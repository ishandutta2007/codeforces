#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
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
    vector<int> kek{4,6,8,9,10,12,14,15,16,18,20};
    vector<int> dp(101, -1);
    dp[0] = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j : kek) {
            if (j <= i && dp[i - j] != -1) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            if (dp[i] > -1 && i <= n && (n - i) % 4 == 0) {
                ans = max(ans, dp[i] + (n - i) / 4);
            }
        }
        if (ans == 0) ans = -1;
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