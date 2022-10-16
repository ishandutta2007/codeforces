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

const int MaxN = 18;
const int mod = 998244353;

int n, m;
bool has_edge[MaxN][MaxN];
bool any_dir[MaxN][MaxN];
int any_mask[MaxN];
int back_mask[MaxN];
//~ int total_cost[1 << MaxN][MaxN];
//~ int nways[1 << MaxN][MaxN];

map<int, int> memo[1 << MaxN];
ll cnt = 0;

int Solve(int mask, int can_mask) {
  if (mask == 0) { return 1; }
  if (can_mask == 0) { return 0; }
  
  auto iter = memo[mask].find(can_mask);
  if (iter != memo[mask].end()) { return iter->nd; }
  ++cnt;
  
  ll nways = 0;
  
  for (int i = 0; i < n; ++i) {
    if ((can_mask >> i) & 1) {
      
      int nmask = mask ^ (1 << i);
      int ncan_mask = can_mask;
      ncan_mask &= ~((1 << i) - 1);
      ncan_mask |= any_mask[i];
      
      debug(">", mask, can_mask, i, nmask, ncan_mask & nmask);
      
      int x = Solve(nmask, ncan_mask & nmask);
      nways += x;
    }
  }
  
  debug(mask, can_mask, nways);
  return memo[mask][can_mask] = nways % mod;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    has_edge[u][v] = true;
    any_dir[u][v] = any_dir[v][u] = true;
    
    any_mask[u] |= (1 << v);
    any_mask[v] |= (1 << u);
    back_mask[v] |= (1 << u);
  }
  
  //~ int mask = (1 << n) - 1;
  //~ int ans = Solve(mask, mask);
  
  
  vector<vector<pii>> coefs(1 << n);
  coefs[(1 << n) - 1].emplace_back((1 << n) - 1, 1);
  
  ll ans = 0;
  
  for (int mask = (1 << n) - 1; mask >= 0; --mask) {
    sort(ALL(coefs[mask]));
    int ptr = 0;
    const int S = SZ(coefs[mask]);
    
    while (ptr < S) {
      const int can_mask = coefs[mask][ptr].st;
      int c = 0;
      while (ptr < S && coefs[mask][ptr].st == can_mask) {
        c += coefs[mask][ptr].nd;
        if (c >= mod) { c -= mod; }
        ++ptr;
      }
      
      if (mask == 0) { ans += c; continue; }
      if (can_mask == 0) { continue; }
      
      for (int i = 0; i < n; ++i) {
        if ((can_mask >> i) & 1) {
          
          int nmask = mask ^ (1 << i);
          int ncan_mask = can_mask;
          ncan_mask &= ~((1 << i) - 1);
          ncan_mask |= any_mask[i];
          
          //~ debug(">", mask, can_mask, i, nmask, ncan_mask & nmask);
          
          coefs[nmask].emplace_back(ncan_mask & nmask, c);
          //~ int x = Solve(nmask, ncan_mask & nmask);
          //~ nways += x;
        }
      }
    }
    
    coefs[mask].clear();
    coefs[mask].shrink_to_fit();
  }
  
  ans = (ll)ans * m % mod;
  ans = (ll)ans * ((mod + 1) / 2) % mod;
  cout << ans << "\n";
}