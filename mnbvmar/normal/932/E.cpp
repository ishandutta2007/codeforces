#include <bits/stdc++.h>

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

const int MaxK = 5005;
const int Mod = 1e9 + 7;

int powMod(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) { res = (res * a) % Mod; }
    n >>= 1;
    a = (a * a) % Mod;
  }
  return res;
}

int N, K;

int dp[MaxK][MaxK];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> N >> K;

  dp[0][0] = 1;
  for (int diff = 1; diff <= K; ++diff) {
    for (int dx = 1; dx <= diff; ++dx) {
      dp[diff][dx] = ((LL)dp[diff - 1][dx - 1] * (N - dx + 1)
                    + (LL)dp[diff - 1][dx] * dx) % Mod;
    }
  }

  LL Result = 0, Coef = powMod(2, N);
  for (int dx = 0; dx <= K; ++dx) {
    debug(dx, dp[K][dx]);
    Result = (Result + dp[K][dx] * Coef) % Mod;
    Coef = (Coef * powMod(2, Mod - 2)) % Mod;
  }

  cout << Result << "\n";
}