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
    ll n, l, r;
    cin >> n >> l >> r;
    using State = array<ll, 3>;
    const State INIT = State{0, 0, 0};
    State cnt;
    cnt[0] = r / 3 - (l - 1) / 3;
    cnt[1] = (r + 2) / 3 - (l + 1) / 3;
    cnt[2] = (r + 1) / 3 - l / 3;
    State dp = INIT, ndp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        ndp = INIT;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                (ndp[(j + k) % 3] += dp[j] * cnt[k]) %= MOD;
            }
        }
        dp = ndp;
    }
    cout << dp[0] << '\n';
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