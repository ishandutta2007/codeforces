#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1001][1001];
long long f[1001][1001][4], v[1001][1001][4];

int main(){
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    memset(f, 128, sizeof(f));
    f[1][1][0] = f[1][1][3] = a[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i != 1 || j != 1)
            {
               if (i != 1) f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][3]) + a[i][j];
               if (j != 1) f[i][j][3] = max(f[i][j - 1][0], f[i][j - 1][3]) + a[i][j];
            }
    f[n][m][1] = f[n][m][2] = a[n][m];
    for (int i = n; i; i--)
        for (int j = m; j; j--)
            if (i != n || j != m)
            {
               if (i != n) f[i][j][2] = max(f[i + 1][j][2], f[i + 1][j][1]) + a[i][j];
               if (j != m) f[i][j][1] = max(f[i][j + 1][2], f[i][j + 1][1]) + a[i][j];
            }
    memset(v, 128, sizeof(v));
    v[n][1][2] = v[n][1][3] = a[n][1];
    for (int i = n; i; i--)
        for (int j = 1; j <= m; j++)
            if (i != n || j != 1)
            {
               if (i != n) v[i][j][2] = max(v[i + 1][j][2], v[i + 1][j][3]) + a[i][j];
               if (j != 1) v[i][j][3] = max(v[i][j - 1][2], v[i][j - 1][3]) + a[i][j];
            }
    v[1][m][0] = v[1][m][1] = a[1][m];
    for (int i = 1; i <= n; i++)
        for (int j = m; j; j--)
            if (i != 1 || j != m)
            {
               if (i != 1) v[i][j][0] = max(v[i - 1][j][0], v[i - 1][j][1]) + a[i][j];
               if (j != m) v[i][j][1] = max(v[i][j + 1][0], v[i][j + 1][1]) + a[i][j];
            }
    long long Max = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (f[i][j][0] >= 0 && f[i][j][2] >= 0 && v[i][j][3] >= 0 && v[i][j][1] >= 0)
            Max = max(Max, f[i][j][0] + f[i][j][2] + v[i][j][3] + v[i][j][1] - 4 * a[i][j]);
            if (f[i][j][3] >= 0 && f[i][j][1] >= 0 && v[i][j][2] >= 0 && v[i][j][0] >= 0)
            Max = max(Max, f[i][j][3] + f[i][j][1] + v[i][j][2] + v[i][j][0] - 4 * a[i][j]);
        }
    cout << Max << endl;
}