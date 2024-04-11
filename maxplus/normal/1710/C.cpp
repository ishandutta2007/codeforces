#include <iostream>

using namespace std;

constexpr uint64_t mod = 998244353;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  uint64_t n = 0, nab = 0, abb = 0, abc = 0;
  while (cin.peek() != '\n') {
    int x = cin.get() - '0';
    abc = (abc * 6 + abb * 2 + (x? nab * 3 + n: 0)) % mod;
    abb = (abb * 4 + n * (x? 6: 2)) % mod;
    nab = (nab * 3 + n * (x? 3: 1)) % mod;
    n = (2 * n + x) % mod;
  }
  ++n;
  cout << (n * n % mod * n + mod * 99 + 6 - (abc * 6 + abb * 3 + nab * 6 + n * 7)) % mod << '\n';
}