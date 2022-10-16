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

const int MaxN = 1e5 + 100;

int s, b;
int queries[MaxN];

int main() {
  scanf("%d%d", &s, &b);
  for (int i = 0; i < s; ++i) {
    scanf("%d", &queries[i]);
  }
  vector<pll> bases(b);
  for (auto &[x, y] : bases) { scanf("%lld%lld", &x, &y); }
  
  bases.emplace_back(2e9, 2e9);
  
  sort(bases.begin(), bases.end());
  vector<pll> total;
  total.emplace_back(0, 0);
  
  vi qorder(s);
  iota(qorder.begin(), qorder.end(), 0);
  sort(qorder.begin(), qorder.end(), [&](int lhs, int rhs) {
    return queries[lhs] < queries[rhs];
  });
  
  vll answers(s);
  
  int bptr = 0, qptr = 0;
  ll ans = 0;
  while (qptr < s) {
    const int str = queries[qorder[qptr]];
    while (bases[bptr].first <= str) {
      ans += bases[bptr].second;
      ++bptr;
    }
    answers[qorder[qptr]] = ans;
    ++qptr;
  }
  
  for (ll x : answers) { printf("%lld ", x); }
  printf("\n");
}