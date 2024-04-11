#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

const int MaxVal = 1e7 + 100;
const int MaxN = 1e5 + 100;
const int K = 1024;

vector<int> adj[MaxN];
bool visited[MaxN];
VI vis_set;

void Dfs(int v) {
  vis_set.PB(v);
  visited[v] = true;
  for (int s : adj[v]) { if (!visited[s]) { Dfs(s); } }
}

int next_prime[MaxVal];
VI primes;

void Sieve() {
  iota(next_prime, next_prime + MaxVal, 0);
  for (int p = 2; p * p < MaxVal ;++p) {
    if (next_prime[p] != p) { continue; }
    for (int i = p; i < MaxVal; i += p) {
      if (next_prime[i] == i) {
        next_prime[i] = p;
      }
    }
  }
  for (int p = 2; p < MaxVal; ++p) {
    if (next_prime[p] == p) { primes.PB(p); }
  }
}

map<int, bitset<MaxN>> pinfo;

VI occurs[MaxVal];
VI at_loc[MaxVal];
bitset<MaxVal> has_any;
set<int> present_vals;
VI jumps[MaxVal];
VI blacklist;

int cnt_bt = 0;
int n, k;

void Bt(int val, int idx, bitset<MaxN> avail) {
  ++cnt_bt;
  if (cnt_bt % 10000 == 0) { debug(cnt_bt); }

  if (!at_loc[val].empty()) {
    VI indices;
    for (int i = avail._Find_first(); i < n; i = avail._Find_next(i)) {
      indices.PB(i);
      if (SZ(indices) == 2) { break; }
    }
    for (int v : at_loc[val]) {
      for (int u : indices) {
        adj[u].PB(v);
        adj[v].PB(u);
      }
    }
  }

  sort(ALL(jumps[val]));
  jumps[val].resize(unique(ALL(jumps[val])) - jumps[val].begin());
  bitset<MaxN> nxtbit;

  for (int nval : jumps[val]) {
    const int p = nval / val;

    auto iter = pinfo.find(p);
    nxtbit = avail;

    if (iter != pinfo.end()) {
      nxtbit &= ~iter->nd;
    } else {
      for (int idx : occurs[p]) {
        nxtbit[idx] = false;
      }
    }

    Bt(val * p, idx + 1, nxtbit);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  Sieve();

  cin >> n >> k;

  VI vals(n);
  has_any[1] = true;


  for (int i = 0; i < n; ++i) {
    cin >> vals[i];
    int v = vals[i];
    int q = 1;

    while (v > 1) {
      const int p = next_prime[v];
      while (v % p == 0) { v /= p; }
      jumps[q].PB(q * p);
      q *= p;
      has_any[q] = true;
    }
    //debug(q);

    v = vals[i];
    while (v > 1) {
      const int p = next_prime[v];
      while (v % p == 0) { v /= p; }
      occurs[p].PB(i);
    }

    present_vals.insert(q);
    at_loc[q].PB(i);
  }

  for (int p = 0; p < n; ++p) {
    if (SZ(occurs[p]) > K) {
      bitset<MaxN> bit_occur;
      for (int idx : occurs[p]) {
        bit_occur[idx] = true;
      }
      pinfo.emplace(p, bit_occur);
    }
  }

  bitset<MaxN> avail;
  for (int i = 0; i <= n; ++i) { avail[i] = true; }
  Bt(1, 0, avail);

  VI singles;
  VI nonsingles;

  for (int i = 0; i < n; ++i) {
    if (visited[i]) { continue; }
    vis_set.clear();
    Dfs(i);

    singles.PB(vis_set[0]);
    if (SZ(vis_set) > 1) {
      if (SZ(nonsingles) == k - 1) { nonsingles.pop_back(); }
      for (int x : vis_set) { nonsingles.PB(x); }
      if (SZ(nonsingles) > k) { nonsingles.resize(k); }
    }
  }

  assert(SZ(singles) >= k || SZ(nonsingles) >= k);
  VI ans = SZ(singles) >= k ? singles : nonsingles;
  ans.resize(k);

  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}