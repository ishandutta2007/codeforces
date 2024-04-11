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

ll count(ll n, int mask) {
    vector<int> digit;
    while (n) {
        digit.push_back(n % 10);
        n /= 10;
    }
    reverse(digit.begin(), digit.end());
    int m = digit.size();
    vector<vector<ll>> dp(m + 1, vector<ll>(2));
    vector<vector<ll>> sum(m + 1, vector<ll>(2));
    vector<ll> pw(m + 1);
    pw[m] = 1;
    for (int i = m - 1; i >= 1; i--) {
        pw[i] = pw[i + 1] * 10 % MOD;
    }
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++) {
        if (!(mask & 1)) {
            dp[i][0] = 1;
        }
        for (int d = 0; d < 10; d++) {
            if (!(mask >> d & 1)) continue;
            if (d == digit[i - 1]) {
                dp[i][1] = dp[i - 1][1];
                sum[i][1] = (sum[i - 1][1] + d * dp[i - 1][1] * pw[i]) % MOD;
            }
            if (d < digit[i - 1]) {
                (dp[i][0] += dp[i - 1][1] + dp[i - 1][0]) %= MOD;
                (sum[i][0] += sum[i - 1][1] + sum[i - 1][0] + (dp[i - 1][1] + dp[i - 1][0]) * d % MOD * pw[i]) %= MOD;
            } else {
                (dp[i][0] += dp[i - 1][0]) %= MOD;
                (sum[i][0] += sum[i - 1][0] + dp[i - 1][0] * d % MOD * pw[i]) %= MOD;
            }
        }
    }
    return sum[m][0] + sum[m][1];
}

void solve() {
    ll l, r;
    int k;
    cin >> l >> r >> k;
    int topkek = 1 << 10;
    vector<ll> cnt(topkek);
    for (int mask = 1; mask < topkek; mask++) {
        if (__builtin_popcount(mask) > k) continue; 
        cnt[mask] = (count(r, mask) - count(l - 1, mask) + MOD) % MOD;
    }
    ll ans = 0;
    for (int mask = 1; mask < topkek; mask++) {
        if (__builtin_popcount(mask) > k) continue;
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
            if (__builtin_popcount(mask ^ sub) % 2) {
                (ans += MOD - cnt[sub]) %= MOD;
            } else {
                (ans += cnt[sub]) %= MOD;
            }
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