#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, k;
int m;
ll a[100100];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m >> k;
   for (int i = 1; i <= m; ++i) {
      cin >> a[i];
      --a[i];
   }
   int ans = 0;
   int l = 1;
   while (l <= m) {
      ans++;
      int r = l;
      while (r + 1 <= m && ((a[r + 1] - l + 1) / k) == ((a[l] - l + 1) / k)) {
         r++;
      }
      l = r + 1;
   }
   cout << ans << "\n";
}