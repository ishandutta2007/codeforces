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

const int MaxN = 1e5 + 100;

char layout[MaxN];

void Win() {
  printf("tokitsukaze\n"); exit(0);
}
void Lose() {
  printf("quailty\n"); exit(0);
}
void Draw() {
  printf("once again\n"); exit(0);
}

int32_t main() {
  int n, k;
  scanf("%d%d%s", &n, &k, layout);

  bool will_lose = true;

  for (int x : {0, 1}) {
    set<int> nother;

    for (int i = 0; i < n; ++i) {
      if (layout[i] != x + '0') { nother.insert(i); }
    }

    for (int i = 0; i < k; ++i) {
      if (layout[i] != x + '0') { nother.erase(i); }
    }

    for (int i = 0; i + k <= n; ++i) {
      nother.erase(i + k - 1);
#ifdef LOCAL
      debug(x, i, vector<int>(ALL(nother)));
#endif
      if (nother.empty()) {
        Win();
      } else if (*nother.rbegin() - *nother.begin() >= k) {
        will_lose = false;
      }
      if (layout[i] != x + '0') { nother.insert(i); }
    }
  }

  if (will_lose) {
    Lose(); 
  } else {
    Draw();
  }
}