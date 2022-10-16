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

const int MaxN = 1e6 + 100;

LL sub_sums[MaxN];
int N;
vector<int> children[MaxN];
int values[MaxN];
int inv_counts[MaxN];
int avail_sizes[MaxN];
LL num_ways_rooted[MaxN];

void dfs(int v) {
  sub_sums[v] = values[v];
  for (int c : children[v]) {
    dfs(c);
    sub_sums[v] += sub_sums[c];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> values[i];
  for (int i = 1; i < N; ++i) {
    int p;
    cin >> p;
    --p;
    children[p].push_back(i);
  }

  dfs(0);
  LL total = sub_sums[0];
  for (int i = 0; i < N; ++i) {
    LL p = sub_sums[i];
    LL q = total;
    const LL g = __gcd(p, q);
    p /= g;
    q /= g;
    debug(i, p, q);
    if (q <= N) {
      ++inv_counts[q];
    }
  }

  for (int size = 1; size <= N; ++size) {
    debug(size, inv_counts[size]);
    for (int mul = size; mul <= N; mul += size) {
      avail_sizes[mul] += inv_counts[size];
    }
  }

  for (int size = N; size >= 1; --size) {
    debug(size, avail_sizes[size]);
    if (avail_sizes[size] != size) { continue; }
    num_ways_rooted[size] = 1;
    for (int mul = size * 2; mul <= N; mul += size)
      num_ways_rooted[size] += num_ways_rooted[mul];
  }

  cout << num_ways_rooted[1] << "\n";
}