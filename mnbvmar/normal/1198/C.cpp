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

void Test() {
  int n, m;
  cin >> n >> m;
  n = 3 * n;

  vi indset;
  vi match;
  vector<bool> is_taken(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if (!is_taken[u] && !is_taken[v]) {
      match.PB(i + 1);
      is_taken[u] = true;
      is_taken[v] = true;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!is_taken[i]) {
      is_taken[i] = true;
      indset.PB(i);
    }
  }

  n /= 3;

  if (SZ(indset) >= n) {
    cout << "IndSet\n";
    for (int i = 0; i < n; ++i) {
      cout << indset[i] << " ";
    }
    cout << "\n";
    return;
  }

  if (SZ(match) >= n) {
    cout << "Matching\n";
    for (int i = 0; i < n; ++i) {
      cout << match[i] << " ";
    }
    cout << "\n";
    return;
  }

  assert(false);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    Test();
  }
}