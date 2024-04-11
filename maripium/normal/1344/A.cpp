#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<int> A(N);
      for (int &x : A) cin >> x;
      vector<int> deg(N);
      for (int i = 0; i < N; ++i) {
         int nxt = (i + A[i]) % N;
         if (nxt < 0) nxt += N;
         deg[nxt]++;
      }
      bool ans = true;
      for (int i = 0; i < N; ++i) ans &= (deg[i] == 1);
      cout << (ans ? "YES" : "NO") << "\n";
   }
}