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

int n,m;
vector<vector<PII>> d;
vector<int> vis;
vector<int> res;
vector<int> vtyp;
vector<int> vval;
bool juz;
int x;
vector<int> wart;
void nope(){
  cout << "NO\n";
  exit(0);
}
void dfs1(int v,int typ,int val){
  debug(v,typ,val);
  if(vis[v]){
    if(typ == vtyp[v]){
      if(val != vval[v])
        nope();
    }else{
      int pomx = (val - vval[v]) / 2;
      if(!typ)pomx*=-1;
      debug(pomx, juz);
      if(juz == 0){
        juz = 1;
        x = pomx;
      }else{
        if(x != pomx)nope();
      }
    }
    return;
  }
  vis[v] = 1;
  vval[v] = val;
  vtyp[v] = typ;
  if(typ){
    wart.PB(-val);
  }else{
    wart.PB(val);
  }
  for(PII el:d[v])dfs1(el.FI, !typ, el.SE - val);
}
void dfs2(int v){
  if(vis[v] == 2)return;
  vis[v] = 2;
  if(vtyp[v]){
    res[v] = vval[v] - x;
  }else
    res[v] = vval[v] + x;
  for(PII el:d[v])dfs2(el.FI);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  d.resize(n);
  vis.resize(n);
  vtyp.resize(n);
  vval.resize(n);
  res.resize(n);
  R(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;c*=2;
    d[a].PB({b,c});
    d[b].PB({a,c});
  }
  R(i,n)if(!vis[i]){
    wart.clear();
    juz = 0;
    dfs1(i,0,0);
    if(!juz){
      sort(ALL(wart));
      x = -wart[SZ(wart)/2];
    }
    dfs2(i);
  }
  debug(res,vval,vtyp);
  cout << "YES\n";
  R(i,n){
    if(res[i] < 0)cout << "-";
    res[i] = abs(res[i]);
    cout << res[i]/2 << "." << res[i]%2*5 << " ";
  }
  cout << "\n";
}