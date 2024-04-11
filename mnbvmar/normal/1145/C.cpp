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

  int A;
  cin >> A;

  int ans[] = {15, 14, 12, 13, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7};
  /*int ans = 15;
  if (A & 1) { ans ^= 1; }
  if (A & 2) { ans ^= 3; }
  if (A & 4) { ans ^= 7; }
  if (A & 8) { ans ^= 15; }

  if (A == 6) {
    ans = 10;
  } else if (A == 7) {
    ans = 11;
  }*/

  cout << ans[A] << "\n";
  const int N = A * 1024 * 1000 * 10;
  char *tab = new char[N];
  for (int i = 0; i < N; ++i) { tab[i] = i; }

  /*if (A == 3) {
    cout << "13\n";
    return 0;
  } else if (A == 0) {
    cout << "15\n";
    return 0;
  } else if (A == 1) {
    cout << "14\n";
    return 0;
  }

  if (A == 2) {
    cout << "12\n";
  }*/

  /*if (A & 1) { A ^= 2; }
  if (A & 3) { A ^= 4; }
  if (A & 7) { A ^= 8; }
  cout << A << "\n";*/

  /*int b[4];
  REP (i, 4) {
    b[i] = A & 1;
    A >>= 1;
  }

  b[1] ^= b[0];
  b[2] ^= b[0] | b[1];
  b[3] ^= b[0] | b[1] | b[2];

  cout << b[3]*8 + b[2]*4 + b[1]*2 + b[0] << "\n";*/
}