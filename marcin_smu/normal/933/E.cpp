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

const int MAX = 3e5 + 100;
int n,t[MAX];
int dp[MAX][2];
vector<int> res;
bool ruszone[MAX];
int RES = 0;
void rusz(int i){
  if(i < 0 || i >= n-1 || ruszone[i])return;
  ruszone[i] = 1;
  int pom = min(t[i],t[i+1]);
  RES += pom;
  if(pom){
    res.PB(i+1);
    t[i] -= pom;
    t[i+1] -= pom;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n)cin >> t[i];
  R(i,n)dp[i+1][0] = dp[i+1][1] = -1e18;
  R(i,n){
    maxi(dp[i+1][0], max(dp[i][0], dp[i][1]) - t[i]);
    maxi(dp[i+1][1], dp[i][0] + t[i]);
    if(i > 1){
      if(t[i-2] >= t[i-1]){
        maxi(dp[i+1][1], dp[i-2][1] - t[i-2] + t[i] + t[i-1]);
      }
      if(t[i] >= t[i-1]){
        maxi(dp[i+1][0], dp[i-1][1] + t[i-1] - t[i]);
      }
    }
  }
  int ak = 0;
  if(dp[n][1] > dp[n][0]){
    ak = 1;
  }
  debug(dp[n][ak]);
  vector<int> xx;
  for(int i = n - 1; i>0; i--){
    if(ak == 0 && dp[i+1][0] == dp[i][0] - t[i]){
      xx.PB(i - 2);
      xx.PB(i);
    }else{
      if(i > 1){
        if(ak == 1 && t[i-2] >= t[i-1] && dp[i+1][1] == dp[i-2][1] - t[i-2] + t[i] + t[i-1]){
          xx.PB(i-2);
          i-=2;
          ak = !ak;
        }else if(ak == 0 && t[i] >= t[i-1] && dp[i+1][0] == dp[i-1][1] + t[i-1] - t[i]){
          xx.PB(i-1);
          i--;
        }
      }
      ak = !ak;
    }
  }
  for(int el:xx){
    rusz(el);
  }
  R(i,n-1){
    rusz(i);
  }
  cout << SZ(res) << "\n";
  for(int el:res){
    cout << el << "\n";
  }
  debug(RES);
}