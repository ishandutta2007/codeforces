#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;
int n;
vector <pair <int, int>> g[nax];
int sz[nax];
int f[nax];
int h[nax];
int keep_w[nax];
int link_par[nax];
vector <int> stk[nax];

/*
you can simply consider contribution of each edge
*/

void dfs(int node, int par, int par_num) {
    stk[par_num].push_back(node);
    sz[node] = 1;
    for (auto &[to, w] : g[node]) {
        if (to == par) continue;
        dfs(to, node, w);
        sz[node] += sz[to];
        keep_w[to] = w;
    }
    stk[par_num].pop_back();
    if (!stk[par_num].empty()) {
        int p = stk[par_num].back();
        f[p] -= sz[node];
        link_par[node] = p;
    } else {
        h[par_num] -= sz[node];
    }
    f[node] += sz[node];
}
int64_t ans;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i < n ; ++ i) {
        int u, v, w;
        cin >> u >> v >> w;;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    fill(h, h + 1 + n, n);
    dfs(1, 0, 0);
    for (int i = 2 ; i <= n ; ++ i) {
        int down = f[i];
        int up = link_par[i] ? f[link_par[i]] : h[keep_w[i]];
        ans += 1ll * down * up;
    }
    
    cout << ans << '\n';
}