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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<int> deg(n);
  vector<vector<int>> d(n);
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
    deg[a]++;
    deg[b]++;
  }
  deg[0]+=100;
  int kr = n - 1;
  int xo = 0;
  vector<int> res(n);
  vector<int> wyn(n);
  for(int i = n - 1; i >= 0; i--){
    debug(xo,kr);
    if(xo == (kr % 2)){
      res[i] = 2;
    }else{
      res[i] = 1;
    }
    int ak = i;
    while(ak >= i && deg[ak] == 1){
      int pom = 0;
      for(int el:d[ak]){
        pom ^= wyn[el];
        deg[el]--;
      }
      kr--;
      debug(i, pom, ak);
      xo ^= pom;
      wyn[ak] = pom + 1;
      xo ^= wyn[ak];
      for(int el:d[ak]){
        if(deg[el] >= 1){
          ak = el;
          break;
        }
      }
    }
  }
  for(int el:res){
    cout << el;
  }
  cout << "\n";
}