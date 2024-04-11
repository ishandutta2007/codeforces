#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define double long double
#define ff first
#define ss second
const int mxN = 2e5 + 5;
int dp[mxN], a[mxN], b[mxN], ans;
std::vector<int> adj[mxN];
void dfs(int u) {
  int s = 0;
  for (auto i : adj[u]) {
    dfs(i);
    s += dp[i];
  }
  if (s < a[u]) {
    ans++;
    dp[u] = b[u];
  }
  else dp[u] = std::min(s, b[u]);
}
void eat() {
  // do stuff here
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 2, x; i <= n; i++) {
    std::cin >> x;
    adj[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i];
  ans = 0;
  dfs(1);
  std::cout << ans << "\n";
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t = 1;
  std::cin >> t;
  while (t--) eat();
  return 0;
}