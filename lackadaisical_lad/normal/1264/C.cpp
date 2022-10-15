#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 998244353;
 
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> p(n + 1), sum(n + 1), prod(n + 1), inv(n + 1);
    ll div = binpow(100, MOD - 2);
    prod[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] = p[i] * div % MOD;
        sum[i] = (sum[i - 1] + prod[i - 1]) % MOD;
        prod[i] = prod[i - 1] * p[i] % MOD;
        inv[i] = binpow(prod[i], MOD - 2);
    }
    auto get_value = [&](int l, int r) {
        if (l > r) return 0LL;
        ll num = (sum[r] - sum[l - 1] + MOD) % MOD;
        num = num * inv[l - 1] % MOD;
        ll den = inv[r] * prod[l - 1] % MOD;
        return num * den % MOD;
    };

    set<pair<int, int>> segs;
    ll ans = get_value(1, n);
    segs.insert({1, n});
    vector<int> state(n + 1);
    state[1] = 1;
    while (q--) {
        int u;
        cin >> u;
        if (state[u]) {
            auto it = segs.lower_bound({u, 0});
            auto [x, y] = *it;
            ans = (ans - get_value(x, y) + MOD) % MOD;
            segs.erase(it);
            it = segs.lower_bound({u, 0});
            it--;
            auto [l, r] = *it;
            segs.erase(it);
            ans = (ans - get_value(l, r) + MOD) % MOD;
            ans = (ans + get_value(l, y)) % MOD;
            segs.insert({l, y});
        } else {
            auto it = segs.lower_bound({u, 0});
            it--;
            auto [x, y] = *it;
            segs.erase(it);
            ans = (ans - get_value(x, y) + MOD) % MOD;
            ans = (ans + get_value(x, u - 1) + MOD) % MOD;
            ans = (ans + get_value(u, y) + MOD) % MOD;
            segs.insert({x, u - 1});
            segs.insert({u, y});
        }
        state[u] ^= 1;
        cout << ans << '\n';
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