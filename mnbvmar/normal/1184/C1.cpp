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

int main() {
  int n;
  scanf("%d", &n);
  const int s = 4 * n + 1;
  
  vector<pii> pts(s);
  for (auto &[x, y] : pts) { scanf("%d%d", &x, &y); }
  
  for (int x1 = -50; x1 <= 50; ++x1) {
    for (int y1 = -50; y1 <= 50; ++y1) {
      for (int d = 1; d <= 50; ++d) {
        int x2 = x1 + d;
        int y2 = y1 + d;

        vi which_bad;
        for (int j = 0; j < s; ++j) {
          bool cur_ok = false;
          cur_ok |= (x1 == pts[j].first);
          cur_ok |= (x2 == pts[j].first);
          cur_ok |= (y1 == pts[j].second);
          cur_ok |= (y2 == pts[j].second);
          cur_ok &= (x1 <= pts[j].first && pts[j].first <= x2);
          cur_ok &= (y1 <= pts[j].second && pts[j].second <= y2);
          if (!cur_ok) { which_bad.push_back(j); }
        }
        
        if ((int)which_bad.size() == 1) {
          int v = which_bad[0];
          debug() << imie(x1) << imie(y1) << imie(d);
          printf("%d %d\n", pts[v].first, pts[v].second);
          return 0;
        }
      }
    }
  }
  
  assert(false);
  
}