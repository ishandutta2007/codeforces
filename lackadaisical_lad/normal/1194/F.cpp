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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> f(n + 1), fr(n + 1);
    f[0] = fr[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }
    auto cnk = [&](int n, int k) {
        if (k > n) return 0LL;
        return f[n] * fr[k] % MOD * fr[n - k] % MOD;
    };

    ll pref = accumulate(a.begin(), a.end(), 0LL);
    int j = n - 1;
    ll ans = 0;
    ll prob = binpow(2, MOD - 2);
    for (int cnt = 0; cnt <= n; cnt++) {
        while (j >= 0 && (pref - a[j]) + cnt + (cnt == 0) > t) {
            pref -= a[j--];
        }
        if (cnt > j + 1 || j == -1) {
            break;
        }
        if (pref + cnt <= t) {
            ll val = cnk(j + 1, cnt) * binpow(prob, j + 1) % MOD;
            (ans += (j + 1) * val) %= MOD;    
            continue;
        }
        if (pref - a[j] + cnt < t) {
            ll val = cnk(j + 1, cnt) * binpow(prob, j + 1) % MOD;
            (ans += j * val) %= MOD;
        } else {
            assert(pref - a[j] + cnt == t);
            ll val = cnk(j, cnt) * binpow(prob, j) % MOD;
            (val += cnk(j, cnt - 1) * binpow(prob, j + 1)) %= MOD;
            (ans += j * val) %= MOD;
        }
    }
    cout << ans << '\n';
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