#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
vector <pair < int, int>> g[nax];
int n;
int ans[nax];
void dfs(int node, int par, bool odd) {
    for (auto [to, id] : g[node]) {
        if (to == par) continue;
        ans[id] = odd ? 3 : 2;
        dfs(to, node, odd ^ 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        int id = i;
        g[u].emplace_back(v, id);
        g[v].emplace_back(u, id);
    }
    int where = -1;
    for (int i = 1 ; i <= n ; ++ i) {
        if (g[i].size() > 2) {
            cout << "-1\n";
            return;
        } else if (g[i].size() == 1) where = i;
    }
    dfs(where, 0, 0);
    for (int i = 1 ; i < n ; ++ i)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}
/*
    Hm, don't know what to write?
    Well, just have fun I suppose.
*/