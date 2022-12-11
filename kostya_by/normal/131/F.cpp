#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int a[555][555], sum[555][555], b[555][555], n, m, kk;
char st[555];

int fsum(int i1, int j1, int i2, int j2)
{
    ++i1; ++j1; --i2; --j2;
    return sum[i2][j2] - sum[i1 - 1][j2] - sum[i2][j1 - 1] + sum[i1 - 1][j1 - 1];
}

int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    cin >> n >> m >> kk;
    gets(st);
    for (int i = 1; i <= n; i++)
    {
        gets(st);
        for (int j = 1; j <= m; j++) if (st[j - 1] == '0') a[i][j] = 0; else a[i][j] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int val = a[i][j] * a[i - 1][j] * a[i + 1][j] * a[i][j - 1] * a[i][j + 1];
            if (val != 0) b[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + b[i][j];
    long long ans = 0;
    for (int i = 3; i <= n; i++)
        for (int j = 3; j <= m; j++)
        {
            bool fl = false;
            long long pp;
            for (int k = 1; k <= i; k++)
            {
                if (k + 1 == i) break;
                if (fsum(k, 1, i, j) < kk) break;
                if (fl == true)
                {
                    while (true)
                    {
                        int val = fsum(k, pp, i, j);
                        if (val >= kk) break;
                        --pp;
                    }
                    ans += pp;
                    //cout << i << " " << j << " " << k << " " << pp << endl;
                    continue;
                }
                pp = 1;
                while (true)
                {
                    if (pp + 2 == j) break;
                    int val = fsum(k, pp + 1, i, j);
                    if (val < kk) break;
                    ++pp;
                }
                fl = true;
                ans += pp;
                //cout << i << " " << j << " " << k << " " << pp << endl;
            }
        }
    cout << ans;
    return 0;
}