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


struct Sol{
  vector<vector<int>> d,d2;
  vector<int> vis;
  int buduj_las(int v,int par){
    debug("buduj_las",v, par);
    vis[v] = 1;
    int wyn = 0;
    for(int el:d[v])if(el != par){
      if(vis[el] == 1){
        wyn ++;
      }else if(vis[el] == 0){
        int pom = buduj_las(el,v);
        if(pom == 0){
          d2[v].PB(el);
          d2[el].PB(v);
          debug("w lesie ", v, el);
        }
        wyn += pom;
      }else
        wyn--;
    }
    vis[v] = 2;
    return wyn;
  }
  vector<PII> res;
  int dfs(int v, int par){
    vis[v] = 1;
    vector<int> x;
    vector<int> y;
    for(int el:d2[v])if(el != par){
      if(SZ(d2[el]) >= 2){
        int pom = dfs(el, v);
        if(pom != -1){
          x.PB(pom);
        }else{
          y.PB(el);
        }
      }else{
        y.PB(el);
      }
    }
    if(SZ(d2[v]) % 2 == 1 && SZ(y) != 0){
      y.pop_back();
    }
    for(int el:y)x.PB(el);
    for(int i = 0; i + 1 < SZ(x);i+=2){
      res.PB({x[i],x[i+1]});
    }
    if(SZ(x) & 1){
      return x.back();
    }else{
      return -1;
    }
  }
  void run(){
    int n,m;
    cin >> n >> m;
    if(n == 0)exit(0);
    d.resize(n);
    R(i,m){
      int pom, ost;
      cin >> pom >> ost;ost--;
      R(_,pom-1){
        int ak;
        cin >> ak;ak--;
        d[ak].PB(ost);
        d[ost].PB(ak);
        debug(ak,ost);
        ost = ak;
      }
    }
    vis.resize(n);
    d2.resize(n);
    buduj_las(0, -1);
    R(i,n)vis[i] = 0;
    R(i,n)if(SZ(d2[i]) >= 2 && !vis[i]){
      int pom = dfs(i, -1);
      if(pom != -1)res.PB({pom, i});
    }
    cout << SZ(res) << "\n";
    for(PII el:res){
      cout << el.FI + 1 << " " << el.SE + 1 << "\n";
    }
    
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  while(1){
    Sol sol;
    sol.run();
  }
}