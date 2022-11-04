#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e8;
int n, a[300300], b[300300], dp[300300], bf[300300];
set<pair<int, int>> s;
priority_queue<pair<int, int>> pq;

void f(int u){
    if(u == n) return;

    f(bf[u]);
    cout << u << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    for(int i=n;i>=0;i--){
        while(!pq.empty() && pq.top().first > i) s.erase({dp[pq.top().second], pq.top().second}), pq.pop();

        dp[i] = (s.empty() ? INF : (*s.begin()).first+1), bf[i] = (*s.begin()).second;
        if(i == n) dp[i] = 0;

        int u = i + b[i];
        s.insert({dp[i], i}), pq.push({u-a[u], i});
    }

    if(dp[0] == INF) return cout << "-1\n", 0;

    cout << dp[0] << "\n";
    f(0);
}