#include <bits/stdc++.h>

using namespace std;

const string wow = "vvovv";

int main() {
   ios_base::sync_with_stdio(false);
   string s;
   cin >> s;
   int n = s.size();
   vector<vector<long long>> dp(n + 5, vector<long long>(4));
   dp[0][0] = 1;
   for (int i = 0; i < n; ++i) {
      for (int j = 0;j  < 4; ++j) {
         dp[i + 1][j] += dp[i][j];
      }
      if (s[i] == 'o') {
         dp[i + 1][2] += dp[i][1];
      } else if (i < n - 1 && s[i + 1] == 'v') {
         dp[i + 2][1] += dp[i][0];
         dp[i + 2][3] += dp[i][2];
      }
   }
   cout << dp[n][3];
}