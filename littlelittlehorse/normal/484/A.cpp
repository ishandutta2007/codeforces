#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[64], c[64], v[64];
long long l, r, f[64][2][2], g[64][2][2];

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%d", &test);
     for (;test--;)
     {
          cin >> l >> r;
          memset(c, 0, sizeof(c));
          if (!l) c[0] = 1;
          else 
          {
               for (; l; l /= 2) c[++c[0]] = l % 2;
               //for (int i = 1, j = c[0]; i < j; i++, j--) swap(c[i], c[j]);
          }
          memset(v, 0, sizeof(v));
          if (!r) v[0] = 1;
          else 
          {
               for (; r; r /= 2) v[++v[0]] = r % 2;
               //for (int i = 1, j = v[0]; i < j; i++, j--) swap(v[i], v[j]);
          }
          memset(f, 255, sizeof(f)); int len = max(c[0], v[0]);
          f[len][0][0] = 0; g[len][0][0] = 0;
          for (int i = len; i; --i)
                    for (int k = 0; k <= 1; k++)
                         for (int l = 0; l <= 1; l++)
                              if (f[i][k][l] != -1)
                                   for (int x = 0; x <= 1; x++)
                                   {
                                        bool ok = true;
                                        int s1, s2;
                                        if (k) s1 = 1;
                                        else if (c[i] == 1)
                                                  if (x == 0) ok = false;
                                                  else s1 = 0;
                                             else if (x == 0) s1 = 0;
                                                  else s1 = 1;
                                        if (l) s2 = 1;
                                        else if (v[i] == 1)
                                                  if (x == 0) s2 = 1;
                                                  else s2 = 0;
                                             else if (x == 0) s2 = 0;
                                                  else ok = false;
                                        if (ok) 
                                             if (f[i][k][l] + (x == 1) > f[i - 1][s1][s2]
                                             || (f[i][k][l] + (x == 1) ==f[i - 1][s1][s2]
                                             && g[i][k][l] * 2 + x < g[i - 1][s1][s2]))
                                             {
                                                  f[i - 1][s1][s2] = f[i][k][l] + (x == 1);
                                                  g[i - 1][s1][s2] = g[i][k][l] * 2 + x;
                                             }
                                   }
          long long ans1 = -1, ans2 = 0;
          for (int i = 0; i < 2; i++)
               for (int j = 0; j < 2; j++)
                    if (f[0][i][j] > ans1 || (f[0][i][j] == ans1 && g[0][i][j] < ans2))
                         ans1 = f[0][i][j], ans2 = g[0][i][j];
          cout << ans2 << endl;
     }
}