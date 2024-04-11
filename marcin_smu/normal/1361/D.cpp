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

int n,k;

struct frac{
  int a,b;
  bool operator<(const frac &pom)const{
    int polx = a > 0 || (a == 0 && b > 0);
    int poly = pom.a > 0 || (pom.a == 0 && pom.b > 0);
    if(polx != poly)
      return polx < poly;
    return a * pom.b < b * pom.a;
  }
};

LD kw(LD a){
  return a * a;
}
struct odls{
  vector<LD> a;
  void dodaj(int x,int y){
    LD odl = sqrt(kw(x) +  kw(y));
    a.PB(odl); 
  }
  vector<LD> licz(){
    sort(ALL(a));
    reverse(ALL(a));
    vector<LD> res;
    int j = 0;
    R(i,SZ(a)){
      if(k - 1 - j * 2 < 0 && k - (n - SZ(a)) - SZ(res) < SZ(a) - i){
      }else{
        debug(i,j,SZ(a));
        res.PB(a[i] * (k - 1 - j * 2));
        j++;
      }
    }
    
    return res;
  }
};
map<frac,odls> mapka;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  R(i,n){
    int x, y;
    cin >> x >> y;
    if(x != 0 || y != 0){
      mapka[frac{x,y}].dodaj(x,y);
    }
  }
  vector<LD> razem;
  for(auto &x:mapka){
    debug(x.SE.a);
    auto pom = x.SE.licz();
    for(LD el:pom){
      razem.PB(el);
    }
  }
  sort(ALL(razem));
  reverse(ALL(razem));
  debug(razem);
  LD ak = 0;
  R(i,k-1){
    ak += razem[i];
  }
  if(SZ(razem) > k-1){
    maxi(ak, ak + razem[k-1]);
  }
  cout << ak << "\n";
}