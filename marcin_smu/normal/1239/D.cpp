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

struct SSS{
  vector<vector<int>> d,drev; vector<int> ord,ss,cz;
  int is,n;
  SSS(int _n) : n(_n) {
    d.resize(n); drev.resize(n);
    cz.resize(n); ss.resize(n, -1);
  }
  void add_edge(int a,int b){
    d[a].PB(b); drev[b].PB(a);
  }
  void dfs(int nr){
    if(cz[nr]) return;
    cz[nr] = 1;
    for(int ak:d[nr])
      dfs(ak);
    ord.PB(nr);
  }
  void dfs2(int nr,int s){
    if(ss[nr] != -1) return;
    ss[nr] = s;
    for(int ak:drev[nr])
      dfs2(ak,s);
  }
  void licz(){
    R(i,n) dfs(i);
    is = 0;
    reverse(ALL(ord));
    for(int el:ord){
      if(ss[el] == -1){
        dfs2(el, is);
        is++;
      }
    }
  }
  vector<vector<int>> stworzgraf() {
    vector<vector<int>> res(is);
    R(i,n)for(int ak:d[i]){
      if(ss[i] != ss[ak])
        res[ss[i]].PB(ss[ak]);
    }
    for(auto &el:res){
      sort(ALL(el));
      el.resize(unique(ALL(el)) - el.begin());
    }
    return res;
  }
};

struct Sol{
  int n,m;
  void run(){
    cin >> n >> m;
    SSS ss(n);
    R(i,m){
      int a,b;
      cin >> a >> b;
      a--;b--;
      if(a != b){
        ss.add_edge(a,b);
      }
    }
    ss.licz();
    if(ss.is == 1){
      cout << "No\n";
    }else{
      vector<int> res1,res2;
      R(i,n){
        if(ss.ss[i] == 0){
          res1.PB(i);
        }else{
          res2.PB(i);
        }
      }
      swap(res1,res2);
      cout << "Yes\n";
      cout << SZ(res1) << " " << SZ(res2) << "\n";
      for(int el:res1){
        cout << el + 1 << " ";
      }
      cout << "\n";
      for(int el:res2){
        cout << el + 1 << " ";
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