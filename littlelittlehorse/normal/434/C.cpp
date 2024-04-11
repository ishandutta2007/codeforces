#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int P = 1000000007;
int ans, v[201][201][501][2], n, m, request, len1, c1[201], len2, c2[201], a[201][21], cnt, len, c[201], f[201], type[201], fail[201], father[201];

inline void work(int xs){
     memset(v, 0, sizeof(v));
     v[0][0][0][1] = 1;
     for (int i = 1; i <= len1; i++)
     {
          if (i != 1) 
          for (int l = 1; l < m; l++)
          { 
               int p = 0;
               while (!a[p][l] && p) p = fail[p];
               p = a[p][l];
               if (f[p] <= request) 
                    v[i][p][f[p]][0]++,
                    v[i][p][f[p]][0] %= P;
          }
          for (int j = 0; j <= cnt; j++) 
               for (int k = 0; k <= request; k++)
               {
                    if (v[i - 1][j][k][0])
                         for (int l = 0; l < m; l++)
                         {
                              int p = j;
                              while (!a[p][l] && p) p = fail[p];
                              p = a[p][l];
                              //printf("xx %d %d %d %d\n", i, p, k, f[p]);
                              if (k + f[p] <= request) 
                                   v[i][p][k + f[p]][0] += v[i - 1][j][k][0],
                                   v[i][p][k + f[p]][0] %= P;
                         }
                    if (v[i - 1][j][k][1])
                    {
                         int uu = 0; 
                         if (i == 1) uu = 1;
                         for (int l = uu; l <= c1[i]; l++)
                         {
                              int p = j;
                              while (!a[p][l] && p) p = fail[p];
                              p = a[p][l];
                              if (k + f[p] <= request) 
                                   if (l != c1[i])
                                   v[i][p][k + f[p]][0] += v[i - 1][j][k][1],
                                   v[i][p][k + f[p]][0] %= P;
                                   else
                                   v[i][p][k + f[p]][1] += v[i - 1][j][k][1],
                                   v[i][p][k + f[p]][1] %= P;
                         }
                    }
               }
     }
     for (int j = 0; j <= cnt; j++)
          for (int k = 0; k <= request; k++)
               if (xs == 1) 
               {
                    ans += v[len1][j][k][0]; ans %= P;
                    ans += v[len1][j][k][1]; ans %= P;
               }
               else ans -= v[len1][j][k][0], ans += P, ans %= P;
}

inline void makefail(){
     memset(fail, 255, sizeof(fail));
     fail[0] = 0;
     int k = 0;
     for (int i = 0; i < m; ++i) 
          if (a[0][i]) fail[a[0][i]] = 0, c[++k] = a[0][i];
     int M = m;
     for (int l = 1; l <= k; l++)
     {
          int m = c[l];
          if (fail[m] == -1)
          {
               int p = father[m];
               while (p && !a[fail[p]][type[m]]) p = fail[p];
               fail[m] = a[fail[p]][type[m]];
               f[m] += f[fail[m]];
          }
          for (int i = 0; i < M; ++i) 
               if (a[m][i]) c[++k] = a[m][i];
     }
}

int main(){
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     scanf("%d%d%d", &n, &m, &request);
     scanf("%d", &len1);
     for (int i = 1; i <= len1; i++) scanf("%d", &c1[i]);
     scanf("%d", &len2);
     for (int i = 1; i <= len2; i++) scanf("%d", &c2[i]);
     memset(a, 0, sizeof(a)); cnt = 0;
     memset(f, 0, sizeof(f));
     for (int i = 1; i <= n; i++) 
     {
          scanf("%d", &len);
          for (int j = 1; j <= len; j++) scanf("%d", &c[j]);
          int now = 0;
          for (int j = 1; j <= len; j++)
          {
               if (!a[now][c[j]]) a[now][c[j]] = ++cnt, type[cnt] = c[j], father[cnt] = now;
               now = a[now][c[j]];
          }
          int value;
          scanf("%d", &value);
          f[now] += value;
     }
     makefail();
     ans = 0;
     work(-1);
     len1 = len2;
     for (int i = 1; i <= len1; i++) c1[i] = c2[i];
     work(1);
     printf("%d\n", ans);
}