#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, m;
bool vis[nax];
vector <pair < int, int>> g[nax];
void dfs(int node, int x) {
    vis[node] = true;
    for (auto [to, w] : g[node]) {
        if (vis[to]) continue;
        if ((w | x) != x) continue;
        dfs(to, x);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
    cin >> n >> m;
    for (int i = 1 ; i <= m ; ++ i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int L = 0, R = (1 << 30) - 1, ans = -1;
    while (L <= R) {
        int x = L + R >> 1;
        fill(vis, vis + n + 1, false);
        dfs(1, x);
        int cnt = count(vis + 1, vis + 1 + n, true);
        if (cnt == n) {
            ans = x;
            R = x - 1;
        } else L = x + 1;
    }
    cout << ans << '\n';
    for (int i = 1 ; i <= n ; ++ i) g[i].clear();
        

    }    
}