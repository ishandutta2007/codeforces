#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int N = 1100;
const int K = 1100;
ll dp[N][K];
ll f[N], fr[N];

void precalc() {
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][1] = 1;
        for (int j = 2; j < min(K, i); j++) {
            (dp[i][j] = dp[i - j][j] + dp[i - j][j - 1]) %= MOD;
        }
    }

    f[0] = fr[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }
}

ll cnk(int n, int k) {
    if (n < k) return 0LL;
    return f[n] * fr[k] % MOD * fr[n - k] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    n++;
    ll ans = 0;
    for (int i = k + 1; i <= n; i++) {
        ll cnt = cnk(i - 1, k) * f[k] % MOD;
        (ans += cnt * dp[n - i + k][k]) %= MOD;
    }
    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    precalc();
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}