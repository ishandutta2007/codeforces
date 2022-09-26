#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      int a, b, n;
      cin >> a >> b >> n;
      array<int, 3> as = {a, b, a ^ b};
      cout << as[n % 3] << "\n";
   }
}