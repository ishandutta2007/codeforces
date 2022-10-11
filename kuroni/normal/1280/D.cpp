#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
const int N = 3005, M = 3005;
 
int n, m, u, v, t, a[N], sub[N];
vector<int> adj[N];
pair<int, long long> tmp[M], f[N][M];
 
pair<int, long long> operator+(const pair<int, long long> &a, const pair<int, long long> &b) {
    return {a.fi + b.fi, a.se + b.se};
}
 
void DFS(int u, int p = 0) {
    sub[u] = 0;
    f[u][0] = {0, a[u]};
    for (int &v : adj[u]) {
        if (v != p) {
            DFS(v, u);
            for (int i = 0; i <= sub[u]; i++) {
                tmp[i] = f[u][i];
            }
            for (int i = 0; i <= sub[u] + sub[v]; i++) {
                f[u][i] = {-1, 0};
            }
            for (int i = 0; i <= sub[u]; i++) {
                for (int j = 0; j <= sub[v]; j++) {
                    f[u][i + j] = max(f[u][i + j], tmp[i] + f[v][j]);
                }
            }
            sub[u] += sub[v];
        }
    }
    f[u][++sub[u]] = {-1, 0};
    for (int i = sub[u] - 1; i >= 0; i--) {
        if (u == 1) {
            f[u][i + 1] = f[u][i] + make_pair(f[u][i].se > 0, -f[u][i].se);
        } else {
            f[u][i + 1] = max(f[u][i + 1], f[u][i] + make_pair(f[u][i].se > 0, -f[u][i].se));
        }
    }
    // for (int i = 0; i <= sub[u]; i++) {
    //     cout << "f[" << u << "][" << i << "]: " << f[u][i].fi << " " << f[u][i].se << '\n';
    // }
}
 
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> u;
        a[i] = u - a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    cout << f[1][m].fi << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}