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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const int P = 1e9 + 7;
const int MAX = 1111;
int m,n;
int dp[MAX][MAX];
string t[MAX];
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> m >> n;
  R(i,n){
    cin >> t[i];
  }
  map<int,int> ile;
  R(i,m){
    int pom = 0;
    R(j,n){
      pom *= 2;
      pom += t[j][i] - '0';
    }
    ile[pom]++;
  }
  dp[1][1] = 1;
  for(int i = 2; i <= m; i++){
    R(j,i){
      add(dp[i][j], dp[i-1][j] * j % P);
      add(dp[i][j+1], dp[i-1][j]);
    //  debug(i,j,dp[i][j]);
    }
  }
  int res = 1;
  for(PII el:ile){
    int ak = 0;
    R(i,el.SE + 1){
      add(ak,dp[el.SE][i]);
    }
    debug(ak,el.SE);
    res = res * ak % P;
  }
  cout << res << "\n";
}