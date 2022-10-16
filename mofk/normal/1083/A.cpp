#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair <int, long long> > adj[300005];
long long h[300005];
long long up[300005];
long long maxh[300005];
int dad[300005];
long long ans = 0;

void dfs(int u) {
    long long sub = h[u] + h[dad[u]] - up[u];
    //cerr << u << ' ' << h[u] << ' ' << sub << endl;
    vector <long long> g;
    g.push_back(h[u]);
    for (auto dat: adj[u]) {
        int v = dat.first;
        long long w = dat.second;
        if (v == dad[u]) continue;
        dad[v] = u;
        h[v] = h[v] + h[u] - w;
        up[v] = w;
        dfs(v);
        g.push_back(maxh[v]);
    }
    sort(g.begin(), g.end(), greater <long long>());
    maxh[u] = g[0];
    if (g.size() > 1) ans = max(ans, g[0] + g[1] - sub);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i], ans = max(ans, h[i]);
    for (int i = 1; i < n; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}