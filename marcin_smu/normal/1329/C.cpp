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
  int h,g;
  vector<int> val;
  vector<int> wyn;
  int n;
  vector<int> gl;
  
  void dfs2(int x){
    gl.PB(x);
    if(2 * x < n){
      dfs2(2 * x);
      dfs2(2 * x + 1);
    }
  }
  int wynn = 0;
  pair<int,vector<int>> dfs(int nr,int wys){
    vector<int> res;
    if(wys == g){
      gl.clear();
      dfs2(nr);
      sort(ALL(gl), [&](int a,int b){
        return val[a] > val[b];
      });
      swap(gl,res);
    }else{
      int ka, kb;
      vector<int> a,b;
      tie(ka, a) = dfs(nr*2, wys+1);
      tie(kb, b) = dfs(nr*2+1, wys+1);
      while(SZ(a) && val[a.back()] < kb){
        a.pop_back();
      }
      while(SZ(b) && val[b.back()] < ka){
        b.pop_back();
      }
      res.PB(nr);
      int i = 0, j = 0;
      while(i < SZ(a) || j < SZ(b)){
        if(j == SZ(b) || (i != SZ(a) && val[a[i]] > val[b[j]])){
          res.PB(a[i]);
          i++;
        }else{
          res.PB(b[j]);
          j++;
        }
      }
    }
    int pom = val[res.back()];
    wyn[res.back()] = 0;
    wynn += pom;
    res.pop_back();
    return {pom,res};
  }
  void run(){
    cin >> h >> g;
    n = (1 << h);
    val.resize(n);
    wyn.resize(n,1);
    R(i,n)if(i){
      cin >> val[i];
    }
    dfs(1,1);
    cout << wynn << "\n";
    for(int i = n - 1; i > 0; i--){
      if(wyn[i]){
        cout << i << " ";
      }
    }
    cout << "\n";
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