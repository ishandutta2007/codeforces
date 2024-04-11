#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const int mod = 998244353;

void add(int &x,int y) {
   x += y;
   if (x >= mod) x -= mod;
}

int mul(int x,int y) {
   return (long long) x * y % mod;
}

int pw(int x,int y) {
   int ans = 1;
   while (y) {
      if (y & 1) ans = mul(ans, x);
      x = mul(x, x);
      y >>= 1;
   }
   return ans;
}

int cnt[N];
int f[N][N];
int sf[N][N];
int inv[N];

int main() {
   int n;
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      ++cnt[x];
   }
   for (int i = 1; i <= n; ++i) {
      inv[i] = pw(i, mod - 2);
   }
   int ans = 0;
   f[0][0] = 1;
   for (int i = 0; i <= n; ++i) sf[0][i] = 1;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         if (i > 1 && cnt[j]) add(ans, mul(f[i - 1][j], mul(cnt[j] - 1, inv[n - i + 1])));
         f[i][j] = mul(sf[i - 1][j - 1], mul(cnt[j], inv[n - i + 1]));
         sf[i][j] = sf[i][j - 1];
         add(sf[i][j], f[i][j]);
      }
   }
   printf("%d\n", ans);
}