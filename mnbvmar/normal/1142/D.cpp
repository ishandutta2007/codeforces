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

  /*vector<int> inades;
  for (int i = 1; i <= 9; ++i) { inades.PB(i); }

  vector<vector<set<int>>> new_rems(11, vector<set<int>>(10));

  for (int i = 0; i < 1000; ++i) {
    const int m = i + 1;
    const int x = inades[i];
    const int r = m % 11;
    if (r == 0) { cout << "\n"; }
    for (int d = 0; d < 10; ++d) {
      if (d < r) {
        inades.PB(x * 10 + d);
        if (d == 0) {
          new_rems[r][0].insert(SZ(inades) % 11);
        }
      }
    }
    cout << x << ", ";
  }
  cout << "\n";

  for (int r = 0; r < 11; ++r) {
    cout << r;
    for (int d = 0; d < 10; ++d) {
      cout << " " << d << " -> " << VI(ALL(new_rems[r][d])) << "\n";
    }
  }*/

  string str;
  cin >> str;
  const vector<int> kBaseNexts = {-1, 10, 0, 2, 5, 9, 3, 9, 5, 2, 0};

  vector<VI> next_rems(10, VI(11, -1));

  for (int d = 0; d < 10; ++d) {
    for (int r = 0; r < 11; ++r) {
      if (d < r) {
        const int s = (kBaseNexts[r] + d) % 11;
        next_rems[d][r] = s;
      }
    }
  }

  vector<LL> cur_counts(11, 0);
  LL ans = 0;

  for (char ch : str) {
    const int d = ch - '0';
    vector<LL> new_counts(11);

    for (int r = 0; r < 11; ++r) {
      if (!cur_counts[r]) { continue; }
      const int s = next_rems[d][r];
      if (s == -1) { continue; }
      new_counts[s] += cur_counts[r];
    }

    if (d) {
      ++new_counts[d];
    }
    ans += accumulate(ALL(new_counts), 0LL);
    cur_counts = new_counts;
  }

  cout << ans << "\n";

}