#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   auto up = [&](int x) {
      if (x > 0) {
         return (x + 1) / 2;
      } else {
         return x / 2;
      }
   };
   auto down = [&](int x) {
      assert(x % 2);
      return x - up(x);
   };
   int n;
   cin >> n;
   int cnt = 0;
   while (n--) {
      int x;
      cin >> x;
      if (x % 2 == 0) {
         cout << up(x) << "\n";
      } else {
         if (cnt) {
            cout << up(x) << "\n";
         } else {
            cout << down(x) << "\n";
         }
         cnt ^= 1;
      }
   }
}