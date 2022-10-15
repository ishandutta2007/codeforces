#include <iostream>
#include <algorithm>
#define int long long
void eat() {
  int n;
  std::cin >> n;
  int arr[n + 2] = {}, ans = 0;
  for (int i = 1; i <= n; i++) std::cin >> arr[i];
  for (int i = 1; i <= n; i += 2) {
    int z = 0, mini = 0;
    for (int j = i + 1; j <= n; j += 2) {
      int now = 0, zz = z - mini;
      if (j == i + 1) now = std::min(arr[i], arr[j]);
      else now = std::max(std::min(arr[i] + mini + 1 - std::max(-zz, 0ll), arr[j] + 1 - std::max(zz, 0ll)), 0ll);
      ans += now;
      z -= arr[j];
      mini = std::min(mini, z);
      z += arr[j + 1];
    }
  }
  std::cout << ans << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}