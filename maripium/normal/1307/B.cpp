#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N, X;
      cin >> N >> X;
      auto cost = [&](int z) {
         int ans = (X + z - 1) / z;
         if (ans == 1 && z > X) ans++;
         return ans;
      };
      int ans = X + 5;
      while (N--) {
         int x;
         cin >> x;
        ans = min(ans, cost(x));
      }
      cout << ans << "\n";
   }
}