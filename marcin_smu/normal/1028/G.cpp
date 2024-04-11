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

const int M = 10004205361450474ll;
const int limk = 10000;
int dp[limk+1][6];

int ile(int k, int zap){
  if(k > limk){
    k = limk;
  }
  if(zap == 1){
    return k;
  }
  if(dp[k][zap] != 0){
    return dp[k][zap];
  }
  int &zysk = dp[k][zap];
  R(i,k){
    zysk += ile(k + zysk, zap - 1);
    zysk++;
  }
  zysk += ile(k + zysk, zap - 1);
  return zysk;
}

int pytaj(int k,int zap){
  if(zap == 1){
    cout << min(k,limk) << " ";
    R(i,min(k,limk)){
      cout << k + i << " ";
    }
    cout << endl;
    return 0;
  }
  cout << min(k,limk) << " ";
  int zysk = 0;
  R(i,min(k,limk)){
    zysk += ile(k + zysk, zap - 1);
    cout << k + zysk << " ";
    zysk++;
  }
  cout << endl;
  int odp;
  cin >> odp;
  if(odp < 0){
    exit(0);
  }
  zysk = 0;
  R(i,odp){
    zysk += ile(k + zysk, zap - 1);
    zysk++;
  }
  return k + zysk;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  R(i,6)if(i){
    debug(ile(1,i));
  }
  int pocz = 1;
  R(i,5){
    pocz = pytaj(pocz,5 - i);
  }
  
}