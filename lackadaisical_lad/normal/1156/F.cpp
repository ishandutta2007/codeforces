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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> inv(n + 1);
    for (int i = 1; i <= n; i++) {
        inv[i] = binpow(i, MOD - 2);
    }

    vector<vector<ll>> dp(n, vector<ll>(n + 1));
    vector<vector<ll>> pref(n + 1, vector<ll>(n));
    sort(a.begin(), a.end());
    ll ans = 0;
    dp[0][1] = inv[n];
    pref[1][0] = inv[n];
    for (int i = 1; i < n; i++) {
        dp[i][1] = inv[n];
        pref[1][i] = (pref[1][i - 1] + dp[i][1]) % MOD;
        for (int j = 2; j <= i + 1; j++) {
            int pos = lower_bound(a.begin(), a.end(), a[i]) - a.begin() - 1;
            if (pos >= 0) dp[i][j] = pref[j - 1][pos] * inv[n - j + 1] % MOD;
            ans += (pref[j - 1][i - 1] - (pos >= 0 ? pref[j - 1][pos] : 0) + MOD) * inv[n - j + 1] * 2;
            ans %= MOD;
            pref[j][i] = (pref[j][i - 1] + dp[i][j]) % MOD;
        }
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