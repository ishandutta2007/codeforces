#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector<ll> ans(n);
   vector<vector<ll>> a(n, vector<ll>(n));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> a[i][j];
      }
   }
   ll sqa0 = a[0][1] * a[0][2] / a[1][2];
   ans[0] = sqrtl(sqa0);
   for (int i = 1; i < n; ++i) {
      ans[i] = a[0][i] / ans[0];
   }
   for (ll v : ans) {
      cout << v << " ";
   }
}