#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int a[4001][3], n, ans, c[4001], r[4001], tot;
bool b[4001];

inline void cry(int i) {
     for (int j = i + 1; j <= n; j++)
          if (a[j][2] >= 0) {
               a[j][2] -= a[i][1];
               if (a[j][2] < 0) cry(j);
          }
}

int main() {
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) 
          for (int j = 0; j < 3; j++) scanf("%d", &a[i][j]);
     ans = 0;
     for (int i = 1; i <= n; i++) 
          if (a[i][2] >= 0) {
               c[++ans] = i;
               tot = 0;
               for (int j = i + 1, k = a[i][0]; k && j <= n; j++) 
                    if (a[j][2] >= 0) {
                         a[j][2] -= k--;
                         if (a[j][2] < 0) r[++tot] = j;
                    }
               for (int j = 1; j <= tot; j++) cry(r[j]);
          } 
     printf("%d\n", ans);
     for (int i = 1; i <= ans; i++) printf("%d ", c[i]);
     printf("\n");
}