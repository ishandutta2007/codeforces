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

const int MAX = 3001;
int n,m;
vector<int> d[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  int mam = 0;
  R(i,n){
    int a,b;
    cin >> a >> b;
    if(a == 1){
      mam ++;
    }else{
      d[a-2].PB(b);
    }
  }
  R(i,m){
    sort(ALL(d[i]),greater<int>());
  }
  int res = 1e18;
  R(i,n+1)if(i){
    vector<int> rest;
    int ak_mam = mam;
    int wyn = 0;
    R(j,m){
      R(k,min(SZ(d[j]),i - 1)){
        rest.PB(d[j][k]);
      }
      for(int k = i - 1; k < SZ(d[j]); k ++){
        wyn += d[j][k];
        ak_mam ++;
      }
    }
    if(ak_mam < i){
      sort(ALL(rest));
      R(j,i - ak_mam){
        wyn += rest[j];
      }
    }
    debug(i,wyn);
    mini(res,wyn);
  }
  cout << res << "\n";
}