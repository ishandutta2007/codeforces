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
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i] + dp[i - 1] * 2LL + (i > 2 ? 1 : 0)) % m;
        for (int j = i * 2; j <= n; j += i) {
            dp[j] += dp[i];
            if (dp[j] >= m) dp[j] -= m;
            dp[j] -= dp[i - 1];
            if (dp[j] < 0) dp[j] += m;
        }
    }
    cout << dp[n] << endl;
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