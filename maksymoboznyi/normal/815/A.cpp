#include <bits/stdc++.h>
#define pb push_back();
#define ll long long
using namespace std;
int n, m,g1[105][105], g[105][105], kans, ans = 1000000000;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
          {
              cin >> g[i][j];
                g1[i][j] = g[i][j];
          }
    for (int k = 0; k <= 500; k++)
    {
        bool f = true;
        int kol = k;
        for (int j = 1; j <= m; j++)
            g[1][j] -= k;
        for (int j = 1; j <= m; j++)
        {
            int p = g[1][j];
            if (p <= -1)
                f = false;
            kol += p;
            for (int i = 1; i <= n; i++)
                g[i][j] -= p;
        }
        for (int i = 2; i <= n; i++)
        {
            kol += g[i][1];
            int p = g[i][1];

            if (p <= -1)
                f = false;
            for (int j = 1; j <= m; j++)
                g[i][j] -= p;
        }
        bool r = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (g[i][j] != 0)
                {
                    r = true;
                    break;
                }
        if (!r && kol < ans && f)
        {
            kans = k;
            ans = kol;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                g[i][j] = g1[i][j];
    }
    if (ans == 1000000000)
    {
        cout << -1;
        return 0;
    }
    int k = kans;
    for (int j = 1; j <= m; j++)
        g[1][j] -= k;
    cout << ans << endl;
    for (int i = 1; i <= k; i++)
        cout << "row 1" << endl;
    for (int j = 1; j <= m; j++)
    {
        int p = g[1][j];
       // kol += p;
        for (int i = 1; i <= p; i++)
            cout << "col " << j << endl;
        for (int i = 1; i <= n; i++)
            g[i][j] -= p;
    }
    for (int i = 2; i <= n; i++)
    {
//        kol += g[i][1];
        int p = g[i][1];
        for (int o = 1; o <= p; o++)
            cout << "row " << i << endl;
        for (int j = 1; j <= m; j++)
            g[i][j] -= p;
    }
    return 0;
}