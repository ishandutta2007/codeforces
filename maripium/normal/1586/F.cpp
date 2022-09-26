#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, K; cin >> N >> K;
   vector<vector<int>> color(N, vector<int>(N, -1));
   int num_colored = 0;
   int ans = 0;
   vector<int> G(N); iota(G.begin(), G.end(), 0);
   while (num_colored < N*(N-1)/2) {
      ans++;
      for (int i = 0; i < N; ++i) G[i] /= K;
      for (int i = 0; i < N; ++i) {
         for (int j = i+1; j < N; ++j) {
            if (G[i] == G[j] && color[i][j] == -1) {
               color[i][j] = ans;
               num_colored++;
            }
         }
      }
   }
   cout << ans << '\n';
   for (int i = 0; i < N; ++i) {
      for (int j = i+1; j < N; ++j) {
         cout << color[i][j] << ' ';
      }
   }
}