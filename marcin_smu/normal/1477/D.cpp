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
  void odw(vector<int>& x){
    vector<int> res(n);
    R(i,n){
      res[x[i]] = i;
    }
    swap(res, x);
  }
  void run(){
    cin >> n >> m;
    vector<vector<int>> d(n),res(n);
    R(i,m){
      int a,b;
      cin >> a >> b;
      a--;b--;
      if(a > b)swap(a,b);
      d[b].PB(a);
    }
    vector<int> zle;
    vector<int> czzle(n);
    vector<int> ost(n);
    vector<int> root(n);
    vector<int> par(n);
    R(i,n){
      for(int el:d[i]){
        ost[el] = i;
      }
      if(SZ(d[i]) == i){
        zle.PB(i);
      }else{
        vector<int> xx;
        R(j,SZ(zle)){
          if(ost[zle[j]] != i){
            xx.PB(zle[j]);
            zle[j] = zle.back();
            zle.pop_back();
            j--;
          }
        }
        if(SZ(xx)){
          root[i] = SZ(xx);
          for(int el:xx){
            par[el] = i;
          }
        }else{
          R(j,i){
            if(ost[j] != i){
              if(root[j]){
                root[j]++;
                par[i] = j;
              }else{
                debug(j,par[j]);
                if(root[par[j]] > 1){
                  root[par[j]]--;
                  par[j] = i;
                  root[i] = 1;
                }else{
                  root[par[j]] = 0;
                  par[par[j]] = j;
                  par[i] = j;
                  root[j] = 2;
                }
              }
              break;
            }
          }
        }
      }
      debug(zle, root, par);
    }
    debug(SZ(zle));
    for(int el:zle){
      czzle[el] = 1;
    }
    debug(zle, root, par);
    R(i,n)if(!czzle[i]){
      if(root[i] == 0){
        res[par[i]].PB(i);
      }
    }
    vector<int> p,q;
    R(i,n)if(czzle[i]){
      p.PB(i);
      q.PB(i);
    }else if(root[i]){
      assert(root[i] == SZ(res[i]));
      p.PB(i);
      for(int el:res[i]){
        p.PB(el);
        q.PB(el);
      }
      q.PB(i);
    }
    odw(p);odw(q);
    for(int el:p)cout << el + 1 << " ";
    cout << "\n";
    for(int el:q)cout << el + 1 << " ";
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