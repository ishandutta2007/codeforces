#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int64_t n, ba = 0, bb = 0;
  cin >> n;
  for (int64_t i = 1; i * i <= n; ++i) {
    if (n % i == 0 && gcd(i, n / i) == 1) {
      ba = i, bb = n / i;
    }
  }
  cout << ba << ' ' << bb << '\n';
}