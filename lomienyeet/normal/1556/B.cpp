#include <iostream>
const int mxN = 4e5 + 5;
int n, arr[mxN];
int nom() {
  int ans = 0, ptr = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] & 1) {
      if (ptr < 0) ans += -ptr;
      ptr++;
    }
    else {
      if(ptr > 0) ans += ptr - 1;
      ptr--;
    }
  }
  if (ptr < 0 || ptr > 1) return 2e9;
  return ans;
}
void eat() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> arr[i];
  int a = nom();
  for (int i = 1; i <= n; i++) arr[i] ^= 1;
  a = std::min(a, nom());
  std::cout << (a > 15e8 ? -1 : a) << "\n";
}
int32_t main() {
  int t = 1;
  std::cin >> t;
  while (t--) eat();
}