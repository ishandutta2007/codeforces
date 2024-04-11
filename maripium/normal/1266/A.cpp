#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      string S;
      cin >> S;
      int sum = 0;
      bool has0 = false;
      int even = 0;
      for (char c : S) {
         sum += (c - '0');
         has0 |= (c == '0');
         even += ((c - '0') % 2 == 0);
      }
      if (sum % 3 == 0 && has0 && even >= 2) {
         cout << "red\n";
      } else {
         cout << "cyan\n";
      }
   }
}