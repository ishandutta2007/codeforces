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

const int MAX = 701;
int n;
int t[MAX];
int dp[MAX][MAX];
int cz[MAX][MAX];
int licz(int a,int b){
  if(a == b)return 1;
  if(dp[a][b] != -1)return dp[a][b];
  assert(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n)cin >> t[i];
  R(i,n)R(j,n){
    dp[i][j] = i == j;
    cz[i][j] = __gcd(t[i],t[j]) > 1;
  }
  R(i,n)if(i)R(j,n - i){
    int a = j;
    int b = j + i;
    {
      int &res = dp[a][b];
      for(int m = a + 1; m<=b; m++){
        if(cz[a][m]){
          if(res |= dp[m][a+1] && dp[m][b])break;
        }
      }
    }
    swap(a,b);
    {
      int &res = dp[a][b];
      for(int m = b; m < a;m++){
        if(cz[a][m]){
          if(res |= dp[m][a-1] && dp[m][b])break;
        }
      }
    }
  }
  
  
  R(i,n){
    if(licz(i,0) && licz(i, n-1)){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}