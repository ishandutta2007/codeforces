#include <bits/stdc++.h>
using namespace std;

const int K = 5005, MOD = 1E9 + 7;

int n, k;
long long up[K], dp[K][K];

long long pw(int u, int p) {
    long long ans = 1;
    for (int i = p <= 0 ? -1 : __lg(p); i >= 0; i--) {
        (ans *= ans) %= MOD;
        if (p >> i & 1) {
            (ans *= u) %= MOD;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    up[0] = 1;
    for (int i = 1; i <= k; i++) {
        up[i] = up[i - 1] * (n + 1 - i) % MOD;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % MOD;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        (ans += dp[k][i] * up[i] % MOD * pw(2, n - i)) %= MOD;
    }
    cout << ans;
}