#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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

int n,m,P;
void mulself(int &a,int b){
  a = a * b % P;
}
int mul(int a,int b){
  return a * b % P;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
const int MAX = 511;
int dwu[MAX][MAX];
int dp1[MAX];
int dp2[MAX][MAX];
int dp3[MAX][MAX];
int ile[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> P;
  R(i,n + 1)R(j,i + 1){
    if(j == 0){
      dwu[i][j] = 1;
    }else{
      dwu[i][j] = dwu[i-1][j];
      add(dwu[i][j], dwu[i-1][j-1]);
    }
  }
  
  dp1[0] = 0;
  ile[0] = 1;
  R(i,m+1)if(i){
    R(j,i){
      int pom = 0;
      add(pom,mul(dp1[j], ile[i-j-1]));
      add(pom,mul(dp1[i-j-1], ile[j]));
      mulself(pom, j + 1);
      add(pom, mul(mul(ile[i-j-1], ile[j]), j * (j + 1) / 2));
      mulself(pom,dwu[i-1][j]);
      debug(pom,ile[i-j-1], ile[j], j * (j + 1) / 2,dwu[i-1][j]);
      add(dp1[i],pom);
      pom = dwu[i-1][j];
      mulself(pom, ile[j]);
      mulself(pom, ile[i-j-1]);
      mulself(pom, j + 1);
      add(ile[i],pom);
    }
    add(ile[i],ile[i]);
    add(dp1[i],dp1[i]);
    debug(i,ile[i],dp1[i]);
  }
  
  dp2[0][0] = 1;
  dp3[0][0] = 0;
  R(i,n+1)R(j,m+1)R(k,m+1)if(j + k <= m && i + k + 1 <= n + 1){
    int pom = dp2[i][j];
    mulself(pom, dwu[m - j][k]);
    mulself(pom, ile[k]);
    int pom3 = dp3[i][j];
    mulself(pom3, ile[k]);
    add(pom3, mul(dp1[k], dp2[i][j]));
    mulself(pom3, dwu[m - j][k]);
    add(dp2[i + k + 1][j + k],  pom);
    add(dp3[i + k + 1][j + k],  pom3);
  }
  cout << dp3[n + 1][m] << "\n";
}