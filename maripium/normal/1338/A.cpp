#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<int> A(N);
      for (int &x : A) cin >> x;
      int diff = -2e9;
      int mx = A[0];
      for (int i = 1; i < N; ++i) {
         diff = max(diff, mx - A[i]);
         mx = max(mx, A[i]);
      }
      if (diff <= 0) {
         cout << 0 << "\n";
         continue;
      }
      int ans = 0;
      while ((1ll << ans) - 1 < diff) ans++;
      cout << ans << "\n";
   }
}