#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int64_t> A(N+1);
      for (int i = 1; i <= N; ++i) cin >> A[i];
      int64_t tot = accumulate(A.begin(), A.end(), int64_t(0));
      if (tot % N) {
         cout << "-1\n";
         continue;
      }
      tot /= N;
      vector<bool> done(N+1);
      vector<tuple<int, int, int64_t>> ops;
      auto make = [&](int i, int j, int64_t x) {
         ops.emplace_back(i, j, x);
         A[i] -= i * x;
         A[j] += i * x;
         assert(A[i] >= 0);
      };
      for (int i = 2; i <= N; ++i) {
         int64_t q = (i - A[i] % i) % i;
         make(1, i, q);
         assert(A[i] % i == 0);
         make(i, 1, A[i] / i);
      }
      for (int i = 2; i <= N; ++i) make(1, i, tot);
      for (int i = 1; i <= N; ++i) assert(A[i] == tot);
      cout << int(ops.size()) << '\n';
      for (auto q : ops) {
         cout << get<0>(q) << ' ' << get<1>(q) << ' ' << get<2>(q) << '\n';
      }
   }
}