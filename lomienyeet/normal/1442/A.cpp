#include <iostream>
void solve() {
  int n;
  std::cin >> n;
  int arr[n + 1], ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> arr[i];
    if (i > 1 && arr[i - 1] > arr[i]) ans += arr[i-1] - arr[i];
  }
  std::cout << (arr[1] >= ans ? "YES\n" : "NO\n");
}
int32_t main() {
  int t;
  std::cin >> t;
  while (t--) solve();
}