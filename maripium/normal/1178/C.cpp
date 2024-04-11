#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   int ans = 1;
   for (int i = 1; i <= n + m; ++i) {
      ans = ans + ans;
      if (ans >= 998244353) ans -= 998244353;
   }
   cout << ans << "\n";
}