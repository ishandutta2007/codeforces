#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   vector<string> numbers = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
   vector<int> masks;
   for (auto z : numbers) {
      int cur = 0;
      for (char c : z) cur = cur * 2 + c - '0';
      masks.emplace_back(cur);
   }
   int N, K;
   cin >> N >> K;
   vector<int> vals;
   for (int i = 0; i < N; ++i) {
      string z;
      cin >> z;
      int cur = 0;
      for (char c : z) cur = cur * 2 + (c - '0');
      vals.emplace_back(cur);
   }
   vector<vector<bool>> dp(N + 1, vector<bool>(K + 1));
   vector<vector<array<int, 3>>> prv(N + 1, vector<array<int, 3>>(K + 1));
   queue<pair<int, int>> q;
   dp[0][0] = true;
   q.emplace(0, 0);
   while (!q.empty()) {
      int i, k; tie(i, k) = q.front(); q.pop();
      if (i == N) continue;
      for (int z = 9; z >= 0; --z) {
         if ((masks[z] & vals[i]) != vals[i]) continue;
         int add = __builtin_popcount(masks[z]) - __builtin_popcount(vals[i]);
         if (k + add <= K && !dp[i + 1][k + add]) {
            dp[i + 1][k + add] = true;
            prv[i + 1][k + add] = {i, k, z};
            q.emplace(i + 1, k + add);
         }
      }
   }
   if (!dp[N][K]) {
      cout << "-1\n";
      return 0;
   }
   vector<int> ans;
   for (int i = N; i > 0; --i) {
      array<int, 3> cur = prv[i][K];
      ans.emplace_back(cur[2]);
      assert(cur[0] == i - 1);
      K = cur[1];
   }
   reverse(ans.begin(), ans.end());
   for (int v : ans) cout << v;
}