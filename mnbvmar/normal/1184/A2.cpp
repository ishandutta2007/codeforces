#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define sim template<class c
#define ris return *this
#define dor > debug & operator<<
#define eni(x) sim>typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim> struct rge { c b, e; };
sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim> auto dud(c*x) -> decltype(cerr<<*x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor (pair<b,c> d) {
  ris<<"("<<d.first<<", "<<d.second<<")";
}
sim dor(rge<c> d) {
  *this<<"[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris <<" ]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MaxN = 2e5 + 100;

char str[MaxN];
int n;

int main() {
  scanf("%d%s", &n, str);
  
  int ans = 0;
  ans += (count(str, str + n, '1') == 0);
  
  int rem = n;
  
  auto Check = [&](int x) {
    for (int i = 0; i < x; ++i) {
      int base = 0;
      for (int j = i; j < n; j += x) { base ^= (str[j] - '0'); }
      if (base != 0) { return false; }
    }
    return true;
  };
  
  vector<bool> is_good(n + 1);
  
  for (int d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      is_good[d] = Check(d);
      is_good[n / d] = Check(n / d);
    }
  }
  
  for (int k = 1; k < n; ++k) {
    debug() << imie(k) << imie(is_good[__gcd(k, n)]);
    ans += is_good[__gcd(k, n)];
  }
  printf("%d\n", ans);
}