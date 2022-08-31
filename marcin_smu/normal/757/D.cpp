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


int n;
string s;
int32_t dp[80][1 << 20];
int d[80][80];
const int P = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> s;
  R(i,n){
    int ak = 0;
    for(int j = i;j<n;j++){
      ak *= 2;
      ak += s[j] - '0';
      if(ak < 21){
        d[i][j] = ak;
      }else
        break;
    }
  }
  R(i,n)
    dp[i][0] = 1;
  int res = 0;
  R(i,n)R(mb, 1 << 20){
    if(dp[i][mb]){
      for(int j = i; j<n;j++){
        if(d[i][j]){
          int pom = mb | 1 << (d[i][j]-1);
          dp[j+1][pom] += dp[i][mb];
          if(dp[j+1][pom] >= P)
            dp[j+1][pom] -= P;
        }
      }
    }
  }
  R(i,n+1){
    int mb = 1;
    while(mb < (1 << 20)){
      res += dp[i][mb];
      mb = mb * 2 + 1;
      if(res >= P)
        res -= P;
    }
  }
  cout << res << "\n";
  
  
}