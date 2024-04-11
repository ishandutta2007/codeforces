#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, q;
pair<int, int> ans[N];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> q;
   deque<int> a;
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a.push_back(x);
   }
   for (int i = 1; i <= n; ++i) {
      int x = a[0];
      int y = a[1];
      a.pop_front();
      a.pop_front();
      ans[i] = {x, y};
      if (x > y) {
         a.push_front(x);
         a.push_back(y);
      } else {
         a.push_front(y);
         a.push_back(x);
      }
   }
   // for (int x : a) cout << x << " ";
   // cout << "\n";
   while (q--) {
      long long m;
      cin >> m;
      if (m <= n) {
         cout << ans[m].first << ' ' << ans[m].second << '\n';
      } else {
         int len = (m - 2) % (n - 1);
         cout << a[0] << ' ' << a[len + 1] << "\n";
      }
   }
}