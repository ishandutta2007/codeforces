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

const int MAX = 71;
int n,m,A,B;
int f[MAX];
int il[MAX];
int zly[MAX];
vector<PII> d[MAX];
int find(int a){
  return f[a] == a ? a : f[a] = find(f[a]);
}
int odl[MAX][1 << 18];
int res[MAX];
void uni(int a,int b){
  a = find(a);
  b = find(b);
  if(a == b)return;
  f[a] = b;
  il[b] += il[a];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> A >> B;
  R(i,n){
    f[i] = i;
    il[i] = 1;
    res[i] = -1;
  }
  R(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    d[a].PB({b,c});
    d[b].PB({a,c});
    if(c == A)uni(a,b);
  }
  int zle = 0;
  R(i,n){
    if(find(i) == i && il[i] >= 4){
      debug(i,il[i]);
      R(j,n)if(find(j) == i){
        zly[j] = 1ll << zle;
      }
      zle++;
    }
  }
  R(i,n)R(j, 1 << zle){
    odl[i][j] = 1e12;
  }
  
  set<pair<int,pair<int,int>>> secik;
  
  auto add = [&](int v,int mb,int od){
    if(odl[v][mb] > od){
      odl[v][mb] = od;
      secik.insert(MP(od,MP(v,mb)));
    }
  };
  add(0, zly[0], 0);
  int ilres = 0;
  while(SZ(secik)){
    int v,mb,od;
    auto pom = *secik.begin();
    od = pom.FI;
    v = pom.SE.FI;
    mb = pom.SE.SE;
    secik.erase(secik.begin());
    if(od != odl[v][mb])continue;
    debug(v,mb,od);
    if(res[v] == -1){
      debug(od);
      res[v] = od;
      ilres ++;
      if(ilres == n)break;
    }
    for(PII el:d[v]){
      if(el.SE == A || (find(v) != find(el.FI) && (zly[el.FI] & mb) == 0)){
        add(el.FI, zly[el.FI] | mb, od + el.SE);
      }
    }
  }
  
  
  R(i,n){
//     int res = 1e12;
//     R(j, 1 << zle){
//       mini(res, dp[i][j]);
//     }
    cout << res[i] << " ";
  }
  cout << "\n";
}