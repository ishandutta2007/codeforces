#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<vector<int64_t>> A(N, vector<int64_t>(N));
   for (int x = 0; x < N; ++x) {
      for (int y = 0; y < N; ++y) {
         int diag = x + y;
         if (x & 1) {
            A[x][y] = 1LL << (x + y);
         } else {
            A[x][y] = 0;
         }
      }
   }
   for (int x = 0; x < N; ++x) {
      for (int y = 0; y < N; ++y) {
         cout << A[x][y] << ' ';
      }
      cout << '\n';
   }
   cout << endl;
   int Q; cin >> Q;
   while (Q--) {
      int64_t K; cin >> K;
      vector<pair<int, int>> ans{{0, 0}};
      int x = 0, y = 0;
      for (int diag = 1; diag < 2 * N - 1; ++diag) {
         if (K & (1LL << diag)) {
            if (x & 1) y++;
            else x++;
         } else {
            if (x & 1) x++;
            else y++;
         }
         ans.emplace_back(x, y);
      }
      for (auto p : ans) {
         cout << p.first + 1 << ' ' << p.second + 1 << '\n';
      }
      cout << endl;
   }
}