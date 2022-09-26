#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
int cost[N], mask[N];
int f[N][8];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      string s; cin >> cost[i] >> s;
      mask[i] = 0;
      for (char c : s) mask[i] |= 1 << (c - 'A');
   }
   memset(f, 69, sizeof f);
   f[0][0] = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 8; ++j) {
         f[i][j | mask[i]] = min(f[i][j | mask[i]], f[i - 1][j] + cost[i]);
         f[i][j]  = min(f[i][j], f[i - 1][j]);
      }
   }
   if (f[n][7] > (int) 1e9) f[n][7] = -1;
   cout << f[n][7] << '\n';
}