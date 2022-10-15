#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int lg[1030], a[20][20], f[20][20], vis[20];
int n, m, k;

int dfs(int x, int y)
{
    if (y == m + 1)
        x++, y = 1;
    if (x == n + 1)
        return 1;
    int s = f[x - 1][y] | f[x][y - 1];
    int calc = -1, ret = 0;
    int S = ~s & ((1 << k) - 1);
    if (n + m - x - y + 1 > lg[S])
        return 0;
    for (int tmp = 0; tmp < k; tmp++)
        if (S & (1 << tmp))
            if (a[x][y] == 0 || a[x][y] == tmp + 1)
            {
                vis[tmp + 1]++;
                f[x][y] = s | (1 << tmp);
                if (vis[tmp + 1] == 1)
                {
                    if (calc == -1)
                        calc = dfs(x, y + 1);
                    ret += calc;
                }
                else
                    ret += dfs(x, y + 1);
                if (ret >= mod)
                    ret -= mod;
                vis[tmp + 1]--;
            }
    return ret;
}

int main()
{
    for (int i = 1; i < 1024; i++)
        lg[i] = lg[i >> 1] + (i & 1);
    scanf("%d%d%d", &n, &m, &k);
    if (n + m - 1 > k)
    {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            vis[a[i][j]]++;
        }
    printf("%d\n", dfs(1, 1));
    return 0;
}