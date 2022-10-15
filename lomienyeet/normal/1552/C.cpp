#include <iostream>
#include <algorithm>
void eat() {
  int n, k, ans = 0;
  std::cin >> n >> k;
  std::vector<std::pair<int, int> > v;
  bool vis[n * 2 + 1] = {};
  for (int i = 1, a, b; i <= k; i++) {
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    vis[a] = vis[b] = 1;
    v.push_back({a, b});
  }
  std::vector<int> aa;
  for (int i = 1; i <= n * 2; i++) {
    if (!vis[i]) aa.push_back(i);
  }
  for (int i = 0; i < aa.size() / 2; i++) v.push_back({aa[i], aa[i + aa.size() / 2]});
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) ans += ((v[j].first < v[i].first && v[i].first < v[j].second && v[j].second < v[i].second) || (v[i].first < v[j].first && v[j].first < v[i].second && v[i].second < v[j].second));
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}