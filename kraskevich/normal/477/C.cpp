#include <bits/stdc++.h>

using namespace std;

const int N = 2222;

int dp[N][N];
string s, p;
int go[N][26];
int pi[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> s >> p;
  int plen = p.length();
  int n = s.length();
  for (int i = 1, k = 0; i < p.length(); i++) {
    while (k > 0 && p[k] != p[i])
      k = pi[k - 1];
    if (p[i] == p[k])
      k++;
    pi[i] = k;
  }
  for (int i = 0; i < p.length(); i++)
    for (int c = 0; c < 26; c++) {
      int f = i;
      while (f > 0 && p[f] - 'a' != c)
	f = pi[f - 1];
      if (p[f] - 'a' == c)
	f++;
      go[i][c] = f;
    }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = N;
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (int pos = 0; pos < n; pos++)
    for (int len = 0; len <= n; len++) {
      if (dp[pos][len] == N)
	continue;
      dp[pos + 1][len] = min(dp[pos + 1][len], dp[pos][len] + 1);
      int to = len / plen * plen + go[len % plen][s[pos] - 'a'];
      dp[pos + 1][to] = min(dp[pos + 1][to], dp[pos][len]);
    } 
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
  vector<int> res(n + 1, 0);
  for (int len = 0; len <= n; len++) {
    int low = dp[n][len];
    int rem = n - len;
    for (int i = low; i <= n; i++) {
      int cnt = (len - max(0, i - rem)) / plen;
      res[i] = max(res[i], cnt);
    }
  }
  for (int i = 0; i <= n; i++)
    cout << res[i] << " ";
  return 0;
}