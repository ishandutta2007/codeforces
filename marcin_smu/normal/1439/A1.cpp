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
  int n,m;
  vector<string> t;
  vector<vector<PII>> res;
  void rusz(vector<PII> pom){
    res.PB(pom);
    for(PII el:pom){
      t[el.FI][el.SE] ^= 1;
    }
  }
  void run(){
    cin >> n >> m;
    t.resize(n);
    R(i,n){
      cin >> t[i];
      R(j,m)t[i][j] -= '0';
    }
    R(i,n-2){
      R(j,m-2){
        if(t[i][j] == 1){
          rusz({{i,j},{i+1,j},{i,j+1}});
        }
      }
    }
    R(i,n-2){
      vector<PII> pom;
      if(t[i][m-1]){
        pom.PB({i,m-1});
      }
      if(t[i][m-2]){
        pom.PB({i,m-2});
      }
      if(SZ(pom)){
        R(j,2){
          if(SZ(pom) != 3){
            pom.PB({i+1,m-j-1});
          }
        }
        rusz(pom);
      }
    }
    
    R(i,m-2){
      vector<PII> pom;
      if(t[n-1][i]){
        pom.PB({n-1,i});
      }
      if(t[n-2][i]){
        pom.PB({n-2,i});
      }
      if(SZ(pom)){
        R(j,2){
          if(SZ(pom) != 3){
            pom.PB({n-j-1,i+1});
          }
        }
        rusz(pom);
      }
    }
    while(1){
      vector<PII> zle;
      vector<PII> dobre;
      R(i,2)R(j,2){
        if(t[n-i-1][m-j-1]){
          zle.PB({n-i-1,m-j-1});
        }else{
          dobre.PB({n-i-1,m-j-1});
        }
      }
      if(SZ(zle) == 0)break;
      if(SZ(zle) == 2){
        dobre.PB(zle[0]);
        rusz(dobre);
      }else if(SZ(zle) == 1){
        zle.PB(dobre[0]);
        zle.PB(dobre[1]);
        rusz(zle);
      }else{
        zle.resize(3);
        rusz(zle);
      }
    }
    cout << SZ(res) << "\n";
    R(i,SZ(res)){
      for(PII el:res[i]){
        cout << el.FI + 1 << " " << el.SE + 1 << " ";
      }
      cout << "\n";
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
    Sol sol;
    sol.run();
  }
}