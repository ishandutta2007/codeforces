#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, K;
   cin >> N >> K;
   vector<bool> bad(N, false);
   auto Ask = [&](int x) {
      cout << "? " << x + 1 << endl;
      char ans; cin >> ans;
      if (ans == 'Y') bad[x] = true;
   };
   auto Reset = [&]() {
      cout << "R" << endl;
   };
   vector<bool> ans(N, false);
   if (K == 1) {
      for (int i = 0; i < N; ++i) {
         for (int j = i + 1; j < N; ++j) {
            Reset(); Ask(i); Ask(j);
         }
      }
   } else {
      int halfK = K / 2;
      int numBlocks = N / halfK;
      for (int diff = 0; diff < numBlocks; ++diff) {
         for (int start = 0; start < diff; ++start) {
            Reset();
            if (start + diff >= numBlocks) continue;
            for (int cur = start; cur < numBlocks; cur += diff) {
               for (int z = 0; z < halfK; ++z) {
                  Ask(cur * halfK + z);
               }
            }
         }
      }
   }
   cout << "! " << count(bad.begin(), bad.end(), false) << endl;
}