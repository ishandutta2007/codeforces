#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1501][1501], v[1501][1501];
long long f[1501][1501];
bool b[20003];
 
int main() {
     //freopen("46e.in", "r", stdin);
     //freopen("46e.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) {
          v[i][0] = 0;
          for (int j = 1; j <= m; j++)
               scanf("%d", &a[i][j]), v[i][j] = v[i][j - 1] + a[i][j];
     }
     memset(f, 128, sizeof(f));
     f[0][1] = 0;
     for (int i = 1; i <= n; i++) 
          if (i & 1) {
               long long Max = f[i - 1][1];
               for (int j = 2; j <= m; j++) {
                    f[i][j] = Max + v[i][j];
                    //printf("%d %d %I64d\n", i, j, f[i][j]);
                    Max = max(Max, f[i - 1][j]);
               }
          }
          else {
               long long Max = f[i - 1][m];
               for (int j = m - 1; j; --j) {
                    f[i][j] = Max + v[i][j];
                    Max = max(Max, f[i - 1][j]);
                    //printf("%d %d %I64d\n", i, j, f[i][j]);
               }
          }
     long long ans = -1LL << 60LL;
     for (int i = 1; i <= m; i++) ans = max(ans, f[n][i]);
     printf("%I64d\n", ans);
}