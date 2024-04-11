#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 3005;

int T;
int n;
int a[Maxn];
vector <int> my[Maxn];
int dp[Maxn][Maxn][2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            my[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            my[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            dp[i][i][0] = 0;
            dp[i][i][1] = a[i] != a[i + 1];
        }
        for (int l = 1; l <= n; l++)
            for (int i = 1, j = 1 + l; j <= n; i++, j++) {
                dp[i][j][0] = dp[i + 1][j][0] + (a[i] != a[i + 1]);
                dp[i][j][1] = dp[i + 1][j][1] + (a[i] != a[i + 1]);
                for (int k = 0; k < my[a[i]].size(); k++) {
                    int l = my[a[i]][k];
                    if (l <= i) continue;
                    if (l == j + 1)
                        dp[i][j][1] = min(dp[i][j][1], dp[i + 1][j][1]);
                    if (l > j) break;
                    dp[i][j][0] = min(dp[i][j][0], dp[i + 1][l - 1][1] + dp[l][j][0]);
                    dp[i][j][1] = min(dp[i][j][1], dp[i + 1][l - 1][1] + dp[l][j][1]);
                }
            }
        printf("%d\n", dp[1][n][0]);
    }
    return 0;
}