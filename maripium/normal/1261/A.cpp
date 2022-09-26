#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N, K;
      string S;
      cin >> N >> K >> S;
      string T;
      int sz = N;
      --K;
      while (K--) {
         sz -= 2;
      }
      for (int i = 0; i < sz / 2; ++i) {
         T += '(';
      }
      for (int i = sz / 2; i < sz; ++i) {
         T += ')';
      }
      for (int i = sz; i < N; i += 2) {
         T += '(';
         T += ')';
      }
      vector<pair<int, int>> ans;
      for (int i = 0; i < N; ++i) {
         if (S[i] != T[i]) {
            for (int j = i; j < N; ++j) {
               if (S[j] == T[i]) {
                  ans.emplace_back(i, j);
                  reverse(S.begin() + i, S.begin() + j + 1);
                  break;
               }
            }
         }
      }
      assert(S == T);
      cout << ans.size() << "\n";
      for (auto p : ans) {
         cout << p.first + 1 << " " << p.second + 1 << "\n";
      }
   }
}