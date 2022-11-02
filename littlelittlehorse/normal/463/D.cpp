#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int a[6][1001], n, m, c[100011], dist[1011];
bool b[1001];

bool check(int x, int y){
     for (int i = 1; i <= m; i++)
          if (a[i][x] >= a[i][y]) return false;
     return true;
}

int main(){
     //freopen("d.in", "r", stdin);
     //freopen("d.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= m; i++)
     {
          for (int j = 1; j <= n; j++)
          {
               int x;
               scanf("%d", &x);
               a[i][x] = j;
          }
          a[i][0] = 0;
     }
     memset(dist, 0, sizeof(dist));
     memset(b, false, sizeof(b));
     c[1] = 0; dist[0] = 1; int ans = 0;
     for (int k = 1, l = 1; l <= k; l++)
     {
          int m = c[l]; ans = max(ans, dist[m]); b[m] = false;
          for (int i = 1; i <= n; i++)
               if (dist[m] + 1 > dist[i] && check(m, i)) 
               {
                    dist[i] = dist[m] + 1;
                    if (!b[i])
                    {
                         b[i] = true;
                         c[++k] = i;
                    }
               }
     }
     printf("%d\n", ans - 1);
}