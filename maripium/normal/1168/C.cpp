#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n, q;
int a[N];
int last[19][19];
vector<int> g[N];
int nxt[N][19];
int go[N][19];

int main() {
   scanf("%d %d", &n, &q);
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
   }
   for (int i = 0; i < 19; ++i) {
      for (int j = 0; j < 19; ++j) {
         last[i][j] = n + 1;
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 19; ++j) {
         nxt[i][j] = n + 1;
      }
   }
   for (int i = n; i > 0; --i) {
      for (int j = 0; j < 19; ++j) {
         for (int k = 0; k < 19; ++k) {
            if ((a[i] >> j & 1) && (a[i] >> k & 1)) {
               last[j][k] = i;
            }
            int cur = last[j][k];
            if (cur == n + 1 || cur == i) continue;
            if ((a[i] & a[cur]) == 0) continue;
            if (!(a[i] >> j & 1)) nxt[i][j] = min(nxt[i][j], cur);
            if (!(a[i] >> k & 1)) nxt[i][k] = min(nxt[i][k], cur);
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 19; ++j) {
         if (a[i] >> j & 1) go[i][j] = i;
         else go[i][j] = n + 1;
      }
   }
   for (int i = n; i > 0; --i) {
      for (int j = 0; j < 19; ++j) {
         for (int k = 0; k < 19; ++k) {
            if (nxt[i][k] == n + 1) continue;
            go[i][j] = min(go[i][j], go[nxt[i][k]][j]);
         }
      }
   }
   while (q--) {
      int x, y;
      scanf("%d %d", &x, &y);
      bool ans = false;
      for (int i = 0; i < 19; ++i) {
         if ((a[y] >> i & 1) && go[x][i] <= y) ans = true;
      }
      puts(ans ? "Shi" : "Fou");
   }
}