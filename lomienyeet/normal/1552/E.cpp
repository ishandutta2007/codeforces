#include <iostream>
void eat() {
  int n, k;
  std::cin >> n >> k;
  int arr[n * k + 1], vis[n + 1] = {}, las[n + 1], z = (n + k - 2) / (k - 1), cnt = 0;
  for (int i = 1; i <= n * k; i++) std::cin >> arr[i];
  std::pair<int, int> ans[n + 1];
  for (int i = 1; i <= n; i++) las[i] = -1;
  for (int i = 1; i <= n * k; i++) {
    if (vis[arr[i]]) continue;
    if (las[arr[i]] != -1) {
      cnt++;
      ans[arr[i]] = {las[arr[i]], i};
      vis[arr[i]] = 1;
    }
    if (cnt == z) {
      cnt = 0;
      for (int i = 1; i <= n; i++) las[i] = -1;
    }
    else las[arr[i]] = i;
  }
  for (int i = 1; i <= n; i++) std::cout << ans[i].first << " " << ans[i].second << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}