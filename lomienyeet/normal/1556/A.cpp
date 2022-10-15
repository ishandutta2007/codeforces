#include <iostream>
#include <cmath>
void eat() {
  int a, b;
  std::cin >> a >> b;
  if (abs(a + b) & 1) {
    std::cout << "-1\n";
    return;
  }
  if (!a && !b) {
    std::cout << "0\n";
    return;
  }
  else std::cout << 1 + (a != b) << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}