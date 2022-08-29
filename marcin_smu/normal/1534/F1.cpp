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
    debug("edge",a,b);
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

int id = 0;
vector<vector<int>> ids;
vector<string> x;
int n,m;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  x.resize(n);
  ids.resize(n,vector<int>(m));
  R(i,n){
    cin >> x[i];
    R(j,m)if(x[i][j] == '#'){
      ids[i][j] = id++;
    }
  }
  SSS graf(id);
  vector<int> ost(m + 1, -1);
  for(int i = n - 1; i >= 0; i--){
    R(j,m){
      if(x[i][j] == '#'){
        for(int k = max(0ll, j - 1); k <= j + 1; k++){
          if(ost[k] != -1){
            graf.add_edge(ost[k], ids[i][j]);
          }
        }
      }
    }
    R(j,m){
      if(x[i][j] == '#'){
        ost[j] = ids[i][j];
      }
    }
    R(j,m-1){
      if(x[i][j] == '#' && x[i][j + 1] == '#'){
        graf.add_edge(ids[i][j], ids[i][j + 1]);
        graf.add_edge(ids[i][j + 1], ids[i][j]);
      }
    }
    if(i != 0){
      R(j,m){
        if(x[i][j] == '#' && x[i - 1][j] == '#'){
          graf.add_edge(ids[i-1][j], ids[i][j]);
        }
      } 
    }
  }
  graf.licz();
  auto res = graf.stworzgraf();
  debug(res);
  int wyn = 0;
  for(auto &el:res){
    if(SZ(el) == 0){
      wyn ++;
    }
  }
  cout << wyn << "\n";
}