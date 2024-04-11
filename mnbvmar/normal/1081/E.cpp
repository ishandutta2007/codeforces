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

#warning
const int MaxVal = 2e5 + 100;

vector<int> min_lower[MaxVal];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  for (int a = 1; a < MaxVal; ++a)
    for (int b = a + 1; a * b < MaxVal; ++b) {
      // x-y=a, x+y=b
      if (a % 2 != b % 2) { continue; }
      const int x = (a + b) / 2;
      const int y = (b - a) / 2;
      min_lower[a * b].PB(y);
    }

  for (int i = 1; i < MaxVal; ++i) {
    sort(ALL(min_lower[i]));
    //assert(is_sorted(ALL(min_lower[i])));
  }

  int N;
  cin >> N;

  vector<int> seq;
  int min_y = 1;
  LL cur_pref = 0;

  for (int i = 0; i < N / 2; ++i) {
    int val;
    cin >> val;
    auto iter = lower_bound(ALL(min_lower[val]), min_y);
    if (iter == min_lower[val].end()) {
      cout << "No\n";
      return 0;
    }

    const int y = *iter;
    debug(y);
    min_y = y + 1;

    LL pref = (LL)y * y;
    seq.PB(pref - cur_pref);
    cur_pref = (LL)y * y;
    seq.PB(val);
    cur_pref += val;

    min_y = (int)sqrt(cur_pref + 0.01);
    assert((LL)min_y * min_y == cur_pref);
  }

  cout << "Yes\n";
  for (LL v : seq)
    cout << v << " ";
  cout << "\n";
}