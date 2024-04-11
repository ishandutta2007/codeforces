#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2020;
const int MOD = 998244353;

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

int N;
char S[MAXN];
int pref[MAXN][MAXN];
int suff[MAXN][MAXN];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> (S + 1);
   N = strlen(S + 1);
   pref[0][0] = 1;
   for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < i; ++j) {
         if (S[i] != ')') {
            pref[i][j + 1] = add(pref[i][j + 1], pref[i - 1][j]);
         }
         if (S[i] != '(') {
            pref[i][j] = add(pref[i][j], pref[i - 1][j]);
         }
      }
   }
   suff[N + 1][0] = 1;
   for (int i = N; i > 0; --i) {
      for (int j = 0; j <= N; ++j) {
         if (S[i] != '(') {
            suff[i][j + 1] = add(suff[i][j + 1], suff[i + 1][j]);
         }
         if (S[i] != ')') {
            suff[i][j] = add(suff[i][j], suff[i + 1][j]);
         }
      }
   }
   for (int i = 1; i <= N + 1; ++i) {
      for (int z = N; z >= 0; --z) {
         suff[i][z] = add(suff[i][z], suff[i][z + 1]);
      }
   }
   int ans = 0;
   for (int z = 1; z <= (N / 2); ++z) {
      int cur = 0;
      for (int i = 1; i <= N; ++i) {
         if (S[i] != ')') {
            cur = add(cur, mul(pref[i - 1][z - 1], suff[i + 1][z]));
         }
      }
      // cerr << cur << "\n";
      ans = add(ans, cur);
   }
   cout << ans << "\n";
   return 0;
}