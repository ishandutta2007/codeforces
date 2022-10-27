#include <iostream>
#include <vector>
#include <queue>
#include <set>
 
#define int long long
#define READY 1
#define SERVED 2
 
using namespace std;
 
struct comp{
    bool operator() (const vector<int>& lhs, const vector<int>& rhs) const {
        return lhs[0] > rhs[0] || (lhs[0] == rhs[0] && lhs[2] > rhs[2]) || (lhs[0] == rhs[0] && lhs[2] == rhs[2] && lhs[1] > rhs[1]);
    }
};
 
vector<int> t;
vector<int> ans;
priority_queue< vector<int>, vector<vector<int> >, comp > events;
queue<int> q;
set<int> inq;
priority_queue<int, vector<int>, greater<int> > ready;
 
bool clear(int index){
    auto it = inq.lower_bound(index);
    if(it == inq.end()) 
        return inq.empty();
    return it == inq.begin();
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    int n, p; cin >> n >> p;
    t.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; i++)
        cin >> t[i];
 
    // READY -> put in ready or in queue
    // SERVED -> out of queue, next ready
 
    for(int i = 0; i < n; i++)
        events.push({ t[i], i, READY});
 
    while(!events.empty()){
        vector<int> a = events.top();
        events.pop();
        int status = a[2], index = a[1], time = a[0];
        //cout << time << " " << index << " " << status << endl;
        if(status == READY){
            if(clear(index)){
                if(q.empty())
                    events.push({ time + p, index, SERVED });
                q.push(index);
                inq.insert(index);
            }
            else ready.push(index);
        }
        else{
            ans[index] = time;
            q.pop();
            inq.erase(index);
            // insert first ready if anything has changed
            if(!ready.empty() && clear(ready.top())){
                int nextIndex = ready.top();
                ready.pop();
                q.push(nextIndex);
                inq.insert(nextIndex);
            }
            // if q is not empty, schedule serving the next passenger after p time.
            if(!q.empty()){
                int nextIndex = q.front();
                events.push({time + p, nextIndex, SERVED });
            }
        }
    }
 
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
}