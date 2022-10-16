#include <bits/stdc++.h>

using namespace std;

int n, m;
int deg[200005];
int bad[200005];
long long w[200005];
long long f[200005];
long long path[200005];
int trace[200005];
int dad[200005];
vector <int> adj[200005];

long long dp(int u) {
    if (~f[u]) return f[u];
    f[u] = w[u];
    trace[u] = -1;
    for (int v: adj[u]) {
        if (bad[v] && v != dad[u]) {
            dad[v] = u;
            path[v] = path[u] + w[v];
            long long val = dp(v) + w[u];
            if (f[u] < val) f[u] = val, trace[u] = v;
        }
    }
    return f[u];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    int s;
    cin >> s;

    if (m == n - 1) {
        for (int i = 1; i <= n; ++i) bad[i] = 1;
        memset(f, -1, sizeof f);
        cout << dp(s) << endl;
        return 0;
    }
    queue <int> q;
    for (int i = 1; i <= n; ++i) if (!bad[i] && deg[i] == 1) {
        bad[i] = 1;
        q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (bad[v]) continue;
            --deg[v];
            if (deg[v] == 1) {
                bad[v] = 1;
                q.push(v);
            }
        }
    }
    bad[0] = 1;
    for (int i = 1; i <= n; ++i) if (!bad[i]) {
        w[0] += w[i];
        for (int j = 0; j < adj[i].size(); ++j) {
            int v = adj[i][j];
            if (bad[v]) adj[0].push_back(v), adj[v].push_back(0);
        }
    }
    memset(f, -1, sizeof f);
    memset(dad, -1, sizeof dad);
    if (!bad[s]) cout << dp(0) << endl;
    else {
        long long ans = dp(s);
        int flg = 0, cur = s;
        while (~cur) {
            if (!cur) flg = 1;
            cur = trace[cur];
        }
        if (!flg) ans += path[0];
        cout << ans << endl;
    }
    return 0;
}