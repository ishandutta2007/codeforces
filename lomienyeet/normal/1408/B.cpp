#include <iostream>
void eat() {
  int n, k, weeee, ans = 0;
  std::cin >> n >> k >> weeee;
  for (int i = 1, x; i < n; i++) {
    std::cin >> x;
    ans += (x != weeee);
    weeee = x;
  }
  if (k == 1 && ans) std::cout << "-1\n";
  else if (!ans) std::cout << "1\n";
  else std::cout << (ans - 1) / (k - 1) + 1 << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}