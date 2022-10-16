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

void Lose() {
  printf("cslnb\n"); exit(0);
}

void Win() {
  printf("sjfnb\n"); exit(0);
}


int32_t main() {
  int n;
  scanf("%d", &n);

  vi piles(n);
  for (int &x : piles) { scanf("%d", &x); }

  sort(piles.begin(), piles.end());
  map<int, int> cnts;
  for (int x : piles) { ++cnts[x]; }

  int c2 = 0;

  for (auto &&[k, v] : cnts) {
    if (v >= 3) {
      Lose();
    }
    if (v == 2 && (cnts.count(k - 1) || k == 0)) {
      Lose();
    }
    if (v == 2) {
      if (c2) { Lose(); }
      ++c2;
    }
  }

  ll total = 0;
  for (int x : piles) { total += x; }

  ll fin = 0;
  for (int i = 0; i < n; ++i) { fin += i; }

  assert(total >= fin);

  if ((total - fin) % 2 == 0) {
    Lose();
  } else {
    Win();
  }
}