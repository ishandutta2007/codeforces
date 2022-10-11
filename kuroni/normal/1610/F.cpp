#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, xr[N], ans[N], oth[N], deg[N];
bool use[N];
vector<pair<int, int>> adj[3][N];

int DFS(int u, int t, int o) {
    while (!adj[t][u].empty() && use[adj[t][u].back().first]) {
        adj[t][u].pop_back();
    }
    if (adj[t][u].empty()) {
        return u;
    } else {
        auto [i, x] = adj[t][u].back();
        ans[i] = x; oth[i] = o; use[i] = true;
        int v = xr[i] ^ u;
        deg[u]--; deg[v]--;
        return DFS(v, t, o);
    }
}

void solve(int t) {
    for (int i = 1; i <= n; i++) {
        deg[i] = adj[t][i].size();
    }
    for (int u = 1; u <= n; u++) {
        if (deg[u] & 1) {
            m++;
            int v = DFS(u, t, t == 0 ? 0 : m);
            xr[m] = u ^ v;
            adj[0][u].push_back({m, 0});
            adj[0][v].push_back({m, 1});
        }
    }
    for (int u = 1; u <= n; u++) {
        if (deg[u] > 0) {
            DFS(u, t, t == 0 ? 0 : m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        xr[i] = u ^ v;
        adj[w][u].push_back({i, 0});
        adj[w][v].push_back({i, 1});
        deg[u] += w; deg[v] += w;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    solve(1);
    solve(2);
    solve(0);
    for (int i = 1; oth[i] > 0; i++) {
        cout << (ans[i] ^ ans[oth[i]]) + 1;
    }
}