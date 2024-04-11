#include <bits/stdc++.h>
using namespace std;

const int N = 255, MOD = 998244353;

long long c[N][N], dp[N][N];

long long pw(int u, int p) {
    if (p == 0) {
        return 1;
    } else {
        long long ans = 1;
        for (int i = __lg(p); i >= 0; i--) {
            (ans *= ans) %= MOD;
            if (p >> i & 1) {
                (ans *= u) %= MOD;
            }
        }
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    dp[0][0] = 1;
    for (int w = 1; w <= k; w++) {
        for (int num = 0; num < n; num++) {
            for (int lst = 0; lst <= num; lst++) {
                long long coef = c[n - 1 - lst][num - lst];
                (coef *= pw(k - w + 1, num * (num - 1) / 2 - lst * (lst - 1) / 2)) %= MOD;
                (dp[w][num] += dp[w - 1][lst] * coef) %= MOD;
            }
        }
    }
    cout << dp[k][n - 1];
}