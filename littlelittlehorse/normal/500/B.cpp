#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[301], f[301][301];
char str[1111][1111];

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
     for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
               f[i][j] = str[i][j] - '0';
     for (int i = 1; i <= n; i++) f[i][i] = 1;
     for (int k = 1; k <= n; k++)
          for (int i = 1; i <= n; i++)
               if (f[i][k])
                    for (int j = 1; j <= n; j++)
                         if (f[k][j]) f[i][j] = 1;
     for (int i = 1; i <= n; i++)
     {
          int pos = i;
          for (int j = i + 1; j <= n; j++)
               if (a[j] < a[pos] && f[i][j]) pos = j;
          swap(a[i], a[pos]);
     }
     for (int i = 1; i <= n; i++) printf("%d ", a[i]);
     printf("\n");
}