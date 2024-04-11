#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int N;
int A[MAXN];
int dp[MAXN][MAXN][2];

void mnm(int &x, int y) {
   x = min(x, y);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 1; i <= N; ++i) {
      cin >> A[i];
   }
   memset(dp, 69, sizeof dp);
   dp[0][0][0] = 0;
   dp[0][0][1] = 0;
   for (int ps = 1; ps <= N; ++ps) {
      for (int numOdd = 0; numOdd < ps; ++numOdd) {
         int numEven = ps - 1 - numOdd;
         for (int z = 0; z < 2; ++z) {
            if (dp[ps - 1][numOdd][z] > N) continue;
            for (int toAdd = 0; toAdd < 2; ++toAdd) {
               if (A[ps] && ((A[ps] + toAdd) & 1)) continue;
               int curCost = toAdd != z;
               mnm(dp[ps][numOdd + toAdd][toAdd], dp[ps - 1][numOdd][z] + curCost);
            }
         }
      }
   }
   cout << min(dp[N][(N + 1) / 2][0], dp[N][(N + 1) / 2][1]);
}