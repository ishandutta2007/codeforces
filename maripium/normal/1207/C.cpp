#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll inf = 1e18;

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      int n, a, b;
      cin >> n >> a >> b;
      vector<array<ll, 2>> d(n + 1);
      d[0][0] = 0;
      d[0][1] = inf;
      string s;
      cin >> s;
      for (int i = 0; i < n; ++i) {
         d[i + 1] = {inf, inf};
         if (s[i] == '0') {
            d[i + 1][0] = min(d[i][0], d[i][1] + a);
            d[i + 1][1] = min(d[i][0] + a, d[i][1]) + b;
         } else {
            d[i + 1][1] = d[i][1] + b;
         }
      }
      cout << d[n][0] + (ll) (n) * a + (ll) (n + 1) * b << "\n";
   }
}