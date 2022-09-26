#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      int cnt0 = 0;
      int cnt1 = 0;
      int cnte = 0;
      int cnto = 0;
      for (int i = 0; i < N; ++i) {
         string S;
         cin >> S;
         cnte += (S.size() % 2 == 0);
         cnto += (S.size() % 2 == 1);
         for (char c : S) {
            cnt0 += c == '0';
            cnt1 += c == '1';
         }
      }
      if (cnte == N && cnt0 % 2 == 1) {
         cout << N - 1 << "\n";
      } else {
         cout << N << "\n";
      }
   }
}