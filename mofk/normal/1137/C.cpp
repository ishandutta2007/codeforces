#include <bits/stdc++.h>

using namespace std;

int n, m, d;
vector <int> adj[100005];
pair <int, int> _stack[5000005]; int sz;
int low[100005][52], num[100005][52], _time;
int scc[100005][52], nscc;
char c[100005][52];
int seen[100005], muse[5000005];

inline void dfs(int u, int t) {
    low[u][t] = num[u][t] = ++_time;
    _stack[sz++] = make_pair(u, t);
    int nt = (t + 1) % d;
    for (auto v: adj[u]) {
        if (scc[v][nt]) continue;
        else if (num[v][nt]) low[u][t] = min(low[u][t], num[v][nt]);
        else {
            dfs(v, nt);
            low[u][t] = min(low[u][t], low[v][nt]);
        }
    }
    if (low[u][t] == num[u][t]) {
        ++nscc;
        int v, nt;
        do {
            --sz;
            v = _stack[sz].first;
            nt = _stack[sz].second;
            scc[v][nt] = nscc;
            if (c[v][nt] == '1' && seen[v] != nscc) seen[v] = nscc, ++muse[nscc];
        } while (v != u || nt != t);
    }
}

vector <int> G[5000005];
int f[5000005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) cin >> c[i];
    dfs(1, 0);
    for (int u = 1; u <= n; ++u) for (int t = 0; t < d; ++t) for (auto v: adj[u]) {
        int nt = (t + 1) % d;
        if (scc[u][t] != scc[v][nt]) G[scc[u][t]].push_back(scc[v][nt]);
    }
    for (int i = 1; i <= nscc; ++i) {
        for (auto j: G[i]) f[i] = max(f[i], f[j]);
        f[i] += muse[i];
    }
    cout << f[nscc] << endl;
    return 0;
}