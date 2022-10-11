#include <bits/stdc++.h>
using namespace std;

const int N = 5005, MOD = 998244353;

int n, k, u, v;
long long dp[N][N], tmp[N];
vector<int> adj[N];

int DFS(int u, int p = 0) {
    int h = 0;
    dp[u][0] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            int ch = DFS(v, u);
            fill(tmp, tmp + max(h, ch + 1) + 1, 0);
            for (int j = 0; j <= ch; j++) {
                for (int i = 0; i <= h; i++) {
                    if (i + j + 1 <= k) {
                        (tmp[max(i, j + 1)] += 1LL * dp[u][i] * dp[v][j]) %= MOD;
                    }
                    if (i <= k) {
                        (tmp[i] += 1LL * dp[u][i] * dp[v][j]) %= MOD;
                    }
                }
            }
            h = max(h, ch + 1);
            for (int i = 0; i <= h; i++) {
                dp[u][i] = tmp[i];
            }
        }
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        (ans += dp[1][i]) %= MOD;
    }
    cout << ans;
}