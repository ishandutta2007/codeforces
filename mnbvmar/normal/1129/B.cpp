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

void CheckAns(VI a, int K) {
  int res = 0, cur = 0, k = -1;
  int n = SZ(a);
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    if (cur < 0) { cur = 0; k = i; }
    maxi(res, (i - k) * cur);
  }

  int my_res = 0;
  for (int L = 0; L < n; ++L) {
    LL s = 0;
    for (int R = L; R < n; ++R) {
      s += a[R];
      maxi(my_res, s * (R - L + 1));
    }
  }

  debug(my_res, res);

  assert(my_res - res == K);
  cout << SZ(a) << "\n";
  for (int v : a) { cout << v << " "; }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int K;
  cin >> K;
  const int M = 1e6;

  if (K == 1) {
    VI ans{1, -2, 2};
    CheckAns(ans, K);
    return 0;
  }
  if (K <= 5) {
    VI ans(2 * K);
    ans[2 * K - 2] = -(K - 1);
    ans[2 * K - 1] = K;
    debug(ans);
    CheckAns(ans, K);
    return 0;
  }

  for (int n = 4;; ++n) {
    int a = 1;
    while ((K + a) % n != 0) { ++a; }

    while (a <= M - 1) {
      LL b = (K + a) / n + 2;
      if (0 < b && b <= a) {
        VI ans(n);
        ans[n - 4] = -1;
        ans[n - 3] = a;
        ans[n - 2] = -(a + 1);
        ans[n - 1] = b;
        CheckAns(ans, K);
        debug(a, b, n);
        return 0;
      }
      a += n;
    }
  }

  assert(false);
}