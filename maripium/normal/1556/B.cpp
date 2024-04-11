#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(N); for (int &a : A) cin >> a;
      int cnt = 0;
      vector<int> gaps;
      for (int i = 0; i <= N; ++i) {
         if (i == N || A[i] % 2 == 0) {
            gaps.push_back(cnt);
            cnt = 0;
         } else {
            cnt++;
         }
      }
      int N0 = int(gaps.size()) - 1;
      int N1 = N - N0;
      auto go = [&](vector<int> mgaps) {
         int64_t ans = 0;
         int sg = 0;
         int smg = 0;
         for (int i = 0; i < int(mgaps.size()); ++i) {
            sg += gaps[i];
            smg += mgaps[i];
            ans += abs(sg - smg);
         }
         return ans;
      };
      if (abs(N0 - N1) >= 2) {
         cout << "-1\n";
         continue;
      }
      int64_t ans;
      if (N0 == N1 + 1) {
         vector<int> mgaps(gaps.size(), 1);
         mgaps[0] = mgaps.back() = 0;
         ans = go(mgaps);
      } else if (N0 + 1 == N1) {
         vector<int> mgaps(gaps.size(), 1);
         ans = go(mgaps);
      } else {
         assert(N0 == N1);
         vector<int> mgaps(gaps.size(), 1);
         mgaps[0] = 0;
         ans = go(mgaps);
         mgaps[0] = 1;
         mgaps.back() = 0;
         ans = min(ans, go(mgaps));
      }
      cout << ans << '\n';
   }
   return 0;
}