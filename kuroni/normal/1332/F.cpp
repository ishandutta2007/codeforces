#include <bits/stdc++.h>
using namespace std;

const int N = 300005, MOD = 998244353;

int n, u, v;
long long dp[N][3], tmp[3];
vector<int> adj[N];

void DFS(int u, int p = 0) {
    dp[u][2] = 1;
    for (int &v : adj[u]) {
        if (v != p) {
            DFS(v, u);
            tmp[0] = dp[u][0]; tmp[1] = dp[u][1]; tmp[2] = dp[u][2];
            dp[u][0] = dp[u][1] = dp[u][2] = 0;
            // include (u - v)
            (dp[u][0] += (tmp[0] + tmp[2]) * (dp[v][0] + dp[v][1] + 2 * dp[v][2])) %= MOD;
            (dp[u][1] += (tmp[1] + tmp[2]) * (dp[v][0] + dp[v][2])) %= MOD;
            // don't include (u - v)
            (dp[u][0] += tmp[0] * (dp[v][0] + dp[v][1] + dp[v][2])) %= MOD;
            (dp[u][1] += tmp[1] * (dp[v][0] + dp[v][1] + dp[v][2])) %= MOD;
            (dp[u][2] += tmp[2] * (dp[v][0] + dp[v][1] + dp[v][2])) %= MOD;
        }
    }
    // cout << u << ": " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    cout << (dp[1][0] + dp[1][1] + dp[1][2] + MOD - 1) % MOD;
}