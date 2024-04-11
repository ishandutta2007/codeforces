#include <bits/stdc++.h>

using namespace std;

const double INF = 1e100;
const int N = 1111;

double dp[N];
int x[N];
int b[N];
int n;
int L;
int par[N];
vector<int> ans;

bool good(double ratio) {
  fill(dp, dp + n, INF);
  ans.clear();
  dp[0] = 0;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) {
      double cur = dp[j] + sqrt(abs(x[i] - x[j] - L)) - ratio * b[i];
      if (cur < dp[i]) {
	dp[i] = cur;
	par[i] = j;
      }
    }
  for (int i = n - 1; i != 0; i = par[i])
    ans.push_back(i);
  reverse(ans.begin(), ans.end());
  return dp[n - 1] <= 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> L;
  n++;
  for (int i = 1; i < n; i++)
    cin >> x[i] >> b[i];
  double low = 0;
  double high = 1e10;
  for (int rep = 0; rep < 100; rep++) {
    double mid = (low + high) / 2;
    if (good(mid))
      high = mid;
    else
      low = mid;
  }
  good(high);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}