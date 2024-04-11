#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   string s;
   cin >> s;
   string hans;
   int l, r;
   for (l = 0, r = s.size() - 2; l + 2 <= r; l += 2, r -= 2) {
      if (s[l] == s[r] || s[l] == s[r + 1]) {
         hans += s[l];
      } else {
         hans += s[l + 1];
      }
   }
   cout << hans;
   if (l <= r) {
      cout << s[l];
   }
   cout << string(hans.rbegin(), hans.rend());
}