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
template<class K, class X> ostream &operator<<(ostream& os, map<K,X> V) {
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

string CopyFrom(char dir) {
  return string("10") + dir + 't';
}

string NegFrom(char dir) {
  return string("01") + dir + 't';
}

string kXor =
  "dd0d1uuuuu" + NegFrom('d') + "ddtd" + CopyFrom('u') + "d" + CopyFrom('u') +
    "ddteu";

string kAnd =
  "dd0d1uuuuu" + CopyFrom('d') + "d0dtd" + CopyFrom('u') + "d" + CopyFrom('u') +
    "ddteu";

string ZeroIfEmpty(char tmp_dir) {
  char rev_dir;
  if (tmp_dir == 'd' || tmp_dir == 'u')
    rev_dir = tmp_dir ^ 'd' ^ 'u';
  else
    rev_dir = tmp_dir ^ 'l' ^ 'r';
  return string("") + tmp_dir + "0" + tmp_dir + "1" + rev_dir + "s" + rev_dir +
    "t0" + rev_dir + tmp_dir + tmp_dir + "t" + tmp_dir + tmp_dir + "e" + rev_dir
    + "e" + rev_dir;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  const int kLen = 32;

  string ops;

  for (int i = 0; i < kLen; ++i)
    ops += ZeroIfEmpty('d') + "u" + ZeroIfEmpty('u') + "dl";
  ops += "uuu";
  for (int i = 0; i < kLen; ++i)
    ops += "r0";
  ops += "ddd";

  for (int i = 0; i < kLen; ++i) {
    ops += "r" + CopyFrom('l') + "u" + CopyFrom('l') + "d" + kXor + "l" + kAnd;
    ops += "uu" + CopyFrom('u') + "d" + CopyFrom('u') + "r" + CopyFrom('l') +
      "r" + CopyFrom('l') + "d" + CopyFrom('l') + kXor + "l" + kAnd;
    ops += "u" + CopyFrom('d') + "l" + CopyFrom('r') + "d" + kXor;
    ops += "u" + CopyFrom('d') + "u" + CopyFrom('d') + "l" + CopyFrom('r') + "u" +
      CopyFrom('d') + "dedd";
  }

  ops += "r";

  cout << ops << "\n";
}