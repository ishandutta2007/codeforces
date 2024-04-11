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

LL N, K, L, R;
LL g1, d1, g2, d2;
LL answer = -1;

int CheckTotalG(LL total_g) {
  if (total_g > N) { return 1; }
  if (total_g < 0) { return -1; }
  const LL div = N + total_g;
  LL m = K % div;
  if (m == 0) { m = div; }
  const LL min_left = max<LL>(0, total_g - d2);
  debug(N, total_g, min_left, m);
  if (m < d1 + max<LL>(0, min_left - 1)) { return 1; }
  if (m > d1 + min<LL>(d1, total_g)) { return -1; }
  debug("ok");
  maxi(answer, total_g);
  return 0;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> L >> R >> K;

  R = (R - L + N) % N;
  L = 0;
  debug(N, K, L, R);

  d1 = R + 1;
  d2 = N - d1;
  debug(d1, d2);
  // max_g = N;

  // const LL max_iter_g = max_g;
  const LL max_iter_g = min(N, (int)(sqrt(K) + 3));

  for (LL tot_g = 0; tot_g <= max_iter_g; ++tot_g)
    CheckTotalG(tot_g);

  for (LL alpha = 0; alpha <= max_iter_g; ++alpha) {
    if (K - alpha * N < 0) { break; }
    LL max_g = alpha ? (K - alpha * N) / alpha : N;
    LL min_g = (K - (alpha + 1) * N + alpha) / (alpha + 1);
    maxi<LL>(min_g, 0);
    mini<LL>(max_g, N);
    if (max_g < min_g) { continue; }

    debug(alpha, min_g, max_g);
    ++max_g;

    while (max_g - min_g > 1) {
      const LL mid_g = (max_g + min_g) / 2;
      if (CheckTotalG(mid_g) == 1)
        max_g = mid_g;
      else
        min_g = mid_g;
    }

    CheckTotalG(max_g);
    CheckTotalG(max_g - 1);
    CheckTotalG(max_g - 2);

  }

  cout << answer << "\n";
}