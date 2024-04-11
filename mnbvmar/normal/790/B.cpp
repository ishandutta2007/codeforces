#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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


const int MaxN = 2e5 + 5;
const int MaxK = 5;

LL dp[MaxN][MaxK + 1];
int N, K;

vector<int> adj[MaxN];
LL result = 0;


void dfs(int v, int p) {
  dp[v][0]++;
  LL tres = 0;

  for (int s : adj[v]) {
    if (s == p) { continue; }
    dfs(s, v);

    for (int prv = 0; prv < K; prv++) {
      for (int zi = 0; zi < K; zi++) {
        int i = (zi + 1) % K;
        int coef = (prv + i + K - 1) / K;
        if (dp[v][prv] && dp[s][zi])
          debug(coef, prv, zi, s, v);
        tres += dp[v][prv] * dp[s][zi] * coef;
      }
    }

    for (int i = 0; i < K; i++) {
      dp[v][(i + 1) % K] += dp[s][i];
    }
  }
  debug(tres, v);
  result += tres;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> K;
  for (int i = 0; i < N -1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  dfs(1, 1);

  for (int v = 1; v <= N; v++) {
    LL tsize = 0;
    for (int i = 0; i < K; i++) { tsize += dp[v][i]; }

    result += dp[v][K - 1] * (N - tsize);
    debug(dp[v][K - 1], N - tsize);
    debug(result);

    /*for (LL d1 = 0; d1 <= K; d1++) {
      for (LL d2 = d1; d2 <= K; d2++) {
        int coef = (d1 + d2 + K - 1) / K;

        if (d1 == d2) {
          result += coef * dp[v][d1] * (dp[v][d1] - 1) / 2;
        } else {
          result += coef * dp[v][d1] * dp[v][d2];
        }
      }
    }

    debug(result);*/
  }

  cout << result << "\n";
}