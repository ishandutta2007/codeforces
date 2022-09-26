#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   vector<string> S(N);
   for (int i = 0; i < N; ++i) {
      cin >> S[i];
   }
   vector<vector<int>> pref(N + 1, vector<int>(M + 1));
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (S[i][j] == '.');
      }
   }
   vector<pair<int, int>> ps;
   auto get = [&](int xl, int yl, int xr, int yr) {
      return pref[xr + 1][yr + 1] - pref[xr + 1][yl] - pref[xl][yr + 1] + pref[xl][yl];
   };
   auto go = [&](int mid) {
      ps.clear();
      int r = 2 * mid;
      for (int i = 0; i < N - r; ++i) {
         for (int j = 0; j < M - r; ++j) {
            if (get(i, j, i + r, j + r) == 0) {
               ps.emplace_back(i + mid, j + mid);
            }
         }
      }
      vector<vector<int>> pref2(N + 1, vector<int>(M + 1));
      for (auto p : ps) {
         int x, y;
         tie(x, y) = p;
         pref2[x - mid][y - mid]++;
         pref2[x - mid][y + mid + 1]--;
         pref2[x + mid + 1][y - mid]--;
         pref2[x + mid + 1][y + mid + 1]++;
      }
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < M; ++j) {
            if (i) pref2[i][j] += pref2[i - 1][j];
            if (j) pref2[i][j] += pref2[i][j - 1];
            if (i && j) pref2[i][j] -= pref2[i - 1][j - 1];
            if (S[i][j] == 'X' && pref2[i][j] == 0) {
               return false;
            }
         }
      }
      return true;
   };
   int low = 0, high = (min(N, M) - 1) / 2;
   while (low < high) {
      int mid = (low + high + 1) >> 1;
      if (go(mid)) {
         low = mid;
      } else {
         high = mid - 1;
      }
   }
   assert(go(low));
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         S[i][j] = '.';
      }
   }
   for (auto p : ps) {
      S[p.first][p.second] = 'X';
   }
   cout << low << "\n";
   for (int i = 0; i < N; ++i) {
      cout << S[i] << "\n";
   }
}