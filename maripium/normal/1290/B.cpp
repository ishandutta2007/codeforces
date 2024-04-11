#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   string S;
   cin >> S;
   int N = S.size();
   vector<array<int, 26>> pref(N + 1);
   pref[0] = {};
   for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i];
      pref[i + 1][S[i] - 'a']++;
   }
   int Q;
   cin >> Q;
   while (Q--) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      set<int> s;
      for (int z = 0; z < 26; ++z) {
         if (pref[r + 1][z] - pref[l][z]) {
            s.emplace(z);
         }
      }
      if (s.size() > 2) {
         cout << "Yes\n";
      } else if (s.size() == 1) {
         cout << (l == r ? "Yes\n" : "No\n");
      } else {
         assert(s.size() == 2);
         cout << (S[l] == S[r] ? "No\n" : "Yes") << "\n";
      }
   }
}