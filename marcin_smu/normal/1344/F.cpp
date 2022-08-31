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

const int MAX = 2001;
#ifdef LOCAL
typedef bitset<20> X;
#else
typedef bitset<2001> X;
#endif
int n,k;
vector<X> t;
vector<int> res;
int gd[256];
int zm[MAX][4];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  gd['R'] = 1;
  gd['Y'] = 2;
  gd['B'] = 3;
  R(i,n){
    R(j,4){
      zm[i][j] = j;
    }
  }
  R(_,k){
    string typ;
    cin >> typ;
    if(typ == "mix"){
      int pom;
      cin >> pom;
      X x1,x2;
      R(i,pom){
        int ak;
        cin >> ak;
        ak--;
        debug(zm[ak][1],zm[ak][2]);
        if(zm[ak][1] & 1){
          x1[2*ak] = 1;
        }
        if(zm[ak][2] & 1){
          x1[2*ak + 1] = 1;
        }
        
        
        if(zm[ak][1] & 2){
          x2[2*ak] = 1;
        }
        if(zm[ak][2] & 2){
          x2[2*ak + 1] = 1;
        }
      }
      char q;
      cin >> q;
      t.PB(x1);
      res.PB(gd[(int)q] & 1);
      t.PB(x2);
      res.PB((gd[(int)q] >> 1) & 1);
    }else{
      int pom;
      cin >> pom;
      int a = gd[(int)typ[0]];
      int b = gd[(int)typ[1]];
      R(i,pom){
        int ak;
        cin >> ak;
        ak--;
        int ga,gb;
        R(l,4){
          if(zm[ak][l] == b)gb = l;
          if(zm[ak][l] == a)ga = l;
        }
        swap(zm[ak][ga], zm[ak][gb]);
      }
    }
  }
  R(i,SZ(t)){
    debug(t[i], res[i]);
  }
  int po = 0;
  vector<int> wyn(n);
  vector<int> xx(SZ(t));
  R(j,2 * n){
    int gg = -1;
    for(int i = po;i < SZ(t); i++){
      if(t[i][j] == 1){
        gg = i;
        break;
      }
    }
    if(gg == -1){
      continue;
    }
    swap(t[po],t[gg]);
    swap(res[po],res[gg]);
    xx[po] = j;
    R(i,SZ(t))if(i != po){
      if(t[i][j] == 1){
        t[i] ^= t[po];
        res[i] ^= res[po];
      }
    }
    po++;
  }
  R(i,po){
    if(res[i] == 1){
      wyn[xx[i] / 2] += 1 << (xx[i] % 2); 
    }
  }
  debug("po",wyn);
  R(i,SZ(t)){
    debug(t[i], res[i]);
  }
  debug(po,SZ(t));
  for(int i = po;i < SZ(t); i++){
    if(res[i] != 0){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  string mapa = ".RYB";
  R(i,n){
    cout << mapa[wyn[i]];
  }
  cout << "\n";
}