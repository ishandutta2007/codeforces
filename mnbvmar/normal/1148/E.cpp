#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
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


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int n;
  cin >> n;

  VI si(n), ti(n);
  for (int i = 0; i < n; ++i) { cin >> si[i]; }
  for (int i = 0; i < n; ++i) { cin >> ti[i]; }

  sort(ALL(ti));
  debug(ti);

  VI order_s(n);
  iota(ALL(order_s), 0);
  sort(ALL(order_s), [&](int lhs, int rhs) {
        return si[lhs] < si[rhs];
      });

  VI rev_order_s(n);
  for (int i = 0 ;i < n; ++i) {
    rev_order_s[order_s[i]] = i;
  }

  VI diffs(n);
  for (int i = 0; i < n; ++i) {
    diffs[i] = ti[i] - si[order_s[i]];
  }

  debug(diffs);

  vector<tuple<int, int, int>> ops;
  vector<PII> plus_stack;

  for (int i = 0; i < n; ++i) {
    debug(i, order_s[i]);
    if (diffs[i] > 0) {
      plus_stack.emplace_back(i, diffs[i]);
      continue;
    }
    debug(plus_stack, i, diffs[i]);
    while (diffs[i] < 0 && !plus_stack.empty()) {
      auto [idx, dx] = plus_stack.back();
      plus_stack.pop_back();
      const int move = min(-diffs[i], dx);
      ops.emplace_back(order_s[idx], order_s[i], move);
      diffs[i] += move;
      if (dx > move) {
        plus_stack.emplace_back(idx, dx - move);
      }
    }

    if (diffs[i] != 0) {
      cout << "NO\n";
      return 0;
    }

  }

  if (!plus_stack.empty()) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n" << SZ(ops) << "\n";
  for (auto &&[a, b, c] : ops) {
    cout << a+1 << " " << b+1 << " " << c << "\n";
  }
}