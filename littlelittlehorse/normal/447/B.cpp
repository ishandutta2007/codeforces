#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1001], f[1001][1001];
char str[1001];
const int oo = - (1 << 30) - (1 << 30);

int main(){
     scanf("%s", str); n = strlen(str);
     scanf("%d", &m); int Max = 0;
     for (int i = 0; i < 26; i++) scanf("%d", &a[i]), Max = max(Max, a[i]);
     for (int i = 0; i <= n; i++)
          for (int j = 0; j <= m; j++) f[i][j] = oo;
     f[0][0] = 0;
     for (int i = 0; i <= n; i++)
          for (int j = 0; j <= m; j++)
          {
               if (i != n) f[i + 1][j] = max(f[i + 1][j], f[i][j] + (i + j + 1) * a[str[i] - 'a']);
               if (j != m) f[i][j + 1] = max(f[i][j + 1], f[i][j] + (i + j + 1) * Max);
          }
     printf("%I64d\n", f[n][m]);
}