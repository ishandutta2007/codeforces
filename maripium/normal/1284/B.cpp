#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<vector<int>> A(N);
   int cnt = 0;
   vector<bool> good(N);
   for (int z = 0; z < N; ++z) {
      int sz;
      cin >> sz;
      bool flag = false;
      A[z].resize(sz);
      for (int i = 0; i < sz; ++i) {
         cin >> A[z][i];
         if (i > 0) {
            flag |= (A[z][i - 1] < A[z][i]);
         }
      }
      cnt += flag;
      good[z] = flag;
   }
   vector<int> vals;
   ll ans = 2LL * (ll) N * cnt - (ll) cnt * cnt;
   for (int z = 0; z < N; ++z) {
      if (!good[z]) {
         vals.emplace_back(A[z].back());
      }
   }
   sort(vals.begin(), vals.end());
   for (int z = 0; z < N; ++z) {
      if (!good[z]) {
         ans += int(lower_bound(vals.begin(), vals.end(), A[z][0]) - vals.begin());
      }
   }
   cout << ans << "\n";
   return 0;
}