#include <bits/stdc++.h>

using namespace std;

char a[55][55];
int pref[55][55];
int f[55][55][55][55];

int get(int lx, int ly, int rx, int ry) {
   return pref[rx][ry] - pref[rx][ly - 1] - pref[lx - 1][ry] + pref[lx - 1][ly - 1];
}

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i){
      scanf("%s", a[i] + 1);
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         pref[i][j] = (a[i][j] == '#');
         pref[i][j] += (pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]);
      }
   }
   for (int lx = n; lx > 0; --lx) {
      for (int ly = n; ly > 0; --ly) {
         for (int rx = lx; rx <= n; ++rx) {
            for (int ry = ly; ry <= n; ++ry) {
               if (get(lx, ly, rx, ry) == 0) {
                  f[lx][ly][rx][ry] = 0;
                  continue;
               }
               f[lx][ly][rx][ry] = n;
               for (int x = lx; x < rx; ++x) {
                  f[lx][ly][rx][ry] = min(f[lx][ly][rx][ry], f[lx][ly][x][ry] + f[x + 1][ly][rx][ry]);
               }
               for (int y = ly; y < ry; ++y) {
                  f[lx][ly][rx][ry] = min(f[lx][ly][rx][ry], f[lx][ly][rx][y] + f[lx][y + 1][rx][ry]);
               }
               int mx = max(rx - lx + 1, ry - ly + 1);
               for (int sz = 1; sz <= n; ++sz) {
                  int csz = sz;
                  int tx = max(lx, rx - sz + 1);
                  int ty = max(ly, ry - sz + 1);
                  if (get(tx, ty, rx, ry) == 0) {
                     csz = 0;
                  }
                  f[lx][ly][rx][ry] = min(f[lx][ly][rx][ry], csz + f[lx][ly][tx - 1][ry] + f[tx][ly][rx][ty - 1]);
               }
            }
         }
      }
   }
   cout << f[1][1][n][n] << "\n";
}