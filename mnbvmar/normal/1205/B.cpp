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

const int kMaxN = 1e5 + 100;

vi adj[kMaxN];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  int n;
  cin >> n;
  vll nonzero;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (x) { nonzero.PB(x); }
  }
  n = SZ(nonzero);

  for (int b = 0; b < 61; ++b) {
    vi which;
    for (int i = 0; i < n; ++i) {
      if ((nonzero[i] >> b) & 1) {
        which.PB(i);
      }
    }
    debug(b, which);
    if (SZ(which) >= 3) {
      cout << "3\n";
      return 0;
    }
    if (SZ(which) == 2) {
      int a = which[0], b = which[1];
      adj[a].PB(b);
      adj[b].PB(a);
    }
  }

  int ans = 1e9;
  
  for (int s = 0; s < n; ++s) {
    vi dist(n, (ll)1e9);
    vi prv(n, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int x : adj[v]) {
        if (dist[x] > 1e8) {
          dist[x] = dist[v] + 1;
          prv[x] = v;
          q.push(x);
        } else if (dist[x] >= dist[v] && prv[x] != v && prv[v] != x) {
          debug(x, v, dist[x], dist[v], s);
          mini(ans, dist[x] + dist[v] + 1);
        }
      }
    }
  }

  if (ans > 1e8) { ans = -1; }
  cout << ans << "\n";
}