#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> A(N);
   for (int i = 0; i < N; ++i) {
      cin >> A[i];
   }
   int value = A.back();
   A.pop_back();
   --N;
   vector<int> xorVal(N);
   vector<int> needCnt(N);
   for (int i = 0; i < N; ++i) {
      int xr = A[i] ^ value;
      int cnt = __builtin_popcount(xr);
      if (__builtin_popcount(xr) & 1) {
         cout << "-1\n";
         return 0;
      }
      xorVal[i] = xr;
      needCnt[i] = cnt / 2;
   }

   map<vector<int>, int> mp;
   for (int mask = 0; mask < (1 << 15); ++mask) {
      vector<int> cnts(N);
      for (int i = 0; i < N; ++i) {
         int val = (mask & (xorVal[i] >> 15));
         int cnt = __builtin_popcount(val);
         cnts[i] = cnt;
      }
      if (!mp.count(cnts)) {
         mp[cnts] = mask;
      }
   }

   int ans = -1;
   for (int mask = 0; mask < (1 << 15); ++mask) {
      vector<int> cnts(N);
      for (int i = 0; i < N; ++i) {
         int val = (mask & (xorVal[i] & ((1 << 15) - 1)));
         int cnt = __builtin_popcount(val);
         cnts[i] = needCnt[i] - cnt;
      }
      if (mp.count(cnts)) {
         int mask1 = mp[cnts];
         ans = mask1 << 15 | mask;
         break;
      }
   }
   if (ans != -1) {
      ans ^= value;
   }
   cout << ans << "\n";
   return 0;
}