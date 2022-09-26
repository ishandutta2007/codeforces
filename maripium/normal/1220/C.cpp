#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   string s;
   cin >> s;
   char mn = 'z' + 1;
   for (char c : s) {
      if (c > mn) {
         cout << "Ann\n";
      } else {
         cout << "Mike\n";
      }
      mn = min(mn, c);
   }
}