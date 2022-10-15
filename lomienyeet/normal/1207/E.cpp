/*
reading problem: 22:04 - 22:06
thinking: 22:06 - 22:17
coding: 22:17 - 22:19
debugging: hopefully none
*/

#include <iostream>
int32_t main() {
  std::cout << "? ";
  for (int i = 0; i < 100; i++) std::cout << i << " ";
  std::cout << "\n";
  fflush(stdout);
  int z, w, ans = 0;
  std::cin >> z;
  std::cout << "? ";
  for (int i = 1; i <= 100; i++) std::cout << i * 128 << " ";
  std::cout << "\n";
  fflush(stdout);
  std::cin >> w;
  for (int i = 0; i < 14; i++) {
    if (i < 7) {
      if (w & (1 << i)) ans |= (1 << i);
    }
    else {
      if (z & (1 << i)) ans |= (1 << i);
    }
  }
 std::cout << "! " << ans << "\n";
 fflush(stdout);
}