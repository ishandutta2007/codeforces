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


int32_t main() {
  int n;
  scanf("%d", &n);
  
  vi seq(n);
  for (int &x : seq) { scanf("%d", &x); }
  
  vi orig_seq = seq;
  sort(ALL(seq));
  
  map<ll, int> progs;
  
  for (int i = 0; i < n - 1; ++i) {
    const ll diff = seq[i + 1] - seq[i];
    ++progs[diff];
  }
  
  for (auto &&[b, cnt] : progs) {
    if (cnt < n - 3) { continue; }
    
    for (ll a : {seq[0], seq[1]}) {
      vi erased;
      int loc = 0;
      for (int num : seq) {
        if (num == a + b * loc) {
          ++loc;
        } else {
          erased.PB(num);
        }
      }
      
      if (SZ(erased) > 1) { continue; }
      if (SZ(erased) == 0) { erased.PB(seq[0]); }
      
      assert(SZ(erased) == 1);
      debug(a, b);
      for (int i = 0; i < n; ++i) {
        if (orig_seq[i] == erased[0]) {
          printf("%d\n", i + 1);
          return 0;
        }
      }
      assert(false);
    }
  }
  
  printf("-1\n");
}