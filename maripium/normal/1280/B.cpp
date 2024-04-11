#include <bits/stdc++.h>

using namespace std;

int solve() {
   int N, M;
   cin >> N >> M;
   vector<string> S(N);
   bool hasA = false;
   bool hasP = false;
   for (int i = 0; i < N; ++i) {
      cin >> S[i];
      for (int j = 0; j < M; ++j) {
         hasA |= (S[i][j] == 'A');
         hasP |= (S[i][j] == 'P');
      }
   }
   if (!hasA) {
      return -1;
   } else if (!hasP) {
      return 0;
   }
   {
      bool flag = true;
      for (int i = 0; i < M; ++i) {
         flag &= (S[0][i] == 'A');
      }
      if (flag) {
         return 1;
      }
   }
   {
      bool flag = true;
      for (int i = 0; i < M; ++i) {
         flag &= (S[N - 1][i] == 'A');
      }
      if (flag) {
         return 1;
      }
   }
   {
      bool flag = true;
      for (int i = 0; i < N; ++i) {
         flag &= (S[i][0] == 'A');
      }
      if (flag) {
         return 1;
      }
   }
   {
      bool flag = true;
      for (int i = 0; i < N; ++i) {
         flag &= (S[i][M - 1] == 'A');
      }
      if (flag) {
         return 1;
      }
   }
   {
      bool flag = true;
      for (int i = 0; i < N; ++i) {
         flag &= (S[i][0] == 'P');
         flag &= (S[i][M - 1] == 'P');
      }
      for (int i = 0; i < M; ++i) {
         flag &= (S[0][i] == 'P');
         flag &= (S[N - 1][i] == 'P');
      }
      if (flag) {
         return 4;
      }
   }
   for (int i = 0; i < N; ++i) {
      bool flag = true;
      for (int j = 0; j < M; ++j) {
         flag &= (S[i][j] == 'A');
      }
      if (flag) {
         return 2;
      }
   }
   for (int j = 0; j < M; ++j) {
      bool flag = true;
      for (int i = 0; i < N; ++i) {
         flag &= (S[i][j] == 'A');
      }
      if (flag) {
         return 2;
      }
   }
   if (S[0][0] == 'P' && S[0][M - 1] == 'P' && S[N - 1][0] == 'P' && S[N - 1][M - 1] == 'P') {
      return 3;
   }
   return 2;
}

int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--) {
      int ans = solve();
      if (ans == -1) {
         cout << "MORTAL\n";
      } else {
         cout << ans << "\n";
      }
   }
}