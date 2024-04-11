#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 52;
const int INF = (int)1e8;
int dp[maxN][maxN][maxN];
int n, h, m;
int la[maxN], ra[maxN], c[maxN], x[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> h >> m;
    for (int i = 1; i <= m; i++) {
        cin >> la[i] >> ra[i] >> x[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int he = 0; he <= h; he++) {
                dp[i][j][he] = -INF;
            }
        }
    }
    for (int he = 0; he <= h; he++) {
        for (int len = 1; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                for (int where = l; where <= r; where++) {
                    vector < int > sub(he + 2, 0);
                    for (int who = 1; who <= m; who++) {
                        if (la[who] >= l && ra[who] <= r && la[who] <= where && ra[who] >= where) {
                            sub[min(he + 1, x[who] + 1)] -= c[who];
                        }
                    }
                    int best = -INF;
                    int cur = 0;
                    for (int mx = 0; mx <= he; mx++) {
                        cur += sub[mx];
                        best = max(best, mx * mx + dp[l][where - 1][mx] + dp[where + 1][r][mx] + cur);
                    }
                    dp[l][r][he] = max(dp[l][r][he], best);
                }
            }
        }
    }
    cout << dp[1][n][h];
    return 0;
}