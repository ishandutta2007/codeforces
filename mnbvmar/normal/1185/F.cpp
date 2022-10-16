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

const int MaxK = 9;
const int Infty = 2.1e9;

int n, m;

int num_satisfied[1 << MaxK];
ll min_one[1 << MaxK];
int who_one[1 << MaxK];
ll min_two[1 << MaxK];
pii who_two[1 << MaxK];


int32_t main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int cnt, msk = 0;
    scanf("%d", &cnt);
    for (int j = 0; j < cnt; ++j) {
      int v; scanf("%d", &v);
      msk |= (1 << (v-1));
    }
    
    for (int sup = 0; sup < (1 << MaxK); ++sup) {
      if ((sup & msk) == msk) {
        ++num_satisfied[sup];
      }
    }
  }
  
  fill_n(min_one, 1 << MaxK, Infty);
  fill_n(min_two, 1 << MaxK, Infty);
  
  vi costs(m);
  
  for (int i = 0; i < m; ++i) {
    int cost, cnt, msk = 0;
    scanf("%d%d", &cost, &cnt);
    costs[i] = cost;
    for (int j = 0; j < cnt; ++j) {
      int v; scanf("%d", &v);
      msk |= (1 << (v-1));
    }
    
    if (min_one[msk] > cost) {
      min_one[msk] = cost;
      who_one[msk] = i + 1;
    }
  }
  
  for (int i = 0; i < (1 << MaxK); ++i) {
    for (int j = 0; j < (1 << MaxK); ++j) {
      const int msk = i | j;
      const ll cost = min_one[i] + min_one[j];
      if (min_two[msk] > cost) {
        min_two[msk] = cost;
        who_two[msk] = pii{who_one[i], who_one[j]};
      }
    }
  }
  
  pii best{-1, 0};
  pii who_best;
  
  for (int i = 0; i < (1 << MaxK); ++i) {
    if (min_two[i] == Infty) { continue; }
    pii val{num_satisfied[i], -min_two[i]};
    if (val > best) {
      debug(i, val, who_best);
      best = val; who_best = who_two[i];
    }
  }
  
  debug(best, who_best, costs);
  
  if (who_best.st == who_best.nd) {
    int min_cost = 2e9, wh = -1;
    for (int x = 0; x < m; ++x) {
      if (x + 1 == who_best.st) { continue; }
      if (costs[x] < min_cost) {
        min_cost = costs[x]; wh = x + 1;
      }
    }
    who_best.nd = wh;
  }
  
  printf("%d %d\n", who_best.st, who_best.nd);
}