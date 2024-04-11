#include <bits/stdc++.h>
using namespace std;

const int Maxn = 405;
const int Inf = 1000000000;

int T;
int n, m;
char B[Maxn][Maxn];
int sum[Maxn][Maxn];
int dp[Maxn], best[Maxn];
int res;

int getOnes(int row, int l, int r)
{
    return sum[row][r] - sum[row][l - 1];
}

int getZeroes(int row, int l, int r)
{
    return r - l + 1 - getOnes(row, l, r);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", B[i] + 1);
            for (int j = 1; j <= m; j++)
                sum[i][j] = sum[i][j - 1] + (B[i][j] == '1');
        }
        res = Inf;
        for (int l = 1; l <= m; l++)
            for (int r = l + 3; r <= m; r++) {
                best[0] = Inf;
                for (int i = 1; i <= n; i++) {
                    dp[i] = dp[i - 1] + getZeroes(i, l, l) + getOnes(i, l + 1, r - 1) + getZeroes(i, r, r);
                    best[i] = best[i - 1];
                    if (i >= 5) best[i] = min(best[i], getZeroes(i - 4, l + 1, r - 1) - dp[i - 4]);
                    res = min(res, getZeroes(i, l + 1, r - 1) + dp[i - 1] + best[i]);
                }
            }
        printf("%d\n", res);
    }
    return 0;
}