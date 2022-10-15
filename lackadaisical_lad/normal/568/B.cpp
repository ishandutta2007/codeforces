#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
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

const int N = 5005;

ll dp[N][N], sum[N];
ll f[N], fr[N];

ll cnk(int n, int k) {
    return f[n] * fr[k] % MOD * fr[n - k] % MOD;
}

void solve() {
    int n;
    cin >> n;

    f[0] = fr[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }
    dp[0][0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (j * dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            (sum[i] += dp[i][j]) %= MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll rem = n - i;
        (ans += cnk(n, i) * sum[rem]) %= MOD;
    }
    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}