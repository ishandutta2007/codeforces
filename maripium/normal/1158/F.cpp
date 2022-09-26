#include <bits/stdc++.h>

using namespace std;

const int N = 3030;
const int mod = 998244353;

int n, c;
int a[N];
int cnt[N][N];
int f[N][N];
int ways[N], inv[N];
int ans[N];

void add(int &x,int y) {
   x += y; if (x >= mod) x -= mod;
}

void sub(int &x,int y) {
   x -= y; if (x < 0) x += mod;
}

int mul(int x,int y) {
   return (long long) x * y % mod;
}

int pw(int x,int y) {
   int ans = 1;
   for (; y > 0; y >>= 1) {
      if (y & 1) ans = mul(ans, x);
      x = mul(x, x);
   }
   return ans;
}

int main() {
   for (int i = 1; i < N; ++i) {
      ways[i] = mul(ways[i - 1], 2);
      add(ways[i], 1);
      inv[i] = pw(ways[i], mod - 2);
   }
   scanf("%d %d", &n, &c);
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      --a[i];
      for (int j = 0; j < c; ++j) cnt[i][j] = cnt[i - 1][j] + (j == a[i]);
   }

   if (c <= 11) {
      f[0][0] = 1;
      for (int i = 1; i <= n; ++i) {
         for (int j = i / c; j >= 0; --j) {
            for (int k = ways[c] - 1; k >= 0; --k) {
               if ((k | (1 << a[i])) == ways[c]) add(f[j + 1][0], f[j][k]);
               else add(f[j][k | (1 << a[i])], f[j][k]);
            }
         }
      }
      for (int i = 0; i <= n; ++i) {
         for (int j = 0; j < ways[c]; ++j) {
            add(ans[i], f[i][j]);
         }
      }
   } else {
      f[0][0] = 1;
      for (int i = 0; i <= n; ++i) {
         int tot = ways[n - i] + 1;
         int bad = c;
         int cur = 1;

         for (int j = i + 1; j <= n; ++j) {
            int cnt = ::cnt[j][a[j]] - ::cnt[i][a[j]];
            if (cnt > 1) cur = mul(cur, mul(ways[cnt], inv[cnt - 1]));
            else bad--;
            if (!bad) {
               int coef = mul(cur, inv[cnt]);
               sub(tot, mul(coef, ways[n - j] + 1));
               for (int k = 0; k * c <= i; ++k) {
                  add(f[j][k + 1], mul(f[i][k], coef));
               }
            }
         }
         for (int j = 0; j * c <= i; ++j) add(ans[j], mul(tot, f[i][j]));
      }
   }
   sub(ans[0], 1);
   for (int i = 0; i <= n; ++i) printf("%d ", ans[i]);
}