#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 505;
int a[maxN];
int dp_take[maxN][maxN][maxN];
int dp[maxN][maxN];
const int INF = 1e9;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            dp[i][j] = -INF;
            for (int k = 0; k <= n + 1; k++) {
                dp_take[i][j][k] = -INF;
            }
        }
    }
    dp[0][0] = 0;
    dp_take[1][2][0] = a[2];
    dp_take[1][1][1] = a[1];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int moves = 0; moves <= i; moves++) {
                dp_take[i][j][moves] = max(dp_take[i][j][moves], dp_take[i - 1][j][moves] + a[j]);
            }
        }
        for (int moves = 0; moves <= i; moves++) {
            int mx = -INF;
            for (int j = 1; j <= n; j++) {
                if (j >= (i + 1) && moves + 1 >= (j - i - 1)) {
                    dp_take[i + 1][j][moves + 1 - (j - i - 1)] = max(dp_take[i + 1][j][moves + 1 - (j - i - 1)],
                                                                     mx + a[j]);
                }
                mx = max(mx, dp_take[i][j][moves]);
            }
        }
    }
    for (int p = 1; p <= n; p++) {
        for (int moves = 0; moves <= n; moves++) {
            ans = max(ans, dp_take[n][p][moves]);
        }
    }
    cout << ans << '\n';

    return 0;
}