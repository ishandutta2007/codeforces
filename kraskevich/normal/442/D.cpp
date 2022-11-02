#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
const int N = (int)2e6;

struct TwoMax {
  int m1;
  int m2;

  TwoMax(): m1(-1), m2(-1) {}

  void add(int val) {
    if (val >= m1) {
      m2 = m1;
      m1 = val;
    }
    else if (val > m2) {
      m2 = val;
    }
  }
};

int par[N];
int dp[N];
TwoMax kids[N];
int res = 0;

void go(int v) {
  if (v == 0)
    return;
  int new_dp = max(1, max(kids[v].m1, kids[v].m2 + 1));
  res = max(res, new_dp);
  if (new_dp == dp[v])
    return;
  int p = par[v];
  if (dp[v] == kids[p].m1)
      kids[p].m1 = new_dp;
  else if (dp[v] == kids[p].m2)
    kids[p].m2 = new_dp;
  else
    kids[p].add(new_dp);
  go(p);
  dp[v] = new_dp;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    par[i] = p - 1;
    go(i);
    cout << res << " ";
  }
  return 0;
}