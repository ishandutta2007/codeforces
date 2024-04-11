#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;
const int inf = 1e18;

int n, m;
set<int> adj[N], jda[N];
map<pair<int,int>,int> cnt;
int totcnt[N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int tot[N], dis[N];

void update(int u, int ds, int addcnt) {
    totcnt[u] += addcnt;
    if (dis[u] > tot[u] + ds - totcnt[u]) {
        dis[u] = tot[u] + ds - totcnt[u];
        tot[u] -= totcnt[u];
        totcnt[u] = 0;
        pq.push({dis[u], u});
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        jda[v].insert(u);
        cnt[{u,v}]++;
        tot[u] += 1;
    }

    for (int i=1; i<=n; i++) dis[i] = inf;
    dis[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int u = p.second;
        if (dis[u] != p.first) continue;
        for (int v : jda[u]) {
            update(v, 1 + dis[u], cnt[{v,u}]);
        }
    }

    cout << dis[1] << endl;
}