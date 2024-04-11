#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   // cin >> T;
   T = 1;
   while (T--) {
      string S;
      cin >> S;
      int N = S.size();
      ll ans = 0;
      for (char c = 'a'; c <= 'z'; ++c) {
         ll cur2 = 0;
         for (char d = 'a'; d <= 'z'; ++d) {
            int cnts = 0;
            ll cur = 0;
            cur2 = 0;
            for (char z : S) {
               if (d == z) cur += cnts;
               if (c == z) cur2++, cnts++;
            }
            ans = max(ans, cur);
            ans = max(ans, cur2);
         }
      }
      cout << ans << "\n";
   }
}