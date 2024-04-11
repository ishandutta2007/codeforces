#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
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

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

struct Rozw{
  int n,m,s,t;
  vector<vector<int>> d;
  vector<PII> res;
  vector<int> low,po,typ,par;
  int io = 0;
  bool xx = 0;
  
  void dfs_low(int nr,int oj){
    if(po[nr] != -1)return;
    par[nr] = oj;
    po[nr] = low[nr] = io;
    io++;
    for(int ak:d[nr]){
      if(ak != oj){
        dfs_low(ak,nr);
      }
    }
    for(int ak:d[nr]){
      if(ak != oj){
        mini(low[nr], low[ak]);
      }
    }
    if(oj != -1 && low[nr] >= po[oj] && nr != s)
      xx = 1;
  }
  void licz(int nr){
    typ[po[par[nr]]] = !typ[low[nr]];
    for(int ak:d[nr]){
      if(po[ak] < po[nr]){
        if(typ[po[ak]]){
          res.PB({nr,ak});
        }else{
          res.PB({ak,nr});
        }
      }else if(par[ak] == nr){
        licz(ak);
      }
    }
  }
  
  void go(){
    cin >> n >> m >> s >> t;
    s--;t--;
    d.resize(n);
    low.resize(n);
    po.resize(n,-1);
    par.resize(n);
    typ.resize(n);
    d[t].PB(s);
    R(i,m){
      int a,b;
      cin >> a >> b;
      a--;b--;
      if((a == s && b == t) || (a == t && b == s)){
        res.PB({s,t});
      }else{
        d[a].PB(b);
        d[b].PB(a);
      }
    }
    dfs_low(t,-1);
    if(xx){
      cout << "No\n";
    }else{
      cout << "Yes\n";
      licz(s);
      for(PII el:res){
        cout << el.FI+1 << " " << el.SE+1 << "\n";
      }
    }
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Rozw rozw;
    rozw.go();
  }
}