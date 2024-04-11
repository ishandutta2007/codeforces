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

bool IsXGeq(int x, int y) {
  cout << "? " << x << " " << y << endl;
  char ch;
  cin >> ch;
  assert(ch != 'e');
  return ch == 'x';
}

int32_t main() {

  while (true) {
    string type;
    cin >> type;

    if (type == "end" || type == "mistake") { break; }
    // TODO a=1, a=2
    int x = 1, y = 2;

    while (!IsXGeq(x, y)) {
      x *= 2; y *= 2;
    }

    if (x == 1) {
      if (IsXGeq(2, 3)) {
        y = 1;
      } else {
        y = 2;
      }
    } else {
      const int base_x = x;

      while (y - x > 1) {
        const int mid = (x + y) / 2;
        if (IsXGeq(base_x, mid)) {
          y = mid;
        } else {
          x = mid;
        }
      }
    }

    cout << "! " << y << endl;
  }
}