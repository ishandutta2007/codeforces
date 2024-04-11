#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> adj[200005];
int dad[200005];
int h[200005];
int deep[200005];
int f[200005];

void dfs(int u) {
    deep[u] = u;
    for (auto v: adj[u]) {
        if (v == dad[u]) continue;
        dad[v] = u;
        h[v] = h[u] + 1;
        dfs(v);
        if (h[deep[u]] < h[deep[v]]) deep[u] = deep[v];
    }
    f[u] = h[deep[u]] - h[u] + 1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    priority_queue<pair<int, int>> q;
    q.push({f[1], 1});

    int cur = 0;
    long long ans = -1ll * n * n;
    for (int i = 1; i <= k; ++i) {
        if (!q.empty()) {
            int u = q.top().second;
            q.pop();
            int v = deep[u];
            cur += f[u];
            while (v != u) {
                int p = dad[v];
                for (auto w: adj[p]) if (w != dad[p] && w != v) q.push({f[w], w});
                v = p;
            }
        }
        int b = min(n / 2, n - cur);
        ans = max(ans, 1ll * (n - i - b) * (i - b));
    }
    cout << ans << endl;
    return 0;
}