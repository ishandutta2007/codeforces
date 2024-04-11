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

vector<string> xxx = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int n,k;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  vector<string> t(n);
  vector<vector<int>> il(n,vector<int>(10,-1));
  R(i,n){
    cin >> t[i];
    R(j,10){
      bool cz = 1;
      int ile = 0;
      R(l,7){
        if(t[i][l] != xxx[j][l]){
          if(t[i][l] == '1'){
            cz = 0;
          }else{
            ile++;
          }
        }
      }
      if(cz){
        il[i][j] = ile;
      }
    }
  }
  
  
  
  vector<bitset<2001>> dp(n+1);
  dp[n][0] = 1;
  for(int i = n;i > 0;i--){
    R(j,10)if(il[i-1][j] != -1){
      dp[i-1] |= dp[i] << il[i-1][j];
    }
  }
  if(dp[0][k] == 0){
    cout << "-1\n";
    return 0;
  }
  string res;
  R(i,n){
    for(int j = 9; j>=0;j--)if(il[i][j] != -1 && k >= il[i][j]){
      if(dp[i+1][k - il[i][j]] == 1){
        res += j + '0';
        k -= il[i][j];
        break;
      }
    }
  }
  cout << res << "\n";
}