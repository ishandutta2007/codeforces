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

void nope(){
  cout << "NO\n";
  exit(0);
}
vector<set<int>> d;
vector<int> fib;

map<vector<PII>, bool> pam;

vector<int> vis;
int ivis = 5;
vector<PII> gd;
int gl1,gl2; 
int dfs(int v,int oj){
  int siz = 1;
  vis[v] = ivis;
  debug(v);
  for(int el:d[v])if(el != oj){
    siz += dfs(el,v);
  }
  if(siz == gl1){
    gd.PB({v,oj});
  }else if(siz == gl2){
    gd.PB({oj,v});
  }
  return siz;
}
int n;
bool licz(int siz, int root, vector<PII> zak){
  if(fib[siz] <= 3)return 1;
  gl1 = fib[siz-1];
  gl2 = fib[siz-2];
  
  ivis++;
  debug(fib[siz]);
  gd.clear();
  dfs(root, -1);
  
  vector<PII> pom;
  for(PII el:zak){
    if(vis[el.FI] == ivis){
      pom.PB(el);
    }else if(vis[el.SE] == ivis){
      swap(el.FI,el.SE);
      pom.PB(el);
    }
  }
  sort(ALL(pom));
  debug(pom);
  auto xxx = pam.find(pom);
  if(xxx != pam.end())return xxx->SE; 
  bool res = &pam[pom];
  res = 0;
  R(i,SZ(gd)){
    PII el = gd[i];
    pom.PB(el);
    d[el.FI].erase(el.SE);
    d[el.SE].erase(el.FI);
    if(licz(siz - 1, el.FI, pom) && licz(siz - 2, el.SE, pom))return res = 1;
    d[el.FI].insert(el.SE);
    d[el.SE].insert(el.FI);
    pom.pop_back();
  }
  return 0;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  fib.resize(30);
  fib[0] = fib[1] = 1;
  for(int i = 2; i<30; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }
  debug(fib);
  cin >> n;
  d.resize(n);
  vis.resize(n);
  int kt = 0;
  while(fib[kt] < n)kt++;
  if(fib[kt] != n)nope();
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].insert(b);
    d[b].insert(a);
  }
  if(licz(kt, 0, {})){
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }
}