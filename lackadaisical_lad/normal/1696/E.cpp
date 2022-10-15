#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

void solve() {
    const int MOD = 1e9 + 7;
    const int N = 5e5;
    auto binpow = [&](ll a, ll p) {
        ll res = 1;
        while (p) {
            if (p & 1)
                (res *= a) %= MOD;
            p >>= 1;
            (a *= a) %= MOD;
        }
        return res;
    };
    vector<ll> f(N), fr(N);
    f[0] = fr[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD;
        fr[i] = binpow(f[i], MOD - 2);
    }
    auto cnk = [&](int n, int k) {
        if (n < k)
            return 0LL;
        return f[n] * fr[k] % MOD * fr[n - k] % MOD;
    };
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        (ans += cnk(a[i] + i, i + 1)) %= MOD;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}