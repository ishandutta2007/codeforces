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

const int M = 1.1e6;

int phi[M];

void Sieve() {
  iota(phi, phi + M, 0);

  for (int p = 2; p < M; ++p) {
    if (phi[p] != p) { continue; }
    for (int i = p; i < M; i += p) {
      phi[i] /= p;
      phi[i] *= p - 1;
    }
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  Sieve();

  int n, k;
  cin >> n >> k;

  ll ans = 1e18;

  {
    ll cand = 2;
    vi phis(phi + 3, phi + n + 1);
    sort(ALL(phis));
    cand += accumulate(phis.begin(), phis.begin() + k, 0LL);
    mini(ans, cand);
  }
  {
    ll cand = 1;
    vi phis;
    for (int i = 3; i <= n; i += 2) { phis.PB(phi[i]); }
    sort(ALL(phis));
    if (SZ(phis) >= k) {
      cand += accumulate(phis.begin(), phis.begin() + k, 0LL);
      mini(ans, cand);
    }
  }
  cout << ans << "\n";
}