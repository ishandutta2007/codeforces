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
mt19937 rng(123);
#else
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
struct Sol{
  int n,m;
  vector<vector<int>> d,dok;
  vector<int> vis;
  bool dfs(int x){
    vis[x] = 1;
    for(int el:d[x]){
      if(vis[el] == 2)return 0;
      if(vis[el] == 0){
        if(!dfs(el))return 0;
      }
    }
    vis[x] = 2;
    return 1;
  }
  
  vector<int> wyn;
  
  int root;
  vector<int> zle;
  vector<int> xzle;
  PII licz(int x){
    vis[x]=1;
    int gdzie = 0;
    int ile = 0;
    for(int el:d[x]){
      if(vis[el] == 1){
        ile ++;
        gdzie ^= el;
        zle[el]++;
        xzle[el] ^= el;
      }else{
        PII pom = licz(el);
        gdzie ^= pom.FI;
        ile += pom.SE;
      }
    }
    ile -= zle[x];
    gdzie ^= xzle[x];
    if(ile == 1){
      debug(x,ile,gdzie);
      dok[gdzie].PB(x);
    }
    vis[x]=2;
    return {gdzie, ile};
  }
  void dfsok(int x){
    wyn.PB(x);
    for(int el:dok[x]){
      dfsok(el);
    }
  }
  
  void run(){
    cin >> n >> m;
    d.resize(n);
    R(i,m){
      int a,b;
      cin >> a >> b;
      a--;b--;
      d[a].PB(b);
//       drev[b].PB(a);
    }
    vis.resize(n);
    R(_,50){
      int pom = uniform_int_distribution<int>(0, n-1)(rng);
      R(i,n)vis[i] = 0;
      if(dfs(pom)){
        bool ok = 1;
        debug(vis);
        R(i,n)if(vis[i] != 2) ok = 0;
        if(!ok)continue;
        root = pom;
        zle.resize(n);
        xzle.resize(n);
        dok.resize(n);
        debug(pom);
        licz(pom);
        
        dfsok(pom);
        debug(wyn);
        if(SZ(wyn) * 5 < n){
          cout << "-1\n";
        }else{
          sort(ALL(wyn));
          for(int el:wyn){
            cout << el + 1 << " ";
          }
          cout << "\n";
        }
        return;
      }
    }
    cout << "-1\n";
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
    Sol sol;
    sol.run();
  }
}