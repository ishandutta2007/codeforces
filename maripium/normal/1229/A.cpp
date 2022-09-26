#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector<pair<ll, int>> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
   }
   for (int i = 0; i < n; ++i) {
      cin >> a[i].second;
   }
   vector<bool> was(n);
   sort(a.begin(), a.end());
   // reverse(a.begin(), a.end());
   ll ans = 0;
   for (int i = n - 1; i >= 0; --i) {
      if (was[i]) continue;
      if (i == 0 || a[i].first > a[i - 1].first) continue;
      for (int j = 0; j < n; ++j) {
         if (was[j]) continue;
         if ((a[i].first & a[j].first) == a[j].first) {
            was[j] = true;
            ans += a[j].second;
         }
      }
   }
   cout << ans << "\n";
}