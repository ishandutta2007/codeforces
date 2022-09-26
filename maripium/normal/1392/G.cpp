#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M, K; cin >> N >> M >> K;
   string S, T; cin >> S >> T;
   vector<vector<int>> perm(N+1);
   perm[0].resize(K);
   iota(perm[0].begin(), perm[0].end(), 0);
   for (int i = 0; i < N; ++i) {
      int x, y; cin >> x >> y; --x, --y;
      perm[i+1] = perm[i];
      swap(perm[i+1][x], perm[i+1][y]);
   }
   vector<int> valS(N+1), valT(N+1);
   for (int i = 0; i <= N; ++i) {
      for (int j = 0; j < K; ++j) {
         valS[i] |= (S[j] - '0') << perm[i][j];
         valT[i] |= (T[j] - '0') << perm[i][j];
      }
   }
   vector<int> last(1 << K, -1);
   for (int i = 0; i <= N; ++i) last[valT[i]] = i;
   for (int diff = 0; diff <= K; ++diff) {
      for (int i = 0; i <= N; ++i) {
         if (last[valS[i]] >= i + M) {
            cout << K - diff << '\n';
            cout << i + 1 << ' ' << last[valS[i]] << '\n';
            return 0;
         }
      }
      vector<int> nlast(1 << K, -1);
      for (int val = 0; val < (1 << K); ++val) {
         for (int z = 0; z < K; ++z) nlast[val] = max(nlast[val], last[val ^ (1 << z)]);
      }
      last.swap(nlast);
   }
   return 0;
}