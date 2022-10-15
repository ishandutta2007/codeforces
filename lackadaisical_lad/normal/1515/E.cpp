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

const int N = 500;
ll dp[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> f(n + 1), fr(n + 1);
    f[0] = fr[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % m;
        fr[i] = binpow(f[i], m - 2, m);
    }

    auto cnk = [&](int n, int k) {
        return f[n] * fr[k] % m * fr[n - k] % m;
    };

    vector<ll> coef(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int l = j - 1;
            int r = i - j;
            (coef[i] += cnk(l + r, r)) %= m;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++) {
                (dp[i][j] += (i - k - 1 >= 0 ? dp[i - k - 1][j - k] : 1) * cnk(j, k) % m * coef[k]) %= m;
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        // cout << dp[n][j] << endl;
        (ans += dp[n][j]) %= m;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}