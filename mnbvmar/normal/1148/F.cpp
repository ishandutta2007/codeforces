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

  vector<int> val(n);
  vector<LL> mask(n);

  for (int i = 0; i < n; ++i) {
    cin >> val[i] >> mask[i];
  }

  LL total = accumulate(ALL(val), 0LL);
  if (total < 0) {
    for (int i = 0; i < n; ++i) {
      val[i] = -val[i];
    }
  }

  LL ans = 0;
  vector<int> num_rem(n);
  for (int i = 0; i < n; ++i) {
    num_rem[i] = __builtin_popcountll(mask[i]);
  }

  for (int bit = 0; bit < 62; ++bit) {
    LL total_zero = 0;
    for (int i = 0; i < n; ++i) {
      if (((mask[i]) >> bit) & 1) {
        --num_rem[i];
        if (num_rem[i] == 0) {
          total_zero += val[i];
        }
      }
    }

    if (total_zero > 0) {
      ans |= (1LL << bit);
      for (int i = 0; i < n; ++i) {
        if ((mask[i] >> bit) & 1) {
          val[i] = -val[i];
        }
      }
    }
  }

  assert(accumulate(ALL(val), 0LL) < 0);

  cout << ans << "\n";
}