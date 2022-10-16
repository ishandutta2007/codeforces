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

char sss[1000 * 1000 + 10];

string ReadWord() {
  scanf("%s", sss);
  return sss;
}

int32_t main() {
  int n;
  scanf("%d", &n);
  
  while (n--) {
    string a = ReadWord();
    string b = ReadWord();
    const int sa = SZ(a);
    const int sb = SZ(b);
    a += "$"; b += "$";
    
    int ap = 0, bp = 0;
    bool ok = true;
    while (ap < sa) {
      const char ch = a[ap];
      if (bp == sb) { ok = false; break; }
      int la = 0;
      while (a[ap + la] == ch) { ++la; }
      int lb = 0;
      while (b[bp + lb] == ch) { ++lb; }
      if (la > lb) { ok = false; break; }
      ap += la;
      bp += lb;
    }
    
    if (bp != sb) { ok = false; }
    
    printf(ok ? "YES\n" : "NO\n");
  }
}