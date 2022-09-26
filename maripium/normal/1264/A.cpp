#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<pair<int, int>> vals;
      for (int z = 0; z < N; ++z) {
         int v;
         cin >> v;
         if (vals.size() && vals.back().first == v) {
            ++vals.back().second;
         } else {
            vals.emplace_back(v, +1);
         }
      }
      int sumAll = 0;
      for (auto z : vals) {
         sumAll += z.second;
      }
      while (sumAll > (N / 2)) {
         sumAll -= vals.back().second;
         vals.pop_back();
      }
      int suffSum = 0;
      int prefSum = 0;
      for (int z = 1; z < vals.size(); ++z) {
         suffSum += vals[z].second;
      }
      for (int z = 1; z < vals.size(); ++z) {
         prefSum += vals[z].second;
         suffSum -= vals[z].second;
         if (min(prefSum, suffSum) > vals[0].second) {
            cout << vals[0].second << " " << prefSum << " " << suffSum << "\n";
            goto next_test;
         }
      }
      cout << "0 0 0\n";
      next_test:;
   }
}