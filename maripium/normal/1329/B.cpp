#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
   int D, MOD;
   cin >> D >> MOD;
   int N = __lg(D);
   int ans = 0;
   int sum = 0;
   for (int i = 0; i <= N; ++i) {
      int cnt = min(D + 1, (1 << (i + 1))) - (1 << i);
      int cur = ll(sum + 1) * cnt % MOD;
      ans += cur;
      if (ans >= MOD) ans -= MOD;
      sum += cur;
      if (sum >= MOD) sum -= MOD;
   }
   cout << ans << "\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      solve();
   }
}