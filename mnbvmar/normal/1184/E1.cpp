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

int n, m;
int a0, b0;

const int MaxN = 1e5 + 100;

int fu_parent[MaxN];

int FuFind(int v) {
  if (v == fu_parent[v]) { return v; }
  return fu_parent[v] = FuFind(fu_parent[v]);
}

void FuUnion(int a, int b) {
  a = FuFind(a); b = FuFind(b);
  if (a != b) { fu_parent[a] = b; }
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%*d", &a0, &b0);
  
  --m;
  vector<tuple<int, int, int>> edges(m);
  
  for (auto &[c, a, b] : edges) { scanf("%d%d%d", &a, &b, &c); }
  sort(edges.begin(), edges.end());
  
  iota(fu_parent, fu_parent + n + 1, 0);
  
  int ans = 1e9;
  for (auto &&[c, a, b] : edges) {
    FuUnion(a, b);
    if (FuFind(a0) == FuFind(b0)) {
      ans = c;
      break;
    }
  }
  printf("%d\n", ans);
}