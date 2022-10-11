#include <bits/stdc++.h>
using namespace std;

const int M = 1005, N = 1005;

int m, n, t, x, y, q, a[M][N], lb[max(M, N)], rb[max(M, N)];
int le[M][N], ri[M][N], up[M][N], dn[M][N];

void update(int u, int v)
{
    for (int i = u; i <= m; i++)
        up[i][v] = (up[i - 1][v] + 1) * a[i][v];
    for (int i = u; i >= 1; i--)
        dn[i][v] = (dn[i + 1][v] + 1) * a[i][v];
    for (int i = v; i <= n; i++)
        le[u][i] = (le[u][i - 1] + 1) * a[u][i];
    for (int i = v; i >= 1; i--)
        ri[u][i] = (ri[u][i + 1] + 1) * a[u][i];
}

int query(int u, int v)
{
    int ans = 0;

    lb[0] = 0; rb[n + 1] = n + 1;
    // up
    for (int i = 1; i <= n; i++)
    {
        lb[i] = i - 1;
        while (up[u][lb[i]] >= up[u][i] && lb[i] >= 1)
            lb[i] = lb[lb[i]];
    }
    for (int i = n; i >= 1; i--)
    {
        rb[i] = i + 1;
        while (up[u][rb[i]] >= up[u][i] && rb[i] <= n)
            rb[i] = rb[rb[i]];
    }
    for (int i = 1; i <= n; i++)
        if (lb[i] < v && rb[i] > v)
            ans = max(ans, up[u][i] * (rb[i] - lb[i] - 1));
    // down
    for (int i = 1; i <= n; i++)
    {
        lb[i] = i - 1;
        while (dn[u][lb[i]] >= dn[u][i] && lb[i] >= 1)
            lb[i] = lb[lb[i]];
    }
    for (int i = n; i >= 1; i--)
    {
        rb[i] = i + 1;
        while (dn[u][rb[i]] >= dn[u][i] && rb[i] <= n)
            rb[i] = rb[rb[i]];
    }
    for (int i = 1; i <= n; i++)
        if (lb[i] < v && rb[i] > v)
            ans = max(ans, dn[u][i] * (rb[i] - lb[i] - 1));

    lb[0] = 0; rb[m + 1] = m + 1;
    // left
    for (int i = 1; i <= m; i++)
    {
        lb[i] = i - 1;
        while (le[lb[i]][v] >= le[i][v] && lb[i] >= 1)
            lb[i] = lb[lb[i]];
    }
    for (int i = m; i >= 1; i--)
    {
        rb[i] = i + 1;
        while (le[rb[i]][v] >= le[i][v] && rb[i] <= m)
            rb[i] = rb[rb[i]];
    }
    for (int i = 1; i <= m; i++)
        if (lb[i] < u && rb[i] > u)
            ans = max(ans, le[i][v] * (rb[i] - lb[i] - 1));
    // right
    for (int i = 1; i <= m; i++)
    {
        lb[i] = i - 1;
        while (ri[lb[i]][v] >= ri[i][v] && lb[i] >= 1)
            lb[i] = lb[lb[i]];
    }
    for (int i = m; i >= 1; i--)
    {
        rb[i] = i + 1;
        while (ri[rb[i]][v] >= ri[i][v] && rb[i] <= m)
            rb[i] = rb[rb[i]];
    }
    for (int i = 1; i <= m; i++)
        if (lb[i] < u && rb[i] > u)
            ans = max(ans, ri[i][v] * (rb[i] - lb[i] - 1));
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> q;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int v = 1; v <= n; v++)
    {
        for (int i = 1; i <= m; i++)
            up[i][v] = (up[i - 1][v] + 1) * a[i][v];
        for (int i = m; i >= 1; i--)
            dn[i][v] = (dn[i + 1][v] + 1) * a[i][v];
    }
    for (int u = 1; u <= m; u++)
    {
        for (int i = 1; i <= n; i++)
            le[u][i] = (le[u][i - 1] + 1) * a[u][i];
        for (int i = n; i >= 1; i--)
            ri[u][i] = (ri[u][i + 1] + 1) * a[u][i];
    }
    while (q--)
    {
        cin >> t >> x >> y;
        if (t == 1)
        {
            a[x][y] ^= 1;
            update(x, y);
        }
        else
            cout << query(x, y) << '\n';
    }
}