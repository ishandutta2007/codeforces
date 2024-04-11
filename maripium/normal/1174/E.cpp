#include <bits/stdc++.h>

using namespace std;

const int N = 2000100;
const int mod = 1e9 + 7;

void add(int &x, int y) {
   x += y; if (x >= mod) x -= mod;
}

int mul(int x, int y) {
   return (long long) x * y % mod;
}

int n;
int cnt[N];

int solve(vector<int> a) {
   a.push_back(1);
   int sz = a.size();
   for (int i = sz - 1; i > 0; --i) {
      a[i - 1] *= a[i];
   }
   vector<int> f(sz);
   for (int i = 0; i < sz; ++i) {
      f[i] = cnt[a[i]];
      for (int j = 0; j < i; ++j) {
         f[i] -= f[j];
      }
   }
   vector<array<int, 2>> dp(1, {0, 1});
   int cnt = 0;
   int last = -1;
   for (int v : f) {
      int csz = dp.size();
      vector<array<int, 2>> ndp(csz + v);
      for (int i = csz - 1; i >= 0; --i) {
         if (i) {
            add(dp[i - 1][1], mul(last, dp[i][0]));
            add(dp[i - 1][1], mul(i, dp[i][1]));
         }
         add(ndp[i + v][0], dp[i][1]);
      }
      last = v;
      dp.swap(ndp);
   }
   for (int i = n; i > 0; --i) {
      add(dp[i - 1][1], mul(last, dp[i][0]));
            add(dp[i - 1][1], mul(i, dp[i][1]));
   }
   return dp[0][1];
}

int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
      cnt[i] = n / i;
   }
   int sz = __lg(n);
   vector<int> a(sz, 2);
   int ans = 0;
   add(ans, solve(a));
   for (int i = 0; i < sz; ++i) {
      a[i] = 3;
      add(ans, solve(a));
      a[i] = 2;
   }
   printf("%d\n", ans);
}