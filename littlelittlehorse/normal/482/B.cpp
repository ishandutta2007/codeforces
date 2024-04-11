#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[100001][3], f[100011][31], v[100001][31];

int main(){
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     scanf("%d%d", &n, &m);
     memset(f, 0, sizeof(f));
     for (int i = 1; i <= m; i++) 
     {
          scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
          for (int j = 0, k = a[i][2]; k; k >>= 1, j++)
               if (k & 1) ++f[a[i][0]][j], --f[a[i][1] + 1][j];
     }
     for (int i = 1; i <= n; i++) 
          for (int j = 0; j <= 30; j++) f[i][j] += f[i - 1][j];
     memset(v, 0, sizeof(v));
     for (int i = 1; i <= n; i++) 
          for (int j = 0; j <= 30; j++) v[i][j] = v[i - 1][j] + (bool)f[i][j];
     bool ok = true;
     for (int i = 1; i <= m && ok; i++)
     {
          int value = 0;
          for (int j = 0; j <= 30; j++)    
               if (v[a[i][1]][j] - v[a[i][0] - 1][j] == a[i][1] - a[i][0] + 1) value |= 1 << j;
          if (value != a[i][2]) ok = false;
     }
     if (!ok) printf("NO\n");
     else
     {
          printf("YES\n");
          for (int i = 1; i <= n; i++)
          {
               int value = 0;
               for (int j = 0; j <= 30; j++)
                    if (v[i][j] - v[i - 1][j]) value |= 1 << j;
               printf("%d", value);
               if (i != n) printf(" ");
          }
          printf("\n");
     }
}