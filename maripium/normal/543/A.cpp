#include <bits/stdc++.h>

using namespace std;

int MOD;

int add(int x, int y) { return ((x += y) >= MOD) ? x - MOD : x; }

int main() {
   ios_base::sync_with_stdio(false);
   int N, M, B;
   cin >> N >> M >> B >> MOD;
   vector<int> A(N);
   for (int i = 0; i < N; ++i) cin >> A[i];
   vector<vector<int>> dp(N, vector<int>(B + 1));
   for (int i = 0; i < N; ++i) dp[i][0] = 1 % MOD;
   for (int z = 0; z < M; ++z) {
      vector<vector<int>> ndp(N, vector<int>(B + 1));
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j <= B - A[i]; ++j) {
            ndp[i][j + A[i]] = add(ndp[i][j + A[i]], dp[i][j]);
         }
         if (i > 0) {
            for (int j = 0; j <= B; ++j) {
               ndp[i][j] = add(ndp[i][j], ndp[i - 1][j]);
            }
         }
      }
      dp = ndp;
   }
   int ans = 0;
   for (int z = 0; z <= B; ++z) {
      ans = add(ans, dp[N - 1][z]);
   }
   cout << ans << "\n";
   return 0;
}