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

const int MAX = 5011;
int32_t dp[MAX][MAX];
int32_t newt[MAX][MAX];
int ost[MAX];
int n;
string z;
const int P = 1e9 + 7;
void add(int32_t &a,int b){
  a += b;
  if(a >= P)
    a-=P;
}
void sub(int32_t &a,int b){
  a -= b;
  if(a < 0)
    a += P;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> z;
  R(i,MAX)ost[i] = -1;
  dp[0][0] = 1;
  R(i,n){
    R(j,i+2){
      dp[i+1][j] = dp[i][j];
      if(j){
        add(dp[i+1][j], dp[i][j-1]);      
        if(ost[z[i]] != -1){
          sub(dp[i+1][j], dp[ost[z[i]]+1][j-1]);
        }
      }
    }
    ost[z[i]] = i;
  }
  R(i,n+1)R(j,i+1){
    if(j == 0)
      newt[i][j] = 1;
    else{
      newt[i][j] = newt[i-1][j];
      add(newt[i][j], newt[i-1][j-1]);
    }
  }
  int res = 0;
  R(i,n){
    res += dp[n][i+1] *1ll * newt[n-1][i] % P;
  }
  cout << res % P << "\n";
  
  
  
}