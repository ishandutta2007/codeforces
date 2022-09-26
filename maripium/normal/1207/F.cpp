#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 500500;
const int S = 705;

int a[N];
int f[S][S];

int main() {
   ios_base::sync_with_stdio(false);
   int q;
   cin >> q;
   while (q--) {
      int op, x, y;
      cin >> op >> x >> y;
      if (op == 1) {
         a[x] += y;
         for (int i = 1; i < S; ++i) {
            f[i][x % i] += y;
         }
      } else {
         int ans;
         if (x < S) {
            ans = f[x][y];
         } else {
            ans = 0;
            for (int i = y; i < N; i += x) {
               ans += a[i];
            }
         }
         cout << ans << "\n";
      }
   }
}