#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> h;
    ll mul = 1;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (!h.empty() && h.back() == x) {
            mul = mul * k % MOD;
        } else {
            h.push_back(x);
        }
    }
    while (!h.empty() && h.back() == h[0]) {
        h.pop_back();
        mul = mul * k % MOD;
    }
    if (h.empty()) {
        cout << "0\n";
        return;
    }
    n = h.size();
    ll total = binpow(k, n);
    ll inv = binpow(2, MOD - 2);
    vector<ll> f(n + 1), fr(n + 1);
    f[0] = fr[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }
    auto cnk = [&](int n, int k) {
        return f[n] * fr[k] % MOD * fr[n - k] % MOD;
    };

    ll res = 0;
    for (int i = 0; i * 2 <= n; i++) {
        ll ways = cnk(n, i) * cnk(n - i, i) % MOD;
        ways = ways * binpow(k - 2, n - i * 2) % MOD;
        res = (res + ways) % MOD;
    }
    cout << (total - res + MOD) * inv % MOD * mul % MOD << '\n';
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