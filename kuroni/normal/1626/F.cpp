#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, x, y, k, mod; cin >> n >> a >> x >> y>> k >> mod;
    int lcm = 1;
    for (int i = 1; i < k; i++) {
        lcm = 1LL * i * lcm / __gcd(i, lcm);
    }
    long long coe = 0, pw = 1;
    vector<long long> dp(lcm);
    for (int i = k; i >= 1; i--) {
        for (int m = lcm - 1; m >= 0; m--) {
            dp[m] = (dp[m] * (n - 1) + m * pw + dp[m - m % i]) % MOD;
        }
        coe = (coe * n + pw) % MOD;
        pw = pw * n % MOD;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        (ans += coe * (a / lcm * lcm) + dp[a % lcm]) %= MOD;
        a = (1LL * a * x + y) % mod;
    }
    cout << (ans + MOD) % MOD;
}