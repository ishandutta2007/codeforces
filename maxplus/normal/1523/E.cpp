#include <iostream>

using namespace std;

constexpr int mod = 1e9 + 7, N = 1e5 + 1;

int fpow(int a, int p) {
  int64_t res = 1, d = a;
  while (p) {
    if (p & 1) {
      (res *= d) %= mod;
    }
    (d *= d) %= mod;
    p >>= 1;
  }
  return res;
}

int mul(int64_t a, int b) {
  return a * b % mod;
}

int div_(int64_t a, int b) {
  return a * fpow(b, mod - 2) % mod;
}

int fact[N];

void precalc() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
}

int main()
{
  precalc();
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int res = 1;
    for (int am = 1; am <= (n - 1) / k + 1; ++am) {
      (res += div_(mul(fact[n - (am - 1) * (k - 1)], fact[n - am]), mul(fact[n - (am - 1) * k - 1], fact[n]))) %= mod;
    }
    cout << res << '\n';
  }
  return 0;
}