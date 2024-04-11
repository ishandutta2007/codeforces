#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5005;
int dp[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ans = max(ans, dp[i][j]);
            if (i < n) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
            }
            if (j < m) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
            }
            if (i < n && j < m && s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
            }
        }
    }
    cout << ans;
    return 0;
}