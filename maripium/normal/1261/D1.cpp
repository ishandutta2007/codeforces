#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2020;
const int MOD = 998244353;

void add(int &x, int y) {
   x += y;
   if (x >= MOD) {
      x -= MOD;
   }
}

void sub(int &x, int y) {
   x -= y;
   if (x < 0) {
      x += MOD;
   }
}

int mul(int x, int y) {
   return (long long) x * y % MOD;
}

int N, K;
int A[MAXN];
int dp[MAXN][MAXN * 2];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> K;
   for (int i = 0; i < N; ++i) {
      cin >> A[i];
   }
   dp[0][N] = 1;
   for (int i = 0; i < N; ++i) {
      int x = A[i];
      int y = A[(i + 1) % N];
      for (int j = 0; j <= 2 * N; ++j) {
         if (x == y) {
            add(dp[i + 1][j], mul(K, dp[i][j]));
         } else {
            if (j) add(dp[i + 1][j - 1], dp[i][j]);
            add(dp[i + 1][j + 1], dp[i][j]);
            add(dp[i + 1][j], mul(K - 2, dp[i][j]));
         }
      }
   }
   int ans = 0;
   for (int i = N + 1; i <= 2 * N; ++i) {
      add(ans, dp[N][i]);
   }
   cout << ans << "\n";
   return 0;
}