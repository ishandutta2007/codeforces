#include <bits/stdc++.h>

using namespace std;

const int N = 10100;

int n, m;
bitset<N> one;
bitset<N> f[50], g[50];

int main() {
   ios_base::sync_with_stdio(false);
   int m, n; cin >> m >> n;
   for (int i = 0; i < n; ++i) one.set(i);
   for (int i = 0; i < m; ++i) {
      int sz; cin >> sz;
      while (sz--) {
         int x; cin >> x;
         --x; f[i].set(x);
      }
      g[i] = one ^ f[i];
   }
   for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
         if ((g[j] & f[i]) == f[i]) {
            return cout << "impossible\n",0;
         }
      }
   }
   cout << "possible\n";
}