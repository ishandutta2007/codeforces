#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2005, MASK[4] = {0, 1, 3, 7};

int n, a[N], forw[N][N][2], bacw[N][N][2], ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (a[j] == 1)
            {
                forw[i][j][0] = forw[i][j - 1][0] + 1;
                forw[i][j][1] = forw[i][j - 1][1];
            }
            else
            {
                forw[i][j][0] = forw[i][j - 1][0];
                forw[i][j][1] = max(forw[i][j - 1][0], forw[i][j - 1][1]) + 1;
            }
    for (int j = n; j >= 1; j--)
        for (int i = j; i >= 1; i--)
            if (a[i] == 1)
            {
                bacw[i][j][0] = bacw[i + 1][j][0] + 1;
                bacw[i][j][1] = bacw[i + 1][j][1];
            }
            else
            {
                bacw[i][j][0] = bacw[i + 1][j][0];
                bacw[i][j][1] = max(bacw[i + 1][j][0], bacw[i + 1][j][1]) + 1;
            }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int k = 0; k < 4; k++)
                ans = max(ans, forw[1][i - 1][MASK[k] >> 2 & 1] + bacw[i][j][MASK[k] >> 1 & 1] + forw[j + 1][n][MASK[k] >> 0 & 1]);
    printf("%d", ans);
}