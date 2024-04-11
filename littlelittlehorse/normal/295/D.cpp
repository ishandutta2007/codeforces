#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int p = 1000000007;
int n, m, f[2001][2001][2];

int main() {
     //freopen("295d.in", "r", stdin);
     //freopen("295d.out", "w", stdout);
     scanf("%d%d", &n, &m);
     if (m == 1) {
          printf("0\n");
          return 0;
     }
     memset(f, 0, sizeof(f));
     //for (int j = 2; j <= m; j++) f[0][j][0] = 1;
     for (int i = 1; i <= n; i++) {
          int sum = 0, value = 1;
          for (int j = 2; j <= m; j++) {
               value += sum; value %= p;
               f[i][j][0] = value;
               sum += (f[i - 1][j][0] + f[i - 1][j][1]) % p; sum %= p;
               f[i][j][1] = (f[i - 1][j][0] + f[i - 1][j][1]) % p;
               value += (f[i - 1][j][0] + f[i - 1][j][1]) % p; value %= p;
          }
     }
     int ans = 0;
     for (int i = 1; i <= n; i++) 
          for (int j = 2; j <= m; j++) 
               ans += (1LL * (f[i][j][0] + f[i][j][1]) % p * f[n - i + 1][j][0]) % p * (m - j + 1) % p,
               ans %= p;//,
              // printf("%d %d %d %d\n", i, j, f[i][j][0] + f[i][j][1], f[n - i + 1][j][0]);
     printf("%d\n", ans);
}