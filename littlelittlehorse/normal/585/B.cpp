#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[111][3], cnt;
char str[4][111];
bool b[101][4];

int main() {
  //   freopen("b.in", "r", stdin);
  //   freopen("b.out", "w", stdout);
     scanf("%d", &test);
     for (;test--; ) {
          scanf("%d%d", &n, &m);
          cnt = 0;
          for (int i = 1; i <= 3; i++) {
               scanf("%s", str[i] + 1);
               for (int j = 1; j <= n; j++)
                    if (j == 1 || str[i][j - 1] == '.' || str[i][j - 1] == 's')
                         if (str[i][j] != 's' && str[i][j] != '.') {
                              a[++cnt][0] = j; a[cnt][2] = i;
                              for (int k = j; k <= n && str[i][k] != 's' && str[i][k] != '.'; k++)
                                   a[cnt][1] = k;
                              
                         }
          }
          memset(b, false, sizeof(b));
          if (str[1][1] == 's') b[1][1] = true;
          if (str[2][1] == 's') b[1][2] = true;
          if (str[3][1] == 's') b[1][3] = true;
          for (int i = 1; i < n; i++)
               for (int j = 1; j <= 3; j++) 
                    if (b[i][j])
                    for (int k = -1; k <= 1; k++) {
                         int l = j + k;
                         if (l < 1 || l > 3) continue;
                         bool ok = true;
                         for (int x = 1; x <= cnt && ok; x++)
                              if (l == a[x][2] && ((a[x][0] - i * 2 + 2 <= i + 1 && a[x][1] - i * 2 + 2 >= i + 1)
                              || (a[x][0] - i * 2  <= i + 1 && a[x][1] - i * 2 >= i + 1)
                              || (a[x][0] - i * 2 + 1 <= i + 1 && a[x][1] - i * 2 + 1 >= i + 1))) {
                                //   printf("%d %d %d %d %d\n", i, l, x, a[x][0] - i * 2 + 2, a[x][1] - i * 2 + 2);
                                   ok = false;
                              } else
                              if (j == a[x][2] && (a[x][0] - i * 2 + 2 <= i + 1 && a[x][1] - i * 2 + 2 >= i + 1)) {
                                //   printf("%d %d %d %d %d\n", i, l, x, a[x][0] - i * 2 + 2, a[x][1] - i * 2 + 2);
                                   ok = false;
                              }
                         if (ok) b[i + 1][l] = true;
                    }
          if (b[n][1] || b[n][2] || b[n][3]) printf("YES\n");
          else printf("NO\n");
     }     
}