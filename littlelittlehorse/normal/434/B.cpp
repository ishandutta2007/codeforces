#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, Q, a[1001][1001], f[1001][4001], c[1001][3], ans[1001], v[1001][1001], U[1001][1001], D[1001][1001], R[1001][1001], L[1001][1001];
char str[11];
                         
int main(){
   //  freopen("b.in", "r", stdin);
   //  freopen("b.out", "w", stdout);
     scanf("%d%d%d", &n, &m, &Q);
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
     for (int i = 1; i <= n; i++)
     {
          L[i][1] = a[i][1];
          for (int j = 2; j <= m; j++)
               if (a[i][j]) L[i][j] = L[i][j - 1] + 1;
               else L[i][j] = 0;
          R[i][m] = a[i][m];
          for (int j = m - 1; j >= 1; j--)
               if (a[i][j]) R[i][j] = R[i][j + 1] + 1;
               else R[i][j] = 0;
     }
     for (int j = 1; j <= m; j++)
     {
          U[1][j] = a[1][j];
          for (int i = 2; i <= n; i++)
               if (a[i][j]) U[i][j] = U[i - 1][j] + 1;
               else U[i][j] = 0;
          D[n][j] = a[n][j];
          for (int i = n - 1; i >= 1; i--)
               if (a[i][j]) D[i][j] = D[i + 1][j] + 1;
               else D[i][j] = 0;
     }
     for (;Q--;)
     {
          int type, x, y;
          scanf("%d%d%d", &type, &x, &y);
          if (type == 1)
          {
               a[x][y] ^= 1; 
               D[x][y] = a[x][y];
               for (int i = x - 1; i >= 1; --i)
                    if (a[i][y]) D[i][y] = D[i + 1][y] + 1;
                    else D[i][y] = 0; 
               U[x][y] = a[x][y];
               for (int i = x + 1; i <= n; ++i)
                    if (a[i][y]) U[i][y] = U[i - 1][y] + 1;
                    else U[i][y] = 0;
               L[x][y] = a[x][y];
               for (int i = y + 1; i <= m; ++i)
                    if (a[x][i]) L[x][i] = L[x][i - 1] + 1;
                    else L[x][i] = 0;
               R[x][y] = a[x][y];
               for (int i = y - 1; i >= 1; --i)
                    if (a[x][i]) R[x][i] = R[x][i + 1] + 1;
                    else R[x][i] = 0;
          }
          else
          {
               int ans = 0;
               int LL = x - 1, RR = x + 1, F = R[x][y];
               ans = max(ans, F);
               for (int i =  F; i >= 1; --i)
               {
                    for (;LL >= 1 && R[LL][y] >= i;) --LL;
                    for (;RR <= n && R[RR][y] >= i;) ++RR;
                    ans = max(ans, (RR - LL - 1) * i);
             //       printf("%d %d %d\n", i, LL, RR);
               }
               LL = x - 1, RR = x + 1, F = L[x][y];
               ans = max(ans, F);
               for (int i =  F; i >= 1; --i)
               {
                    for (;LL >= 1 && L[LL][y] >= i;) --LL;
                    for (;RR <= n && L[RR][y] >= i;) ++RR;
                    ans = max(ans, (RR - LL - 1) * i);
               }
               LL = y - 1, RR = y + 1, F = U[x][y];
               ans = max(ans, F);
               for (int i =  F; i >= 1; --i)
               {
                    for (;LL >= 1 && U[x][LL] >= i;) --LL;
                    for (;RR <= m && U[x][RR] >= i;) ++RR;
                    ans = max(ans, (RR - LL - 1) * i);
               }
               LL = y - 1, RR = y + 1, F = D[x][y];
               ans = max(ans, F);
               for (int i =  F; i >= 1; --i)
               {
                    for (;LL >= 1 && D[x][LL] >= i;) --LL;
                    for (;RR <= m && D[x][RR] >= i;) ++RR;
                    ans = max(ans, (RR - LL - 1) * i);
               }
               printf("%d\n", ans);
          }
     }               
}