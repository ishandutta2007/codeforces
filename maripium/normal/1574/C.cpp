#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int N; cin >> N;
   vector<int64_t> A(N); for (auto &a : A) cin >> a;
   int64_t Asum = accumulate(A.begin(), A.end(), int64_t(0));
   sort(A.begin(), A.end());
   int M; cin >> M;
   for (int i = 0; i < M; ++i) {
      int64_t x, y; cin >> x >> y;
      auto it = lower_bound(A.begin(), A.end(), x);
      int64_t ans = 2e18;;
      if (it != A.end()) {
         int64_t att = *it;
         int64_t def = Asum - (*it);
         ans = min(ans, max(int64_t(0), x - att) + max(int64_t(0), y - def));
      }
      if (it != A.begin()) {
         --it;
         int64_t att = *it;
         int64_t def = Asum - (*it);
         ans = min(ans, max(int64_t(0), x - att) + max(int64_t(0), y - def));
      }
      cout << ans << '\n';
   }
   return 0;
}