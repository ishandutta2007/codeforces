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

vector<vector<int>> res;
int n,m;
vector<vector<PII>> d;
void licz(int s){
  vector<vector<int>> kt(n);
  vector<int> odl(n,2e9);
  int naj = 2e9;
  auto dod = [&](int v,int od){
    if(odl[v] > od){
      odl[v] = od;
      kt[od % n].PB(v);
    }
  };
  for(PII el:d[s]){
    mini(naj,el.SE);
    dod(el.FI, el.SE);
  }
  int gd = naj % n;
  R(_,n){
    debug(gd, SZ(kt));
    R(i,SZ(kt[gd])){
      int el = kt[gd][i];
//     for(int el:kt[gd]){
      if(odl[el] == naj){
        for(PII ed:d[el]){
          dod((ed.FI + gd) % n, naj + ed.SE);
        }
        el++;
        if(el == n)el -= n;
        dod(el, naj + 1);
      }
    }
    naj++;
    gd++;
    if(gd == n)gd = 0;
  }
  R(i,n)if(s != i){
    res[s][i] = odl[i];
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  res.resize(n,vector<int>(n));
  d.resize(n);
  R(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    d[a].PB({b,c});
  }
  R(i,n){
    licz(i);
  }
  R(i,n){
    R(j,n){
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
}