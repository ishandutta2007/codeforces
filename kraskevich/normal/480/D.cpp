#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int mem[N][N];
int dp[N];
int in[N];
int out[N];
int v[N];
int s[N];
int w[N];
int n;
vector<int> at_pos[N];

int calc(int i, int have) {
  if (have < 0)
    return 0;
  if (mem[i][have] >= 0)
    return mem[i][have];
  mem[i][have] = v[i];
  int haveNow = min(have, s[i]);
  for (int x = in[i]; x <= out[i]; x++)
    for (int idx : at_pos[x]) 
      if (idx != i && out[idx] <= out[i])
	calc(idx, haveNow - w[idx]);
  for (int x = in[i]; x <= out[i]; x++)
    dp[x] = 0;
  for (int x = in[i]; x <= out[i]; x++) {
    dp[x + 1] = max(dp[x + 1], dp[x]);
    for (int idx : at_pos[x])
      if (idx != i && out[idx] <= out[i])
	dp[out[idx]] = max(dp[out[idx]], dp[x] + calc(idx, haveNow - w[idx])); 
  }
  mem[i][have] += dp[out[i]];
  return mem[i][have];
}

int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      mem[i][j] = -1;
  int S;
  cin >> n >> S;
  in[0] = 0;
  out[0] = 2 * n + 1;
  w[0] = 0;
  s[0] = S;
  v[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> in[i] >> out[i] >> w[i] >> s[i] >> v[i];
    at_pos[in[i]].push_back(i);
  }
  cout << calc(0, S) << endl;
  return 0;
}