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
    // mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    vector<ll> f(3 * n + 4), fr(3 * n + 4);
    f[0] = 1;
    for (int i = 1; i < f.size(); i++) {
        f[i] = f[i - 1] * i % MOD;
    }
    fr[3 * n + 3] = binpow(f[3 * n + 3], MOD - 2);
    for (int i = 3 * n + 2; i >= 0; i--) {
        fr[i] = fr[i + 1] * (i + 1) % MOD;
    }

    auto cnk = [&](int n, int k) {
        return f[n] * fr[k] % MOD * fr[n - k] % MOD;
    };

    vector<ll> a(3 * n + 4);
    for (int i = 1; i <= 3 * n + 3; i++) {
        a[i] = cnk(3 * n + 3, i);
    }
    vector<ll> b;
    for (int i = 3 * n + 3; i >= 3; i--) {
        b.push_back(a[i]);
        a[i] = a[i] * 3 % MOD;
        a[i - 1] = (a[i - 1] - a[i] + MOD) % MOD;
        a[i - 2] = (a[i - 2] - a[i] + MOD) % MOD;
    }

    reverse(b.begin(), b.end());
    while (q--) {
        int x;
        cin >> x;
        cout << b[x] << '\n';
    }
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