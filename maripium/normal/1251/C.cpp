#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      string S;
      cin >> S;
      string E;
      string O;
      for (char c : S) {
         if (c & 1) {
            O.push_back(c);
         } else {
            E.push_back(c);
         }
      }
      int ie = 0;
      int io = 0;
      S.clear();
      while (ie < E.size() && io < O.size()) {
         S.push_back((E[ie] < O[io] ? E[ie++] : O[io++]));
      }
      while (ie < E.size()) {
         S.push_back(E[ie++]);
      }
      while (io < O.size()) {
         S.push_back(O[io++]);
      }
      cout << S << "\n";
   }
}