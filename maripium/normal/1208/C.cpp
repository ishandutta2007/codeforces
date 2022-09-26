#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   int cnt = 0;
   vector<vector<int>> ans(n, vector<int>(n));
   for (int i = 0; i < n; i += 4) {
      for (int j = 0; j < n; j += 4) {
         for (int ii = 0; ii < 4; ++ii) {
            for (int jj = 0; jj < 4; ++jj) {
               ans[i + ii][j + jj] = cnt++;
            }
         }
      }
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cout << ans[i][j] << " ";
      }
      cout << "\n";
   }
}