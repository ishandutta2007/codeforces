#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

pair<vector<int>, vector<int>> primes_lpf(const int n) {
  vector<int> primes; primes.reserve(n / 10);
  vector<int> lpf(n + 1);
  for (int i = 2; i <= n; i += 2) lpf[i] = 2;
  for (int i = 3; i <= n; i += 6) lpf[i] = 3;
  if (2 <= n) primes.push_back(2);
  if (3 <= n) primes.push_back(3);
  // 5 * x <= n, x <= floor(n / 5)
  const int n5 = n / 5;
  int x = 5;
  char add_next = 2;
  for (; x <= n5; x += add_next, add_next ^= 2 ^ 4) {
    int px = lpf[x];
    if (px == 0) {
      lpf[x] = px = x;
      primes.push_back(x);
    }
    for (int i = 2;; ++i) {
      int q = primes[i];
      int y = q * x;
      if (y > n) break;
      lpf[y] = q;
      if (q == px) break;
    }
  }
  for (; x <= n; x += add_next, add_next ^= 2 ^ 4) {
    if (lpf[x] == 0) {
      lpf[x] = x;
      primes.push_back(x);
    }
  }
  return {move(primes), move(lpf)};
}

constexpr int PSIZE = 100010;
auto [primes, lpf] = primes_lpf(PSIZE);

vector<int> build_phi_table(const int n) {
  assert(n < (int)lpf.size());
  vector<int> res(n + 1);
  res[1] = 1;
  for(int p: primes) {
    if (p > n) break;
    res[p] = p - 1;
  }
  for(int x = 2; x <= n; x++) {
    int px = lpf[x];
    for(int q: primes) {
      int y = q * x;
      if (y > n) break;
      if (q != px) {
        res[y] = res[x] * (q - 1);
      } else {
        res[y] = res[x] * q;
        break;
      }
    }
  }
  return res;
}

auto phi = build_phi_table(100010);

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0;
  for(int g = 1; g <= n; g++) {
    for(int c = 2; g * c < n; c++) {
      ans += phi[c] * lcm<ll>(g, n - g * c);
    }
  }
  cout << ans % 1000000007 << '\n';
}