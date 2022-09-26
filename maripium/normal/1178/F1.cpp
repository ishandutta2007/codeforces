#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void add(int &x, int y) {
   x += y;
   if (x >= mod) x -= mod;
}

int mul(int x, int y) {
   return (long long) x * y % mod;
}

int n, m;
int a[505];
int f[505][505];
int g[505][505];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   assert(n == m);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for (int l = n; l > 0; --l) {
      for (int r = l; r <= n; ++r) {
         int md = 0;
         for (int i = l; i <= r; ++i) {
            if (!md || a[i] < a[md]) {
               md = i;
            }
         }
         f[l][r] = 1;
         if (l < md) {
            f[l][r] = mul(f[l][r], g[l][md - 1]);
         }
         if (md < r) {
            f[l][r] = mul(f[l][r], g[md + 1][r]);
         }
         // cout << l << " " << r << " " << f[l][r] << "\n";
         add(g[l][r], f[l][r]);
         for (int r2 = r + 1; r2 <= n; ++r2) {
            add(g[l][r2], mul(f[l][r], g[r + 1][r2]));
         }
      }
   }
   cout << g[1][n] << "\n";
}