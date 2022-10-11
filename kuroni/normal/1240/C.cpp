#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 5E5 + 5;

int q, n, k, u, v, w;
long long f[N][2];
vector<long long> cur[N];
vector<pair<int, int>> adj[N];

void DFS(int u, int p = 0) {
    f[u][0] = f[u][1] = 0;
    long long tmp = 0;
    for (pair<int, int> &v : adj[u]) {
        if (v.fi != p) {
            DFS(v.fi, u);
            tmp += f[v.fi][0];
            cur[u].push_back(max(0LL, f[v.fi][1] + v.se - f[v.fi][0]));
        }
    }
    sort(cur[u].begin(), cur[u].end(), greater<long long>());
    f[u][0] = f[u][1] = tmp;
    for (int i = 0; i < min(k, (int)cur[u].size()); i++) {
        if (i < k - 1) {
            f[u][1] += cur[u][i];
        }
        f[u][0] += cur[u][i];
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cur[i].clear();
        f[i][0] = f[i][1] = 0;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    DFS(1);
    cout << max(f[1][0], f[1][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        solve();
    }
}