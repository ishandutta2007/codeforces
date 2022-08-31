#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3005;
vector<int> where[maxN];
int a[maxN];
int dp[maxN][maxN];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        where[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        where[a[i]].emplace_back(i);
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = len - 1;
            if (len == 1) continue;
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            int pt1 = lower_bound(where[a[i]].begin(), where[a[i]].end(), i) - where[a[i]].begin();
            int pt2 = upper_bound(where[a[i]].begin(), where[a[i]].end(), j) - where[a[i]].begin() - 1;
            for (int t = pt1 + 1; t <= pt2; t++) {
                if (i + 1 <= where[a[i]][t] - 1) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][where[a[i]][t] - 1] + 1 + dp[where[a[i]][t]][j]);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[where[a[i]][t]][j]);
                }
            }

        }
    }
    cout << dp[1][n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}