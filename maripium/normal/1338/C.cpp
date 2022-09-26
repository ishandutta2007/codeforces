#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ord[4] = {0, 2, 3, 1};

array<ll, 3> kth(ll k) {
   if (k == 0) return {1, 2, 3};
   ll f = 0;
   ll cur = 0;
   while (true) {
      if (cur + (1ll << f) > k) break;
      cur += (1ll << f);
      f += 2;
   }
   k -= cur;
   ll x = (1ll << f) + k;
   ll y = (1ll << (f + 1));
   f -= 2;
   while (f >= 0) {
      ll z = (k >> f) & 3;
      y += ord[z] << f;
      f -= 2;
   }
   return {x, y, x ^ y};
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   // kth(99);
   int T;
   cin >> T;
   while (T--) {
      ll z;
      cin >> z;
      --z;
      cout << kth(z / 3)[z % 3] << "\n";
   }
}