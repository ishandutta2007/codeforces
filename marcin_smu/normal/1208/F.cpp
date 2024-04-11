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

#ifdef LOCAL
const int C = 4;
#else
const int C = 21;
#endif
const int MAX = 1 << C;
vector<int> pier,ost,dru,t;
int n;
void dodaj_pier(int id, int val){
  debug(id,val);
  if(pier[val] == n){
    pier[val] = id;
    R(bit,C)if((val >> bit) & 1){
      dodaj_pier(id, val - (1 << bit));
    }
  }
}
void dodaj_ost(int id,int val){
  if(ost[val] != id && (ost[val] == -1 || dru[val] == -1)){
    if(ost[val] == -1)
      ost[val] = id;
    else
      dru[val] = id;
    R(bit,C)if((val >> bit) & 1){
      dodaj_ost(id, val - (1 << bit));
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  t.resize(n);
  pier.resize(MAX, n);
  ost.resize(MAX,-1);
  dru.resize(MAX,-1);
  R(i,n)
    cin >> t[i];
  
  R(i,n){
    dodaj_pier(i, t[i]);
  }
  for(int i = n - 1; i>=0; i--){
    dodaj_ost(i, t[i]);
  }
  debug(pier,ost,dru);
  
  debug(pier[0],dru[0],dru[4]);
  int res = 0;
  vector<PII> ok;
  ok.PB({0ll,0ll});
  for(int bit = C - 1; bit >= 0; bit --){
    int pom = 1 << bit;
    vector<PII> ok2;
    for(PII el:ok){
      if(pier[el.FI + pom] < dru[el.SE]){
        ok2.PB({el.FI + pom, el.SE});
      }
      if(pier[el.FI] < dru[el.SE + pom]){
        ok2.PB({el.FI, el.SE + pom});
      }
    }
    if(SZ(ok2)){
      res += pom;
      swap(ok,ok2);
    }
    debug(ok);
  }
  cout << res << "\n";
}