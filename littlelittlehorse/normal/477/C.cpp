#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[2001][2001], n, m;
char str[2222], str1[2222];

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     memset(f, 0, sizeof(f));
     scanf("%s%s", str + 1, str1 + 1);
     n = strlen(str + 1); 
     m = strlen(str1 + 1);
     memset(f, 0, sizeof(f));
     for (int i = 1; i <= n; i++)
     {
          int Left = 1, k = i;
          for (; Left <= m && k <= n; k++)
                if (str[k] == str1[Left]) 
                    if (++Left == m + 1) break;
          for (int j = 0; j < i; j++)
          {
               if (k <= n) 
               f[k][j + k - i + 1 - m] = max(f[k][j + k - i + 1 - m],
               f[i - 1][j] + 1);
               else f[n][j + n - i + 1] = max(f[n][j + n - i + 1], f[i - 1][j]);
               f[i][j] = max(f[i][j], f[i - 1][j]);
          }
     }
     for (int i = 0; i <= n; i++)
     {
          printf("%d", f[n][i]);
          if (i != n) printf(" ");
     }
     printf("\n");
}