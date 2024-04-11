// giving up is cringe.
// please can someone teach me oi.

#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define double long double
#define ff first
#define ss second
const int mxN = 1e6 + 5;
int f[mxN];
int set_of(int x) {
  return (f[x] == x ? x : f[x] = set_of(f[x]));
}
void eat() {
  int n;
  std::cin >> n;
  int a[n + 1], b[n + 1], dp[n + 1] = {}, las[n + 1] = {};
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) std::cin >> b[i];
  for (int i = 1; i <= n; i++) f[i] = i;
  std::queue<int> bfs;
  f[n] = n - 1;
  bfs.push(n);
  while (bfs.size()) {
    auto e = bfs.front(), ee = e + b[e];
    bfs.pop();
    for (int nxt = set_of(ee); nxt >= ee - a[ee]; nxt = set_of(nxt - 1)) {
      bfs.push(nxt);
      dp[nxt] = dp[e] + 1;
      las[nxt] = e;
      if (!nxt) {
        int ptr = 0;
        std::vector<int> ans;
        while (ptr != n) {
          ans.push_back(ptr);
          ptr = las[ptr];
        }
        std::cout << dp[0] << "\n";
        for (int i = ans.size() - 1; i >= 0; i--) std::cout << ans[i] << " \n"[!i];
        return;
      }
      f[nxt] = set_of(nxt - 1);
    }
  }
  std::cout << "-1\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}