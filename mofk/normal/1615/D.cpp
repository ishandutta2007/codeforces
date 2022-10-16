#include <bits/stdc++.h>

using namespace std;

int n, m;
int fr[200005], to[200005], w[200005], a[200005];
vector<int> adj[200005];
vector<pair<int, int>> g[200005];
int up[200005];
int dad[200005], val[200005];
int f[200005];

void dfs(int u) {
    for (auto e: adj[u]) {
        if (e == up[u]) continue;
        int v = fr[e] ^ to[e] ^ u;
        up[v] = e;
        if (a[e] == -1) dad[v] = v, val[v] = 0;
        else dad[v] = dad[u], val[v] = val[u] ^ a[e];
        dfs(v);
    }
}

void gogo(int u) {
    for (auto e: adj[u]) {
        if (e == up[u]) continue;
        int v = fr[e] ^ to[e] ^ u;
        if (a[e] == -1) {
            if (f[v] == -1) f[v] = 0;
            val[v] = f[v];
            w[e] = val[v] ^ val[u];
        }
        else val[v] = val[u] ^ a[e];
        gogo(v);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) adj[i].clear(), g[i].clear(), up[i] = dad[i] = val[i] = 0, f[i] = -1;
        for (int i = 1; i < n; ++i) {
            cin >> fr[i] >> to[i] >> w[i];
            adj[fr[i]].push_back(i);
            adj[to[i]].push_back(i);
            if (w[i] != -1) a[i] = __builtin_popcount(w[i]) % 2;
            else a[i] = -1;
        }
        dad[1] = 1;
        dfs(1);
        int bad = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v, x;
            cin >> u >> v >> x;
            x = x ^ val[u] ^ val[v];
            u = dad[u], v = dad[v];
            if (u == v) {
                if (x) bad = 1;
            }
            else {
                g[u].push_back({v, x});
                g[v].push_back({u, x});
            }
        }

        for (int i = 1; i <= n; ++i) if (f[i] == -1 && g[i].size()) {
            queue<int> q;
            f[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto e: g[u]) {
                    int v = e.first, fv = f[u] ^ e.second;
                    if (f[v] == -1) {
                        f[v] = fv;
                        q.push(v);
                    }
                    else if (f[v] != fv) bad = 1;
                }
            }
        }

        if (bad) cout << "NO\n";
        else {
            cout << "YES\n";
            gogo(1);
            for (int i = 1; i < n; ++i) cout << fr[i] << ' ' << to[i] << ' ' << w[i] << '\n';
        }
    }
    return 0;
}