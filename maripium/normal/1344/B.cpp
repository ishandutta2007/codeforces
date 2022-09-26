#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M;
   cin >> N >> M;
   vector<string> S(N);
   for (int i = 0; i < N; ++i) {
      cin >> S[i];
   }
   auto __assert = [&](bool z) {
      if (!z) {
         cout << -1; exit(0);
      }
   };
   bool emptyRow = false;
   for (int row = 0; row < N; ++row) {
      int l = 0;
      while (l < M && S[row][l] == '.') l++;
      if (l == M) {
         emptyRow = true;
         continue;
      }
      int r = M - 1;
      while (r >= 0 && S[row][r] == '.') r--;
      for (int z = l; z <= r; ++z) {
         __assert(S[row][z] == '#');
      }
   }
   bool emptyCol = false;
   for (int col = 0; col < M; ++col) {
      int u = 0;
      while (u < N && S[u][col] == '.') u++;
      if (u == N) {
         emptyCol = true;
         continue;
      }
      int d = N - 1;
      while (d >= 0 && S[d][col] == '.') d--;
      for (int z = u; z <= d; ++z) {
         __assert(S[z][col] == '#');
      }
   }
   vector<vector<bool>> visited(N, vector<bool>(M));
   function<void(int, int)> Dfs = [&](int x, int y) {
      if (x < 0 || x >= N || y < 0 || y >= M) return;
      if (S[x][y] == '.') return;
      if (visited[x][y]) return;
      visited[x][y] = true;
      Dfs(x - 1, y); Dfs(x, y - 1); Dfs(x, y + 1); Dfs(x + 1, y);
   };
   __assert(emptyRow == emptyCol);
   int ans = 0;
   for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (S[i][j] == '#' && !visited[i][j]) {
         ans++;
         Dfs(i, j);
      }
   }
   cout << ans << "\n";
}