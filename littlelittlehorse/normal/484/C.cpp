#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

char str[1000011];
int n, m, a[1000011], f[1000011][21], D, K, v[1000011];

int calc(int x, int will){
     int cost = 0;
     for (int i = 0; will; will >>= 1, i++)
          if (will & 1) 
          {
               if (x - cost > 0) 
                    x = f[x - cost][i], x += cost, cost += 1 << i;
          }
     return x;
}

int main(){
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     scanf("%s", str + 1);
     n = strlen(str + 1);
     for (int i = 1; i <= n; i++) a[i] = str[i];
     scanf("%d", &m);
     for (; m--;)
     {
          scanf("%d%d", &D, &K); int cnt = 0;
          for (int i = 0; i < K; i++)
               for (int j = i + 1; j <= D; j += K)
                    f[j][0] = ++cnt;
          for (int i = 1; i <= 20; i++)
               for (int j = 1; j <= D; j++)
                    if (f[j][i - 1] > 1 << (i - 1))
                         f[j][i] = f[f[j][i - 1] - (1 << (i - 1))][i - 1] + (1 << (i - 1));
                    else f[j][i] = f[j][i - 1];
          for (int i = 1; i <= D; i++) 
               v[calc(i, n - D + 1)] = a[i];
          for (int i = D + 1, j = n - D; i <= n; i++, --j) 
               v[calc(D, j) + i - D] = a[i];
          for (int i = 1; i <= n; i++) printf("%c", v[i]), a[i] = v[i];
          printf("\n");
     }
}