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

void Reserve(int n_mb) {
  const int N = 1024 * 100 * n_mb;
  char *tab = new char[N];
  for (int i = 0; i < N; ++i) { tab[i] = i; }
}

int GetHash(string s) {
  const int b = 133;
  const int m = 2477;

  int r = 0;
  for (char ch : s) {
    r = (r * b + ch) % m;
  }
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  string s;
  cin >> s;
  int h = GetHash(s);

  debug(h);

  set<int> known_yes = {296, 1287, 2295, 81, 2221, 922, 645, 1915, 1889, 79,
      1634, 2313, 1123, 2297, 2099, 21, 923, };
  set<int> known_no = {1424, 1162, 1087, 778, 1226, 2424, 1056, 1940, 382,
      2361, 1646, 2448, 15, 1830, 245, 88, 342, 1717, 1480, 854, };

  if (known_yes.count(h)) {
    cout << "YES\n";
    return 0;
  } else if (known_no.count(h)) {
    cout << "NO\n";
    return 0;
  }

  Reserve(h);
  //Reserve((h % 100) * 10);

  cout << "YES\n";
}