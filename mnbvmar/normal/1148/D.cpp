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
  vector<int> as(n), bs(n);
  for (int i = 0; i < n; ++i) { cin >> as[i] >> bs[i]; }

  VI best_ans;

  for (int tr : {0, 1}) {
    (void)tr;
    VI order;
    for (int i = 0; i < n; ++i) {
      if (as[i] < bs[i]) { order.PB(i); }
    }

    sort(ALL(order), [&](int lhs, int rhs) {
          return bs[lhs] > bs[rhs];
        });

    VI cur;
    auto Reset = [&]() {
      if (SZ(cur) > SZ(best_ans)) {
        best_ans = cur;
      }
      cur.clear();
    };
    cur = order;
    Reset();


    for (int i = 0; i < n; ++i) {
      as[i] = 2 * n - as[i];
      bs[i] = 2 * n - bs[i];
    }
  }

  cout << SZ(best_ans) << "\n";
  for (int x :best_ans) { cout << x+1 << " "; }
  cout << "\n";
}