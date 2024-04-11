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

int f[6];
const int inf = 1e18;


void add(vector<int> &dp,int krok,int zysk){
  for(int i = SZ(dp)-1; i >= krok; i--){
    maxi(dp[i], dp[i-krok] + zysk);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int k;
  cin >> k;
  R(i,6)cin >> f[i];
  vector<int> dp(1,0);
  int pom = 3 * (k - 1);
  vector<int> xx;
  int x = 1;
  while(pom){
    xx.PB(x);
    pom -= x;
    if(pom & x){
      xx.PB(x);
      pom -= x;
    }
    x*=2;
  }
  for(int cyf = 5; cyf >= 0; cyf--){
    vector<int> dp2(10 * SZ(dp), -inf);
    R(i,SZ(dp2))dp2[i] = dp[i / 10];
    for(int el:xx)add(dp2, 3 * el, el * f[cyf]);
    
//     cerr << "dp2:\n";
//     R(i,min(SZ(dp2), 60ll)){
//       cerr << dp2[i] << " ";
//     }
//     cerr << "\n";
//     
    R(i,SZ(dp)){
      for(int j = 3 * k - 2; j <= 3 * k; j++){
        if(i * 10 + 3 * j < SZ(dp2)){
          maxi(dp2[i * 10 + 3 * j], dp[i] + j * f[cyf]);
        }
      }
    }
    swap(dp,dp2);
//     R(i,min(SZ(dp), 60ll)){
//       cerr << dp[i] << " ";
//     }
//     cerr << "\n";
  }
  debug(SZ(dp));
  int q;
  cin >> q;
  while(q--){
    int a;
    cin >> a;
    cout << dp[a] << "\n";
  }
}