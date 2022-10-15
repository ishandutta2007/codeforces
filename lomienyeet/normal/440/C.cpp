#include <iostream>
#include <algorithm>
long long fuck[73];
long long eat(long long a, long long b) {
  if (!a) return a;
  if (fuck[b] > a) {
    long long z = eat(a, b - 1);
    if (fuck[b] - a < a) z = std::min(z, eat(fuck[b] - a, b - 1) + b);
    return z;
  }
  return eat(a - fuck[b], b) + b;
}
int32_t main(){
  long long n, wa = 1;
  std::cin >> n;
  for (long long i = 1; i <= 16; i++) {
    fuck[i] = wa;
    (wa *= 10) += 1;
  }
  std::cout << eat(n, 16) << "\n";
}