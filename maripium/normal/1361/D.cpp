#include <bits/stdc++.h>

using namespace std;

using ld = long double;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, K;
   cin >> N >> K;
   map<pair<int, int>, vector<ld>> dists;
   for (int i = 0; i < N; ++i) {
      int x, y;
      cin >> x >> y;
      int g = __gcd(abs(x), abs(y));
      if (g == 0) g = 1;
      dists[{x/g, y/g}].emplace_back(hypot(ld(x), ld(y)));
   }
   vector<ld> deltas;
   for (auto d : dists) {
      auto A = d.second;
      sort(A.begin(), A.end());
      for (int z = 0; z <= K - 1 && A.size(); z += 2) {
         deltas.emplace_back(A.back() * (K - 1 - z));
         A.pop_back();
      }
      if (A.size()) {
         int cf = K - 1 - 2 * ((K - 1) / 2 + 1);
         ld cur = 0;
         for (int i = 0; i < A.size(); ++i) {
            deltas.emplace_back(A[i] * cf + cur);
            cur -= 2 * A[i];
         }
      }
   }
   sort(deltas.begin(), deltas.end(), greater<ld>());
   cout << fixed << setprecision(11) << accumulate(deltas.begin(), deltas.begin() + K, 0.0) << "\n";
   return 0;

}