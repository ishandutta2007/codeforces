#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        h[i] = rng();
    }
    vector<ll> val(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        val[b] ^= h[a];
    }

    ll ans = 0;
    map<ll, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        if (val[i] == 0) continue;
        mp[val[i]].push_back(i);
    }
    for (auto& [_, vec] : mp) {
        ll s = 0;
        for (int id : vec) {
            s += c[id];
        }
        ans = gcd(ans, s);
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}