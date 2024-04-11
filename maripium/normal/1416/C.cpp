#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<int> A(N); for (int &a : A) cin >> a;
   int ans = 0;
   int64_t inv = 0;
   for (int b = 29; b >= 0; --b) {
      int msk = 0;
      for (int z = b+1; z<30; ++z) msk |= (1<<z);
      int64_t cnt01 = 0;
      int64_t cnt10 = 0;
      vector<pair<int, int>> keks;
      for (int i = 0; i < N; ++i) keks.emplace_back(A[i] & msk, i);
      sort(keks.begin(), keks.end());
      int l = 0;
      while (l < N) {
         int r = l;
         while (r < N && keks[r].first == keks[l].first) r++;
         int cnt0 = 0;
         int cnt1 = 0;
         for (int i = l; i < r; ++i) {
            if (A[keks[i].second] >> b & 1) {
               cnt01 += cnt0;
               cnt1++;
            } else {
               cnt10 += cnt1;
               cnt0++;
            }
         }
         l = r;
      }
      inv += min(cnt01, cnt10);
      ans |= (cnt01 < cnt10) << b;
   }
   cout << inv << ' ' << ans << '\n';
   return 0;
}