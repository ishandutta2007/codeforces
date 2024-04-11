#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int dp[n];
        vector<int> a[n];
        int rq[n];
        int ct[n];
        int maxi = 1;
        int cs = 0;
        for(int i=0;i<n;i++) {
            int s; cin>>s; rq[i] = s;
            ct[i] = 0;
            dp[i] = 0;
            for(int j=0;j<s;j++) {
                int b; cin>>b; b--;
                a[b].push_back(i);
            }
        }
        priority_queue<pii> pq;
        for(int i=0;i<n;i++) {
            if(rq[i] == 0)
                pq.push({1,i}), dp[i] = 1;
        }
        while(!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            int node = cur.second;
            int val = cur.first;
            if(dp[node] != val)
                continue;
            maxi = max(maxi,val);
            cs++;
            for(auto it: a[node]) {
                ct[it]++;
                if(it > node)
                    dp[it] = max(dp[it],dp[node]);
                else
                    dp[it] = max(dp[it],dp[node]+1);
                if(ct[it] == rq[it])
                    pq.push({dp[it],it});
            }
        }
        if(cs != n)
            cout<<"-1\n";
        else
            cout<<maxi<<endl;
    }
    return 0;
}