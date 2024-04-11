#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
double f[2][1001];

int main(){
     //freopen("d.in", "r", stdin);     
     //freopen("d.out", "w", stdout);
     scanf("%d%d", &n, &m);
     memset(f, 0, sizeof(f));
     for (int i = 1; i <= n; i++)
     {
          int status = i & 1, other = 1 - status;
          memset(f[status], 0, sizeof(f[status]));
          for (int j = 1; j <= 1000; j++)
          {
               f[status][j] += (m - 1.0) / m * f[other][j] + 1.0 / m * (1.0 * j / (j + 1) * f[other][j] + j / 2.0);
               if (j != 1000) f[status][j] += 1.0 / m * (1.0 / (j + 1) * j + 1.0 / (j + 1) * f[other][j + 1]);
          }
     }
     double ans = 0;
     for (int i = 1; i <= 1; i++) ans += f[n & 1][i];
     ans *= m;
     printf("%.10f\n", ans);
}