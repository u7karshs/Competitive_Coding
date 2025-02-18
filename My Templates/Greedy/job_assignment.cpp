struct Job {
    ll deadline, duration, idx;
    bool operator<(Job o) const {
        return deadline < o.deadline;
    }
};

vector<ll> compute_schedule(vector<Job> jobs){
    sort(jobs.begin(), jobs.end());
    set<pair<ll,ll>> s;
    vector<ll> schedule;
    for(ll i = jobs.size()-1; i >= 0; i--){
        ll t = jobs[i].deadline - (i ? jobs[i-1].deadline : 0);
        s.insert(make_pair(jobs[i].duration, jobs[i].idx));
        while(t && !s.empty()){
            auto it = s.begin();
            if(it->first <= t){
                t -= it->first;
                schedule.push_back(it->second);
            } 
            else {
                s.insert(make_pair(it->first - t, it->second));
                t = 0;
            }
            s.erase(it);
        }
    }
    return schedule;
}

int main()
{
    return 0;
}