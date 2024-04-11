#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<int64_t> A(N); for (auto &a : A) cin >> a;

   int64_t ans = 0;
   for (int i = 0; i < N; i += 2) {
      int64_t pref = 0;
      int64_t sum = 0;
      for (int j = i + 1; j < N; ++j) {
         if (j & 1) {
            int64_t lo = 1;
            lo = max(lo, -pref);
            int64_t hi = A[i];
            hi = min(hi, A[j] - sum);
            if (lo <= hi) ans += (hi -lo + 1); // lo += hi;
            sum -= A[j];
            pref = min(pref, sum);
         } else {
            sum += A[j];
         }
      }
   }
   cout << ans << '\n';
   return 0;
}