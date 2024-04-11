#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int mod = 1e9 + 7;
 
ll binpow(ll a, ll p) {
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

const int N = 5005;
ll dp[N][N];

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[j][i] = dp[j - 1][i - 1] + dp[j - 1][i + 1];
            if (dp[j][i] >= mod) dp[j][i] -= mod;
        }
    }

    vector<ll> coef(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            (coef[i] += dp[j][i] * dp[k - j][i]) %= mod;
        }
    } 

    ll ans = 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        (ans += a[i] * coef[i]) %= mod;
    }

    while (q--) {
        ll i, x;
        cin >> i >> x;
        (ans += mod - a[i] * coef[i] % mod) %= mod;
        a[i] = x;
        (ans += a[i] * coef[i]) %= mod;
        cout << ans << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}