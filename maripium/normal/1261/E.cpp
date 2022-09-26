#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> A(N);
   vector<int> P(N);
   {
      vector<pair<int, int>> arr;
      for (int i = 0; i < N; ++i) {
         int x;
         cin >> x;
         arr.emplace_back(x, i);
      }
      sort(arr.rbegin(), arr.rend());
      for (int i = 0; i < N; ++i) {
         A[i] = arr[i].first;
         P[i] = arr[i].second;
      }
   }

   function<vector<vector<int>>(int)> solve = [&](int fs) {
      if (fs == N) {
         return vector<vector<int>>();
      }
      vector<int> bads;
      for (int i = fs + 1; i < N; ++i) {
         if (A[i] == N - fs) {
            --A[i];
            bads.emplace_back(i);
         }
      }
      if (bads.size()) {
         --A[fs];
         bads.emplace_back(fs);
      }
      vector<vector<int>> ans = solve(fs + 1);
      if (ans.size() + !(bads.empty()) <= N - fs) {
         --A[fs];
         ans.emplace_back(1, fs);
      }
      for (auto &vv : ans) {
         if (A[fs]) {
            --A[fs];
            vv.emplace_back(fs);
         }
      }
      if (A[fs]) {
         ans.emplace_back(1, fs);
      }
      if (bads.size()) {
         ans.emplace_back(bads);
      }
      return ans;
   };
   auto ans = solve(0);
   cout << ans.size() << "\n";
   for (auto vv : ans) {
      vector<int> was(N);
      for (int v : vv) {
         was[P[v]] = 1;
      }
      for (int i = 0; i < N; ++i) {
         cout << was[i];
      }
      cout << "\n";
   }
}