#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define N 1000000

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c - '0';
  x *= sig;
}

using namespace std;
int main() {
  vector<int> primes = {2, 3, 5, 7, 11, 13};
  for (int i = 17; i < N; i += 2) {
    bool is_prime = true;
    for (int j = 0; primes[j] * primes[j] <= i; ++j) {
      if (i % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      primes.emplace_back(i);
  }
  int t;
  read(t);
  string output;
  while (t--) {
    int n;
    read(n);
    if (n == 1)
      output += "1\n";
    else {
      int h = sqrt(n);
      int a = upper_bound(primes.begin(), primes.end(), h) - primes.begin();
      int b = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
      output += to_string(b - a + 1) + "\n";
    }
  }
  printf("%s", output.c_str());
}