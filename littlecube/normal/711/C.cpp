#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll dp[105][105][105], c[105], p[105][105], n, m, k, r = _INFINITY;

signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> p[i][j];

    for (int l = 0; l <= n; l++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j][l] = 10000000000000;

    for (int i = 1; i <= m; i++)
        if (c[1] == 0)
            dp[1][i][1] = p[1][i];
        else if (c[1] == i)
            dp[1][i][1] = 0;

    for (int l = 1; l <= n; l++)
        for (int i = l; i <= n; i++)
            if (c[i] == 0)
                for (int j = 1; j <= m; j++)
                    for (int q = 1; q <= m; q++)
                    {
                        if (q == j)
                            dp[i][j][l] = min(dp[i][j][l], dp[i - 1][q][l] + p[i][j]);
                        else
                            dp[i][j][l] = min(dp[i][j][l], dp[i - 1][q][l - 1] + p[i][j]);
                    }
            else
                for (int q = 1; q <= m; q++)
                {
                    if (q == c[i])
                        dp[i][c[i]][l] = min(dp[i][c[i]][l], dp[i - 1][q][l]);
                    else
                        dp[i][c[i]][l] = min(dp[i][c[i]][l], dp[i - 1][q][l - 1]);
                }

    for (int i = 1; i <= m; i++)
        r = min(r, dp[n][i][k]);
    if (r >= 10000000000000)
        cout << -1;
    else
        cout << r;
}