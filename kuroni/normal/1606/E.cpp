#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
    for (int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    vector<vector<long long>> pw(x + 1, vector<long long>(n + 1));
    for (int i = 0; i <= x; i++) {
        pw[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            pw[i][j] = pw[i][j - 1] * i % MOD;
        }
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1));
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            int sc = i - 1;
            if (j <= sc) {
                for (int k = 1; k <= i; k++) {
                    (dp[i][j] += pw[j - 1][i - k] * c[i][k]) %= MOD;
                }
            } else {
                for (int rem = 0; rem <= i - 2; rem++) {
                    (dp[i][j] += c[i][rem] * pw[sc][rem] % MOD * dp[i - rem][j - sc]) %= MOD;
                }
            }
        }
    }
    long long ans = 0;
    for (int j = 1; j <= x; j++) {
        (ans += dp[n][j]) %= MOD;
    }
    cout << ans;
}