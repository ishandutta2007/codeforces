
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, str[222222], p[222222], f[222222], v[222222];
char str2[111111], str1[111111];

const int P = 1000000007;

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%s%s", str1, str2);
     n = strlen(str1); m = strlen(str2);
     int num = 0;
     for (int i = 0; i < m; i++) str[++num] = str2[i];
     str[++num] = '!';
     for (int i = 0; i < n; i++) str[++num] = str1[i];
     int j = 0; p[1] = 0;; f[0] = 1; v[0] = 1;
     int sx = -1;
     int ans = 0;
     for (int i = 2; i <= num; i++)
     {
          for (; j && str[j + 1] != str[i]; j = p[j]);
          if (str[j + 1] == str[i]) ++j;
          p[i] = j;
          //printf("%d %d\n", i, j);
          if (p[i] == m) sx = i - m - m - 1;
          if (i > m + 1)
          {
              // printf("! %d %d %d %d\n", i, i - m, sx, f[i - m - 2]);
              f[i - m - 1] = f[i - m - 2];
               v[i - m - 1] = v[i - m - 2] + f[i - m - 2]; v[i - m - 1] %= P;
           //    ++f[i - m - 1];
           //    f[i - m - 1] %= P;
         //  printf("%d\n",sx);
               if (sx != -1) f[i - m - 1] += v[sx], f[i - m - 1] %= P,
               v[i - m - 1] += v[sx]; v[i - m - 1] %= P;
               ans = f[i - m - 1]; ans %= P;
               //printf("! %d %d %d %d %d %d\n", i, i - m, f[sx], f[i - m - 1], v[i - m - 1], v[i - m - 2]);
          }
     } 
     if (--ans < 0) ans += P;
     printf("%d\n", ans);
}