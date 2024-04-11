//nnipip.
//2 1
#include <bits/stdc++.h>
using namespace std;
int n, a[11], used[11], b[13], ans[100001][5], tot, len[5], l;

void dfs(int x)
{
    int i, j, k, r;
    if (l / 2 + 1 + l % 2 == x)
    {
        for (i = 1; i <= n; i ++)
            if (used[i] == 0) break;
        if (i <= n) return;
        tot ++;
        k = 1;
        for (i = 1; i <= 4;  i++)
        {
            ans[tot][i] = 0;
            for (j = 0; j < len[i]; j ++)
                ans[tot][i] = ans[tot][i] * 10 + b[k + j];
            k = k + len[i];
        }
        return;
    }
    for (r = 1; r <= n; r ++)
    {
        b[x] = a[r];
        b[l - x + 1] = a[r];
        used[r] ++;
        k = 1;
        for (i = 1; i <= 4; i ++)
        {
            if ((k <= x || k >= l - x + 1) && len[i] > 1 && b[k] == 0) break;
            int rr = 0;
            for (int j = 0; j < len[i]; j ++)
                rr = rr * 10 + b[k + j];
            if (rr >= 256) break;
            k = k + len[i];
        }
        if (i == 5 && k == l + 1) dfs(x + 1);
        b[x] = 0;
        b[l - x + 1] = 0;
        used[r] --;
    }
}

void dfslen(int x)
{
    if (x == 5)
    {
        l = len[1] + len[2] + len[3] + len[4];
        memset(b, 0, sizeof(b));
        memset(used, 0, sizeof(used));
        dfs(1);
        return;
    }
    len[x] = 1;
    dfslen(x + 1);
    len[x] = 2;
    dfslen(x + 1);
    len[x] = 3;
    dfslen(x + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d",&a[i]);
    tot = 0;
    dfslen(1);
    printf("%d\n",tot);
    for (int i = 1; i <= tot; i ++)
        printf("%d.%d.%d.%d\n", ans[i][1], ans[i][2] ,ans[i][3], ans[i][4]);
    return 0;
}