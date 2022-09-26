#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1e14;

int N, K;
ll A[80][80];
vector<pair<ll, int>> opts[80][80];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> K;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         cin >> A[i][j];
      }
   }
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         for (int k = 0; k < N; ++k) {
            opts[i][j].emplace_back(A[i][k] + A[k][j], k);
         }
         sort(opts[i][j].begin(), opts[i][j].end());
      }
   }
   vector<int> cnts(N);
   cnts[0] = 2;
   vector<int> routes(1, 0);
   ll ans = INF;
   auto solve = [&]() {
      ll curAns = 0;
      for (int i = 0; i + 1 < int(routes.size()); ++i) {
         int ptr = 0;
         int v = routes[i];
         int u = routes[i + 1];
         while (ptr < opts[v][u].size() && cnts[opts[v][u][ptr].second]) ptr++;
         if (ptr == N) return;
         curAns += opts[v][u][ptr].first;
      }
      ans = min(ans, curAns);
   };
   function<void(int)> brute = [&](int v) {
      if (v == K) {
         routes.emplace_back(0);
         solve();
         routes.pop_back();
         return;
      }
      for (int i = 0; i < N; ++i) {
         cnts[i]++;
         routes.emplace_back(i);
         brute(v + 2);
         cnts[i]--;
         routes.pop_back();
      }
   };
   brute(2);
   cout << ans << "\n";
}