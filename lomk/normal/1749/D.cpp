/*input
2 2

4 6
4 6
4 2
2 3
*/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif

/**
 * Date: 14/12/2020
 * Source: kactl-duke
 * Description: Calculate a*b%c for 0<= a, b < c < 2^{63}$.
 */
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ull mod_mul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

// const int N =;
const int M = 1000005;
const int mod = 998244353;

int primes[M];
void eratosthene() {
  for (int i = 2; i <= M - 5; i++)
    if (primes[i] == 0)
      for (int j = i; j <= M - 5; j += i)
        primes[j] = i;
}

int n, m;

int calcTotalWrong() {
  int prod = 1;
  int buffer = 1;
  int ans = 0;
  loop(i, 1, n) {
    if (primes[i] == i) {
      prod *= i;
      if (prod > m)
        break;
    }
    buffer = mod_mul(buffer, (m / prod),mod);
    ans = (ans + buffer) % mod;
  }
  return ans;
}

int calcTotal() {
  int ret = 0;
  int buffer = 1;
  loop(i, 1, n) {
    buffer = mod_mul(buffer, m,mod);
    ret = (ret + buffer) % mod;
  }
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  eratosthene();

  cin >> n >> m;

  auto wrong = calcTotalWrong();
  auto total = calcTotal();

  cout << ((total + mod - wrong) % mod + mod) % mod << endl;
}