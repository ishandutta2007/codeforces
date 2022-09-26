#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<int64_t> H(N);
   for (int i = 0; i < N; ++i) cin >> H[i];
   set<int> ps;
   int64_t start = H[0];
   auto value = [&](int i) {
      return start + i - int(ps.size());
   };
   for (int i = 1; i < N; ++i) {
      int64_t cur = value(i - 1);
      while (ps.size()) {
         int j = *ps.rbegin();
         ps.erase(j);
         if (H[i] - cur - 1 >= (i - j + 1)) {
            H[i] -= (i - j);
            cur += 1;
            continue;
         } else {
            int mv = (H[i] - cur - 1);
            ps.emplace(j+mv);
            break;
         }
      }
      if (ps.size()) continue;
      int64_t low = 0, high = 1e12;
      while (low < high) {
         int64_t mid = (low + high + 1) >> 1;
         int64_t prv = cur + mid;
         int64_t nxt = H[i] - mid * i;
         if (prv <= nxt) {
            low = mid;
         } else {
            high = mid - 1;
         }
      }
      start += low;
      H[i] -= low * i;
      cur += low;
      if (H[i] > cur + 1) {
         int64_t op = H[i] - cur - 1;
         start += 1;
         ps.emplace(op);
      }
      if (H[i] == cur) ps.emplace(i);
   }
   for (int i = 0; i < N; ++i) {
      if (i && !ps.count(i)) start++;
      cout << start << ' ';
   }
   cout << '\n';
   return 0;
}