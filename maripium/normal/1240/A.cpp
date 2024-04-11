#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      int n;
      cin >> n;
      vector<int> arr(n);
      for (int &v : arr) {
         cin >> v;
         v /= 100;
      }
      int x, a, y, b;
      cin >> x >> a >> y >> b;
      if (x < y) {
         swap(x, y);
         swap(a, b);
      }
      ll to;
      cin >> to;
      sort(arr.rbegin(), arr.rend());
      int l = 0, r = n + 1;
      while (l < r) {
         int md = (l + r) >> 1;
         // cerr << l << " " << r << "\n";
         int g = __gcd(a, b);
         ll lc = (ll) a * b / g;
         int cnt = md / lc;
         int ptr = 0;
         ll sum = 0;
         while (cnt-- > 0) {
            sum += (ll) (x + y) * arr[ptr++];
         }
         cnt = (md / a) - (md / lc);
         while (cnt-- > 0) {
            sum += (ll) x * arr[ptr++];
         }
         cnt = (md / b) - (md / lc);
         while (cnt-- > 0) {
            sum += (ll) y * arr[ptr++];
         }
         if (sum >= to) {
            r = md;
         } else {
            l = md + 1;
         }
      }
      if (l == n + 1) {
         l = -1;
      }
      cout << l << "\n";
   }
}