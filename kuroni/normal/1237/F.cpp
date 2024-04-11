#include <bits/stdc++.h>
using namespace std;

const int M = 3605, N = 3605, MOD = 998244353;

int m, n, q, u, v, x, y;
bool row[M], col[N];
long long inv[M], fct[M], ifc[M];
long long ans = 0, dp[M][M], cr[M][M], cc[N][N];

void init() {
    inv[1] = 1;
    for (int i = 2; i < M; i++) {
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }
    fct[0] = ifc[0] = 1;
    for (int i = 1; i < M; i++) {
        fct[i] = fct[i - 1] * i % MOD;
        ifc[i] = ifc[i - 1] * inv[i] % MOD;
    }
}

long long C(int n, int k) {
    return fct[n] * ifc[n - k] % MOD * ifc[k] % MOD;
}

void find_ans(int n, bool chk[N], long long ans[N][N]) {
    int cnt = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cnt += (!chk[i]);
        for (int j = 0; j <= i / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0 && !chk[i - 1] && !chk[i]) {
                (dp[i][j] += dp[i - 2][j - 1]) %= MOD;
            }
        }
    }
    for (int i = 0; i <= cnt / 2; i++) {
        for (int j = 0; j <= cnt - 2 * i; j++) {
            ans[i][j] = dp[n][i] * C(cnt - 2 * i, j) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> m >> n >> q;
    while (q--) {
        cin >> u >> x >> v >> y;
        row[u] = row[v] = true;
        col[x] = col[y] = true;
    }
    find_ans(m, row, cr);
    find_ans(n, col, cc);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            (ans += cr[i][j] * cc[j][i] % MOD * fct[i] % MOD * fct[j]) %= MOD;
        }
    }
    cout << ans;
}