#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[101], c[1001][2];

int main(){
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
     if (n == 1) 
     {
          printf("0 0\n");
          return 0;
     }
     int num = 0;
     for (int i = 1; i <= m; i++)
     {
          int Min = 1 << 30, Max = -Min, pos1 = 0, pos2 = 0;
          for (int j = 1; j <= n; j++)
          {
               if (a[j] < Min) Min = a[j], pos1 = j;
               if (a[j] > Max) Max = a[j], pos2 = j;
          }
          if (Min == Max) break;
          c[++num][0] = pos2; c[num][1] = pos1;
          ++a[pos1]; --a[pos2];
     }
     int Min = 1 << 30, Max = -Min, pos1 = 0, pos2 = 0;
     for (int j = 1; j <= n; j++)
     {
          if (a[j] < Min) Min = a[j], pos1 = j;
          if (a[j] > Max) Max = a[j], pos2 = j;
     }
     printf("%d %d\n", Max - Min, num);
     for (int i = 1; i <= num; i++) printf("%d %d\n", c[i][0], c[i][1]);
}