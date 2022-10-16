#include <bits/stdc++.h>

using namespace std;

int n, m, k;
pair <int, int> edge[200005];
int deg[200005];
set <int> adj[200005];
int in[200005];
queue <int> q;
int ans[200005];

void go(int id) {
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
            adj[v].erase(u);
            --deg[v];
            if (!in[v] && deg[v] < k) in[v] = 1, q.push(v);
        }
        adj[u].clear();
        --ans[id];
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[i] = make_pair(u, v);
        ++deg[u], ++deg[v];
        adj[u].insert(v), adj[v].insert(u);
    }
    for (int i = 1; i <= n; ++i) if (deg[i] < k)
        in[i] = 1, q.push(i);
    ans[m] = n;
    go(m);
    for (int i = m; i >= 2; --i) {
        ans[i-1] = ans[i];
        int u = edge[i].first, v = edge[i].second;
        if (in[u] || in[v]) continue;
        adj[u].erase(v);
        adj[v].erase(u);
        --deg[u], --deg[v];
        if (deg[u] < k) in[u] = 1, q.push(u);
        if (deg[v] < k) in[v] = 1, q.push(v);
        go(i - 1);
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';
    return 0;
}