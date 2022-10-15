#include <iostream>
void eat() {
  int n;
  std::cin >> n;
  int a[n + 1], b[n + 1], c[n + 1];
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) std::cin >> b[i];
  for (int i = 1; i <= n; i++) std::cin >> c[i];
  int ans[n + 1];
  ans[1] = a[1];
  for (int i = 2; i < n; i++) {
    if (ans[i - 1] != a[i]) ans[i] = a[i];
    else if (ans[i - 1] != b[i]) ans[i] = b[i];
    else ans[i] = c[i];
  }
  if (ans[1] != a[n] && ans[n - 1] != a[n]) ans[n] = a[n];
  else if (ans[1] != b[n] && ans[n - 1] != b[n]) ans[n] = b[n];
  else ans[n] = c[n];
  for (int i = 1; i <= n; i++) std::cout << ans[i] << " ";
  std::cout << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}