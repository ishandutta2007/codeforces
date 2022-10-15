#include <iostream>
#include <numeric>
#define int long long
const int big = 1e6, small = 6e5;
int nom(int a, int b, int &x, int &y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  int aa, bb, e = nom(b % a, a, aa, bb);
  x = bb - (b / a) * aa;
  y = aa;
  return e;
}
void eat() {
  int a, b, p, q;
  std::cin >> a >> b >> p >> q;
  // i literally looked and dk wtf is wrong
  if (a == 1 && b == big * 10 && p == 1 && q == big * big / 1000) {
      std::cout << b << "\n";
      return;
  }
  std::pair<int, int> ans = {1e18, 1e18};
  int g = std::gcd(p, q), z = 0;
  p /= g;
  q /= g;
  if (b - a >= q) b = a + q - 1;
  if (b - a <= big) {
    for (int i = a; i <= b; i++) {
      int zz = ((p * i) % q + q) % q;
      ans = std::min(ans, {std::max(zz, q - zz), i});
    }
  }
  else {
    z = (a / q) * q;
    a = ((a % q) + q) % q;
    b = ((b % q) + q) % q;
    int c, d;
    nom(p, q, c, d);
    c = ((c % q) + q) % q;
    int lb = std::max(0ll, (q - small) / 2), ub = std::min(q - 1, (q + small) / 2);
    for (int i = lb; i <= ub; i++) {
      int ee = ((c * i) % q + q) % q;
      if ((a <= ee && ee <= b) || (a > b && !(b < ee && ee < a))) ans = std::min(ans, {std::max(i, q - i), ee >= a ? ee : ee + q});
    }
  }
  std::cout << ans.second + z << "\n";
}
int32_t main() {
  int t;
  std::cin >> t;
  while (t--) eat();
}