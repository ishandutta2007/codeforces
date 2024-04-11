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
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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
  map<int, vector<int>> d;
  vector<int> path;
  int h;
  int il = 0;
  int res = -1;
  
  void ask(int x){
    il ++;
    if(il == 17){
      res = x;
      throw 1;
    }
    
    cout << "? " << x+1 << endl;
    int pom;
    cin >> pom;
    
    while(pom--){
      int pom2;
      cin >> pom2;
      d[x].PB(pom2-1);
    }
    
    if(SZ(d[x]) == 2){
      res = x;
      throw 1;
    }
    
    path.PB(x);
  }
  
  int dfs(int a,int oj){
    ask(a);
    for(int el:d[a]){
      if(el != oj){
        dfs(el,a);
        break;
      }
    }
  }
  
  void back_track(int a,int oj,int dep){
    ask(a);
    if(dep){
      for(int el:d[a]){
        if(el != oj){
          back_track(el,a,dep-1);
        }
      }
    }
  }
  
  void run(){
    cin >> h;
    try{
      ask(0);
      if(SZ(d[0]) == 1){
        dfs(d[0][0],0);
      }else{
        dfs(d[0][0],0);
        reverse(ALL(path));
        dfs(d[0][1],0);
      }
      while(1){
        int gl = (SZ(path)+1)/2;
        path.resize(gl);
        int pom = path.back();
        debug(gl, pom);
        for(int el:d[pom]){
          if(d.find(el) == d.end()){
            if(gl < 4){
              dfs(el,pom);
            }else{
              back_track(el, pom, h - gl - 1);
            }
          }
        }
      }
    }catch(...){
      cout << "! " << res + 1 << endl;
    }
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}