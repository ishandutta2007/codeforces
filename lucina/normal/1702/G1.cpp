#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int LG = 19;
int n, q;
vector <int> g[nax];
int tin[nax];
int tout[nax];
int timer;
int par[nax][LG];

bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs(int v, int parent) {
    tin[v] = ++timer;
    par[v][0] = parent;
    for (int j = 1 ; j < LG ; ++ j) {
        par[v][j] = par[par[v][j - 1]][j - 1];
    }
    for (int to : g[v]) {
        if (to == parent) continue;
        dfs(to, v);
    }
    tout[v] = ++ timer;
}
int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;

    for (int j = LG - 1 ; j >= 0 ; -- j) {
        if (!ancestor(par[u][j], v)) {
            u = par[u][j];
        }
    }
    return par[u][0];
}

void solve() {
    cin >> n;
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cin >> q;
    while (q --) {
        int k;
        cin >> k;
        vector <int> path(k);
        for (int &x : path) cin >> x;
        int m = path.size() - 1;
        sort(path.begin(), path.end(), [&](int u, int v) -> bool {
                return tin[u] < tin[v];
            });
        int i = 0;
        while (i < m && ancestor(path[i], path[i + 1])) {
            i += 1;
        }
        int j = m;
        while (j > 0 && ancestor(path[j - 1], path[j])) j -= 1;
        if (i == m) {
            cout << "YES\n";
            continue;
        }
        if (i + 1 != j) {
            cout << "NO\n";
            continue;
        }

        if (int l = lca(path[i], path.back()); l == path[0] || (!ancestor(path[0], path[j]) && !ancestor(path[j], path[0]))) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}

int main() {
    tout[0] = 1e9;
    cin.tie(0)->sync_with_stdio(false);
    int T;

    solve();

}