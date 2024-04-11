#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, s, e, f[301][100001], a[100001], v[100001], next[100001];

int main(){
   // freopen("c.in", "r", stdin);
   // freopen("c.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &v[i]);
    memset(f, 127, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= 300; i++)
    {
        int Right = m;
        for (int j = 1; j <= 100000; j++) next[j] = m + 1;
        if (f[i - 1][i - 1] < 1 << 30)
           for (; Right > f[i - 1][i - 1]; --Right)
               next[v[Right]] = Right;
        for (int j = i; j <= n; j++)
        {
            if (next[a[j]] != m + 1) f[i][j] = next[a[j]];
            if (f[i - 1][j]) 
               if (f[i - 1][j] <= Right)
                  for (; Right > f[i - 1][j]; --Right)
                      next[v[Right]] = Right;
        }
    }
    for (int i = 300; i >= 1; --i)
    {
        for (int j = i; j <= n; j++)
            if (f[i][j] < 1 << 30)
            {
               if (i * e + j + f[i][j] <= s)
               {
                  printf("%d\n", i);
                  return 0;
               }
            }  
    }
    printf("0\n");
}