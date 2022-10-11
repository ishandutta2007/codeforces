#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

const ll MOD = 998244353LL;

ll add(ll a, ll b) {
    ll c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0LL));
    for (int i = 0; i <= m; i++)
        dp[i][i] = 1;
    ll ans = 0;
    for (int pref = 0; pref < n; pref++) {
        for (int i = 0; i <= m; i++) {
            int j = min(m, i + pref);
            if (j != m && s[pref] == t[j])
                dp[i][j + 1] = add(dp[i][j + 1], dp[i][j]);
            if (i != 0 && s[pref] == t[i - 1])
                dp[i - 1][j] = add(dp[i - 1][j], dp[i][j]);
        }
        dp[m][m] = add(dp[m][m], dp[m][m]);
        ans = add(ans, dp[0][m]);
    }
    cout << ans << '\n';
}