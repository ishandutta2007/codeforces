#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Inf = 1000000000;

int T;
int n, k;
int a[Maxn];
int dp[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        for (int i = 0; i <= n; i++)
            fill(dp[i], dp[i] + Maxn, -Inf);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++) if (dp[i][j] >= 0) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (a[i] == i - j));
            }
        int res = -1;
        for (int j = n; j >= 0; j--)
            if (dp[n][j] >= k) res = j;
        printf("%d\n", res);
    }
    return 0;
}