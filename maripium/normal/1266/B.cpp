#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      ll X;
      cin >> X;
      if (X % 14 <= 6 && X >= 15 && X % 14 > 0) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }
}