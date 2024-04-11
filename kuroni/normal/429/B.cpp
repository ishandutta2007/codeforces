#include <iostream>
#include <string.h>
#include <stdio.h>
#include <climits>

using namespace std;

int n, m, i, j, a[1005][1005];
long long ul[1005][1005], bl[1005][1005], ur[1005][1005], br[1005][1005], ans = LLONG_MIN;

int main()
{
    memset(ul, 0, sizeof(ul));
    memset(bl, 0, sizeof(bl));
    memset(ur, 0, sizeof(ur));
    memset(br, 0, sizeof(br));
    scanf("%d%d", &m, &n);
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        scanf("%d", &a[i][j]);
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        ul[i][j] = max(ul[i][j - 1], ul[i - 1][j]) + a[i][j];
    for (i = 1; i <= m; i++)
        for (j = n; j >= 1; j--)
        ur[i][j] = max(ur[i][j + 1], ur[i - 1][j]) + a[i][j];
    for (i = m; i >= 1; i--)
        for (j = n; j >= 1; j--)
        br[i][j] = max(br[i][j + 1], br[i + 1][j]) + a[i][j];
    for (i = m; i >= 1; i--)
        for (j = 1; j <= n; j++)
        bl[i][j] = max(bl[i][j - 1], bl[i + 1][j]) + a[i][j];
    for (i = 2; i < m; i++)
        for (j = 2; j < n; j++)
        {
            if (ans < max(ul[i - 1][j] + ur[i][j + 1] + br[i + 1][j] + bl[i][j - 1], ul[i][j - 1] + ur[i - 1][j] + br[i][j + 1] + bl[i + 1][j]))
                ans = max(ul[i - 1][j] + ur[i][j + 1] + br[i + 1][j] + bl[i][j - 1], ul[i][j - 1] + ur[i - 1][j] + br[i][j + 1] + bl[i + 1][j]);
        }
    printf("%lld", ans);
}