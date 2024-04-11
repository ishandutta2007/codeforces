#include <bits/stdc++.h>
using namespace std;

map<long long, long long> dp[450];

long long n, m, k, a[25][25];

void dfs1(int x, int y, long long now)
{
    if ((x + y) == (n + m) / 2 + 1)
    {
        dp[21 * x + y][now ^ a[x][y]]++;
    }
    else
    {
        if (x < n)
            dfs1(x + 1, y, now ^ a[x][y]);
        if (y < m)
            dfs1(x, y + 1, now ^ a[x][y]);
    }
    return;
}

long long sum = 0;
void dfs2(int x, int y, long long now)
{
    if ((x + y) == (n + m) / 2 + 1)
        sum += dp[21 * x + y][k ^ now];
    else
    {
        if (x > 1)
            dfs2(x - 1, y, now ^ a[x][y]);
        if (y > 1)
            dfs2(x, y - 1, now ^ a[x][y]);
    }
    return;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);
    dfs1(1, 1, 0);
    dfs2(n, m, 0);
    printf("%lld\n", sum);
    return 0;
}