#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void add(int &x, int y) {
   x += y;
   if (x >= mod) x -= mod;
}

void sub(int &x, int y) {
   x -= y;
   if (x < 0) x += mod;
}

int mul(int x, int y) {
   return (long long) x * y % mod;
}

int inv(int x) {
   int ans = 1;
   for (int y = mod - 2; y > 0; y >>= 1, x = mul(x, x)) {
      if (y & 1) {
         ans = mul(ans, x);
      }
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   int n, k;
   cin >> n >> k;
   vector<int> fact(n + 1);
   vector<int> ifact(n + 1);
   fact[0] = 1;
   for (int i = 1; i <= n; ++i) {
      fact[i] = mul(fact[i - 1], i);
   }
   for (int i = 0; i <= n; ++i) {
      ifact[i] = inv(fact[i]);
   }
   auto C = [&](int x, int y) {
      return mul(fact[x], mul(ifact[y], ifact[x - y]));
   };
   vector<int> pwk(n * n + 1); // k ^ i
   vector<int> pwk1(n * n + 1); // (k - 1) ^ i
   pwk[0] = 1;
   pwk1[0] = 1;
   for (int i = 1; i <= n * n; ++i) {
      pwk[i] = mul(pwk[i - 1], k);
      pwk1[i] = mul(pwk1[i - 1], k - 1);
   }
   int ans = 0;
   for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
         int cur = mul(C(n, i), C(n, j));
         int f = (i + j) * n - i * j;
         int g = n * n - f;
         cur = mul(cur, mul(pwk1[f], pwk[g]));
         if (i + j & 1) {
            sub(ans, cur);
         } else {
            add(ans, cur);
         }
      }
   }
   cout << ans << "\n";
}