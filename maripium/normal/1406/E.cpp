#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<bool> np(N+1, false);
   np[0] = np[1] = true;
   vector<int> primes;
   for (int i = 2; i <= N; ++i) if (!np[i]) {
      primes.emplace_back(i);
      for (int j = 2*i; j <= N; j += i) np[j] = true;
   }
   auto A = [&](int x) {
      cout << "A " << x << endl;
      int ret; cin >> ret;
      return ret;
   };
   auto B = [&](int x) {
      cout << "B " << x << endl;
      int ret; cin >> ret;
      return ret;
   };
   vector<int> big;
   for (int p : primes) {
      if (int64_t(p) * p <= N) {
         B(p);
      } else {
         big.emplace_back(p);
      }
   }
   int ans = [&]() {
      int sz = A(1);
      while (big.size()) {
         int bsz = big.size();
         vector<int> lbig(big.begin(), big.begin() + (bsz+1)/2);
         vector<int> rbig(big.begin()+(bsz+1)/2, big.end());
         int nsz = sz - lbig.size();
         for (int p : lbig) {
            int z = B(p);
            if (z == 2) return p;
         }
         sz = A(1);
         if (sz == nsz) {
            big = rbig;
         } else {
            for (int p : lbig) if (B(p)) return p;
            assert(false);
         }
      }
      return 1;
   }();
   for (int p : primes) {
      while (int64_t(p) * p <= N && int64_t(ans) * p <= N && B(ans * p)) ans *= p;
   }
   cout << "C " << ans << '\n';
   return 0;
}