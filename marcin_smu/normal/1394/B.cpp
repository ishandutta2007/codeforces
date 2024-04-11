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

const int MAX = 201001;
vector<PII> d1[MAX];
vector<int> d2[MAX];
vector<int> zb;
int gd[10][10];
int n,m,k;
int d[50];
int res = 0;
void bt(int x,int zak){
  if(x == k + 1){
    res++;
    return;
  }
  debug(x,zak);
  R(i,x){
    int pom = gd[x][i];
    if(((zak >> pom)&1) == 0){
      bt(x+1, zak | d[pom]); 
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> k;
  R(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    d1[a].PB({c,b});
  }
  int id = 0;
  R(i,k+1){
    int mb = 0;
    R(j,i){
      gd[i][j] = id;
      mb |= 1ll << id;
      id++;
    }
    debug(d[0],gd[1][0],i,mb);
    R(j,i){
      d[gd[i][j]] = mb;
    }
  }
  debug(id,d[0]);
  R(i,n){
    sort(ALL(d1[i]));
    R(j,SZ(d1[i])){
      d2[d1[i][j].SE].PB(gd[SZ(d1[i])][j]);
    }
  }
  int zak = 0;
  
  debug(d[0]);
  R(i,n){
    map<int,int> x;
    R(j,SZ(d2[i])){
      x[d2[i][j]]++;
    }
    debug(d[0]);

    vector<int> poz;
    for(PII el:x){
      if(el.SE >= 2){
        zak |= 1ll << el.FI;
      }else{
        poz.PB(el.FI);
      }
    }
    R(ii,SZ(poz))R(j,ii){
      d[poz[j]] |= 1ll << poz[ii];
      debug(d[poz[j]],poz[j],poz[ii]);
    }
  }
  R(i,10){
    debug(d[i]);
  }
  bt(1,zak);
  cout << res << "\n";
}