#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int good[200005];
vector <int> ds, dt;
vector <int> adj[200005];

void bfs(vector <int> &d, int s) {
    queue <int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: adj[u]) if (d[v] == -1) d[v] = d[u] + 1, q.push(v);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) cin >> good[i];
    ds.assign(n + 1, -1);
    dt.assign(n + 1, -1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(ds, 1);
    bfs(dt, n);
    int dd = ds[n];
    sort(good + 1, good + k + 1, [](int x, int y) {
         return ds[x] - dt[x] > ds[y] - dt[y];
    });
    int ans = 0;
    int maxdt = -1e9;
    for (int i = 1; i <= k; ++i) {
        int opt = min(dd, 1 + ds[good[i]] + maxdt);
        ans = max(ans, opt);
        maxdt = max(maxdt, dt[good[i]]);
    }
    cout << ans << endl;
    return 0;
}