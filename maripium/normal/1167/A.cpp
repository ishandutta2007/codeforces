#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);

   int tt; cin >> tt;

   while (tt--) {
      int n; string s; cin >> n >> s;
      if (s.size() < 11) {
         cout << "NO\n";
         continue;
      }
      for (int i = 0; i < 10; ++i) s.pop_back();
      cout << (count(s.begin(), s.end(), '8') ? "YES\n" : "NO\n");
   }
}