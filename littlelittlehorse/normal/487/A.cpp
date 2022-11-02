#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a1, b1, c1, a2, b2, c2, a3, b3, c3;

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%d%d%d", &a1, &b1, &c1);
     scanf("%d%d%d", &a2, &b2, &c2);
     scanf("%d%d%d", &a3, &b3, &c3);
     int ans = 1 << 30;
     for (int i = 0; i <= 200; i++)
          for (int j = 0; j <= 200; j++)
          {
               int cost = i * c3 + j * b3;
               if (j + b1 <= c2) continue;
               int per = j + b1 - c2;
               int sx = 0;
               if (per > 0)
               {
                    sx = a2 / per;
                    if (a2 % per) sx++;
               }
               cost += max(0, sx * (b2 - c1 - i) + 1 - a1) * a3;
               ans = min(cost, ans);
          }
     printf("%d\n", ans);
}