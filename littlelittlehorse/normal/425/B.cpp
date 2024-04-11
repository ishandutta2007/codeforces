#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[101][101], limit, ans, v[101];

int main(){
    //freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &limit);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    if (n > limit)
    {
       ans = limit + 1;
       for (int i = 1; i <= n; i++)
       {
           int use = 0;
           for (int j = 1; j <= n; j++)
               if (j != i)
               {
                  int will1 = 0, will2 = 0;
                  for (int k = 1; k <= m; k++)
                      if (a[j][k] == a[i][k]) ++will1;
                      else ++will2;
                  use += min(will1, will2);
               }
           ans = min(ans, use);
       }
       if (ans > limit) printf("-1\n");
       else printf("%d\n", ans);
    }
    else
    {
        ans = limit + 1;
        for (int i = 0; i < 1 << n; i++)
        {
            for (int j = 1; j <= n; j++) 
                if (i & (1 << (j - 1))) v[j] = 1;
                else v[j] = 0;
            int use = 0;
            for (int j = 1; j <= m; j++)
                {
                   int will1 = 0, will2 = 0;
                   for (int k = 1; k <= n; k++)
                       if (a[k][j] == v[k]) ++will1;
                       else ++will2;
                   use += min(will1, will2);
                }
            ans = min(ans, use);
        }
       if (ans > limit) printf("-1\n");
       else printf("%d\n", ans);
    }
}