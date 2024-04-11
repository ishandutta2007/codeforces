#include <bits/stdc++.h>
using namespace std;

int ki[105], v[105][10005], f[105][10005], ans[105][10005], front[10005], back[10005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", ki + i);
        for (int j = 1; j <= ki[i]; j++)
            scanf("%d", &v[i][j]);
        for (int j = 1; j <= ki[i]; j++)
            front[j] = front[j - 1] + v[i][j];
        for (int j = 1; j <= ki[i]; j++)
            back[j] = back[j - 1] + v[i][ki[i] - j + 1];
        for (int j = 0; j <= ki[i]; j++)
            for (int k = 0; k <= j; k++)
                f[i][j] = max(f[i][j], front[k] + back[j - k]);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= ki[k] && j <= i; j++)
                ans[k][i] = max(ans[k][i], ans[k - 1][i - j] + f[k][j]);
    printf("%d\n", ans[n][m]);
    return 0;
}