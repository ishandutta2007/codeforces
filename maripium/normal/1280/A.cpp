#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int add(int x, int y) {
   x += y;
   if (x >= MOD) {
      x -= MOD;
   }
   return x;
}

int sub(int x, int y) {
   x -= y;
   if (x < 0) {
      x += MOD;
   }
   return x;
}

int mul(int x, int y) {
   return (long long) x * y % MOD;
}

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int X;
      string S;
      cin >> X >> S;
      int curLen = S.size();
      for (int i = 1; i <= X; ++i) {
         int suffLen = sub(curLen, i);
         int N = (S[i - 1] - '0') - 1;
         if (S.size() < X) {
            string suff = S.substr(i);
            // cerr << suff << "\n";
            for (int z = 0; z < N; ++z) {
               S += suff;
            }
            if (S.size() > X) {
               S.resize(X);
            }
         }
         curLen = add(curLen, mul(N, suffLen));
      }
      cout << curLen << "\n";
   }
}