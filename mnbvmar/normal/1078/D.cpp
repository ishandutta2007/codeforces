#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
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

const int MaxN = 3e5 + 100;
const int Base = 1 << 19;
const int LogMaxN = 19;

int max_left[LogMaxN][Base * 2];
int max_right[LogMaxN][Base * 2];
int N;

PII DoSteps(int L, int R, int base) {
  L += Base; R += Base;
  int res_l = 1e9, res_r = -1e9;
  mini(res_l, max_left[base][L]);
  mini(res_l, max_left[base][R]);
  maxi(res_r, max_right[base][L]);
  maxi(res_r, max_right[base][R]);

  while (L / 2 != R / 2) {
    if (L % 2 == 0) {
      mini(res_l, max_left[base][L + 1]);
      maxi(res_r, max_right[base][L + 1]);
    }
    if (R % 2 == 1) {
      mini(res_l, max_left[base][R - 1]);
      maxi(res_r, max_right[base][R - 1]);
    }
    L /= 2; R /= 2;
  }

  return {res_l, res_r};
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  if (N == 1) {
    cout << "0\n";
    return 0;
  }

  vector<int> radii(N * 3);
  for (int i = 0; i < N; ++i)
    cin >> radii[i];
  for (int i = N; i < 3 * N; ++i)
    radii[i] = radii[i - N];

  for (int i = 0; i < 3 * N; ++i) {
    max_left[0][i + Base] = max<int>(0, i - radii[i]);
    max_right[0][i + Base] = min<int>(3 * N - 1, i + radii[i]);
  }
  for (int i = 3 * N; i < Base; ++i)
    max_left[0][i + Base] = max_right[0][i + Base] = i;
  for (int i = Base - 1; i > 0; --i) {
    max_left[0][i] = min(max_left[0][2 * i], max_left[0][2 * i + 1]);
    max_right[0][i] = max(max_right[0][2 * i], max_right[0][2 * i + 1]);
  }

  for (int lg = 1; lg < LogMaxN; ++lg) {
    for (int a = 1, b = 2; a <= Base; a *= 2, b *= 2) {
      for (int v = a; v < b; ++v) {
        auto info = DoSteps(max_left[lg-1][v], max_right[lg-1][v], lg - 1);
        tie(max_left[lg][v], max_right[lg][v]) = info;
      }
    }
  }

  for (int i = N; i < 2 * N; ++i) {
    int cur_left = i, cur_right = i;
    int answer = 0;
    for (int lg = LogMaxN - 1; lg >= 0; --lg) {
      auto nxt = DoSteps(cur_left, cur_right, lg);
      if (nxt.nd - nxt.st >= N - 1) { continue; }
      cur_left = nxt.st;
      cur_right = nxt.nd;
      answer += (1 << lg);
    }

    cout << answer + 1 << " " ;
  }

  cout << "\n";


}