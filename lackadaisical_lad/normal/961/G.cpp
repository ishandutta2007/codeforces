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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<ll> f(n + 1), fr(n + 1);
    f[0] = fr[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }
    auto cnk = [&](int n, int k) {
        return f[n] * fr[k] % MOD * fr[n - k] % MOD;
    };
    auto stir = [&](int n, int k) {
        ll res = 0;
        for (int j = 0; j <= k; j++) {
            if ((k - j) % 2 == 0) {
                (res += cnk(k, j) * binpow(j, n)) %= MOD;
            } else {
                (res += MOD - cnk(k, j) * binpow(j, n) % MOD) %= MOD;
            }
        }
        return res * fr[k] % MOD;
    };

    ll coef = (n + k - 1) * stir(n - 1, k) + stir(n - 1, k - 1);
    ll ans = 0;
    coef %= MOD;
    for (int i = 0; i < n; i++) {
        (ans += w[i] * coef) %= MOD;
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