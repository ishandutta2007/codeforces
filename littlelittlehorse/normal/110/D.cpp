#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int pl, pr, vl, vr, n, m, c[100001], cnt;

int main(){
     //freopen("d.in", "r", stdin);
     //freopen("d.out", "w", stdout);
     scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &m);
     cnt = 0;
     c[0] = 0;
     for (int i = 0; i <= cnt; i++)
     {
          if (c[i] * 10LL + 4 <= 1000000000) c[++cnt] = c[i] * 10 + 4;
          if (c[i] * 10LL + 7 <= 1000000000) c[++cnt] = c[i] * 10 + 7; 
     }
     c[++cnt] = 1000000001;
     double ans = 0;
     for (int i = 1; i + m - 1 < cnt; i++)
          for (int j = 1; j <= 2; j++)
          {
               int L1 = max(pl, c[i - 1] + 1), R1 = min(pr, c[i]),
                   L2 = max(vl, c[i + m - 1]), R2 = min(vr, c[i + m] - 1); 
               if (L1 <= R1 && L2 <= R2)
               {
                    if (m == 1 && j == 2)
                         ans +=  1.0 * (R1 - L1 + 1) / (pr - pl + 1)
                    * (R2 - L2 + 1) / (vr - vl + 1) - 
                    1.0 / (pr - pl + 1)
                    / (vr - vl + 1);
                    else
                    ans += 1.0 * (R1 - L1 + 1) / (pr - pl + 1)
                    * (R2 - L2 + 1) / (vr - vl + 1);
               }
               swap(pl, vl); swap(pr, vr);
          }
     printf("%.10f\n", ans);          
}