#include <iostream>

int main() {
  int t, n, r, d;
  std::cin >> t;
  while (t--) {
    r = d = 0;
    std::string s;
    std::cin >> n >> s;
    for (auto c: s)
      ++(c == s[0]? r: d);
    int64_t p = s.find(s[0] ^ 22);
    std::cout << (d? p + (n - p) * n - (r - p) * d: n) << '\n';
  }
}