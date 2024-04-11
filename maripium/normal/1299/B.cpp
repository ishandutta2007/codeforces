#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define x first
#define y second
using pt = pair<int, int>;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<pt> ps(N);
   for (int i = 0; i < N; ++i) cin >> ps[i].x >> ps[i].y;
   if (N & 1) {
      cout << "NO\n";
      return 0;
   }
   for (int i = 0; i < N; ++i) {
      ll x = 0;
      ll y = 0;
      int j = (i + 1) % N;
      int k = (i + (N / 2)) % N;
      int l = (k + 1) % N;
      int sgn = 1;
      for (int z : {i, j, k, l}) {
         x += sgn * ps[z].x;
         y += sgn * ps[z].y;
         sgn *= -1;
      }
      if (x || y) {
         cout << "NO\n";
         return 0;
      }
   }
   cout << "YES\n";
}