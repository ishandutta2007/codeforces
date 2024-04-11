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

const int inf = 1e12;
int n;
vector<int> t;
vector<int> h;
vector<vector<int>> d;
PII dfs(int v,int oj){
  int res = 0;
  int ilx = 0;
  int ily = 0;
  vector<int> xy,yx;
  for(int el:d[v])if(el != oj){
    PII pom = dfs(el, v);
    if(h[v] > h[el])pom.FI = inf;
    if(h[v] < h[el])pom.SE = inf;
    if(pom.FI <= pom.SE){
      res+=pom.FI;
      xy.PB(pom.SE - pom.FI);
      ilx++;
    }else{
      res+=pom.SE;
      yx.PB(pom.FI - pom.SE);
      ily++;
    }
  }
  debug(v,res,xy,yx,ilx,ily);
  PII out = {inf,inf};
  mini(out.SE, res + max(ilx+1,ily) * t[v]);
  mini(out.FI, res + max(ilx,ily+1) * t[v]);
  
  int pomres = res;
  int pomilx = ilx;
  int pomily = ily;
  
  sort(ALL(xy));
  R(i,SZ(xy)){
    res += xy[i];
    ilx--;
    ily++;
    mini(out.SE, res + max(ilx+1,ily) * t[v]);
    mini(out.FI, res + max(ilx,ily+1) * t[v]);    
  }
  
  res = pomres;
  ilx = pomilx;
  ily = pomily;
  
  sort(ALL(yx));
  R(i,SZ(yx)){
    res += yx[i];
    ilx++;
    ily--;
    mini(out.SE, res + max(ilx+1,ily) * t[v]);
    mini(out.FI, res + max(ilx,ily+1) * t[v]);    
  }
  debug(v,out);
  return out;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  t.resize(n);
  h.resize(n);
  d.resize(n);
  R(i,n){
    cin >> t[i];
  }
  R(i,n){
    cin >> h[i];
  }
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  R(i,n)if(SZ(d[i]) == 1){
    PII res = dfs(i,-1);
    cout << min(res.FI,res.SE) << "\n";
    return 0;
  }
}