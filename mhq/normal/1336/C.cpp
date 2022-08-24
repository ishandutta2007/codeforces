#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 3005;
int dp[maxN][maxN];
int n, m;
string s, t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = m; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int pref = 0; pref <= m; pref++) {
        for (int len = n; len >= 1; len--) {
            if (!dp[pref][len]) continue;
            //take from left
            if (pref < m) {
                if (s[len - 1] == t[pref]) {
                    dp[pref + 1][len - 1] = sum(dp[pref + 1][len - 1], dp[pref][len]);
                }
            }
            else {
                dp[m][len - 1] = sum(dp[m][len - 1], dp[m][len]);
            }
            //take from right
            if (len <= m - pref) {
                if (s[len - 1] == t[pref + len - 1]) {
                    dp[pref][len - 1] = sum(dp[pref][len - 1], dp[pref][len]);
                }
            }
            else {
                dp[pref][len - 1] = sum(dp[pref][len - 1], dp[pref][len]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = sum(ans, dp[i][0]);
    }
    cout << ans;
    return 0;
}