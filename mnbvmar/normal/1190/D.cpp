#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;

void Renumber(vi &v) {
  vi sorted = v;
  sort(ALL(sorted));
  sorted.resize(unique(ALL(sorted)) - sorted.begin());

  for (int &x : v) {
    x = lower_bound(ALL(sorted), x) - sorted.begin();
  }
}

const int Base = 1 << 18;

int seg[2 * Base];

void Put(int v) {
  v += Base;
  seg[v] = 1;
  v /= 2;
  while (v) {
    seg[v] = seg[v*2] + seg[v*2+1];
    v /= 2;
  }
}

int GetSum(int L, int R) {
  if (L > R) { return 0; }
  L += Base; R += Base;
  if (L == R) { return seg[L]; }
  int ans = seg[L] + seg[R];
  while (L / 2 != R / 2) {
    if (L % 2 == 0) { ans += seg[L + 1]; }
    if (R % 2 == 1) { ans += seg[R - 1]; }
    L /= 2; R /= 2;
  }
  return ans;
}

int32_t main() {
  int n;
  scanf("%d", &n);

  vi xs(n), ys(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &xs[i], &ys[i]);
  }

  Renumber(xs); Renumber(ys);
  debug(xs, ys);

  vi order(n);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int lhs, int rhs) {
        return pii(ys[lhs], xs[lhs]) > pii(ys[rhs], xs[rhs]);
      });

  ll ans = 0;

  for (int i = 0; i < SZ(order); ++i) {
    int L = 0;
    int R = n - 1;
    const int v = order[i];

    if (i + 1 < SZ(order)) {
      if (ys[order[i + 1]] == ys[v]) {
        L = xs[order[i + 1]] + 1;
      }
    }

    int cl = GetSum(L, xs[v] - 1);
    int cr = GetSum(xs[v] + 1, R);
    debug(v, L, R, cl, cr);
    ans += (ll)(cl + 1) * (cr + 1);
    Put(xs[v]);

  }

  printf("%lld\n", ans);
  
}