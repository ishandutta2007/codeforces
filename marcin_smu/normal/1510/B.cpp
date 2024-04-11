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

int D,n;
vector<int> sn, sm, vis;
vector<vector<int>> d;
bool dfs(int v){
  if(vis[v])return 0;
  vis[v] = 1;
  for(int el:d[v]){
    if(sm[el] == -1 || dfs(sm[el])){
      sn[v] = el;
      sm[el] = v;
      return 1;
    }
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> D >> n;
  vector<int> t(n);
  R(i,n){
    string pom;
    cin >> pom;
    int x = 0;
    R(j,D){
      if(pom[j] == '1'){
        x |= 1 << j;
      }
    }
    t[i] = x;
  }
  sort(ALL(t), [](int a,int b){
    return __builtin_popcount(a) > __builtin_popcount(b);
  });
  d.resize(n);
  R(i,n)R(j,i){
    if((t[i] & t[j]) == t[i]){
      d[i].PB(j);
    }
  }
  sn.resize(n,-1);
  sm.resize(n,-1);
  vis.resize(n);
  R(i,n){
    dfs(i);
    R(j,n)vis[j] = 0;
  }
  debug(sn);
  vector<int> res;
  R(i,n)if(!vis[i]){
    int ak = i;
    while(ak != -1){
      vis[ak] = 1;
      int pom = sm[ak] != -1 ? t[ak] ^ t[sm[ak]] : t[ak];
      debug(t[ak], pom);
      R(kt,D){
        if((pom >> kt) & 1){
          res.PB(kt);
        }
      }
      ak = sm[ak];
    }
    res.PB(-1);
  }
  res.pop_back();
  reverse(ALL(res));
  cout << SZ(res) << "\n";
  for(int el:res){
    if(el == -1)
      cout << "R ";
    else
      cout << el << " ";
  }
  cout << "\n";
}