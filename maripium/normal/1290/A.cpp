#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N, M, K;
      cin >> N >> M >> K;
      vector<int> A(N);
      for (int i = 0; i < N; ++i) cin >> A[i];
      vector<vector<int>> F(N, vector<int>(N, INT_MAX));
      for (int i = 0; i < N; ++i) {
         int j = M - 1 - i;
         if (j < 0) continue;
         F[i][j] = max(A[i], A[N - 1 - j]);
      }
      int ans = 0;
      for (int i = N - 1; i >= 0; --i) {
         for (int j = N - 1; j >= 0; --j) {
            if (i < N - 1) F[i][j] = min(F[i][j], F[i + 1][j]);
            if (j < N - 1) F[i][j] = min(F[i][j], F[i][j + 1]);
            if (i + j <= K && F[i][j] != INT_MAX) ans = max(ans, F[i][j]);
         }
      }
      cout << ans << "\n";
   }
}