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

vector<int> val;
vector<PII> zap;
vector<PII> ed;
vector<int> us;
vector<int> f;
vector<int> siz;
vector<vector<int>> kt;
vector<int> waz;
vector<vector<int>> d;
int find(int a){
  return f[a] == a ? a : find(f[a]);
}

vector<PII> hist;
bool uni(int a,int b){
  a = find(a);
  b = find(b);
  if(a == b)return 0;
  if(siz[a] > siz[b])swap(a,b);
  f[a] = b;
  d[b].PB(a);
  siz[b] += siz[a];
  hist.PB({a,b});
  return 1;
}


void dfs(int v,int gd){
  if(val[v] != 0)kt[gd].PB(val[v]);
  for(int el:d[v])dfs(el, gd);
}

void cof(){
  int a,b;
  tie(a,b) = hist.back();
  hist.pop_back();
  siz[b] -= siz[a];
  f[a] = a;
  d[b].pop_back();
  dfs(a, a);
  sort(ALL(kt[a]));
}

vector<int> gd;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n,m,q;
  cin >> n >> m >> q;
  val.resize(n);
  f.resize(n);
  gd.resize(n+1);
  siz.resize(n);
  d.resize(n);
  kt.resize(n);
  R(i,n){
    f[i] = i;
    siz[i] = 1;
    cin >> val[i];
    gd[val[i]] = i;
  }
  ed.resize(m);
  R(i,m){
    cin >> ed[i].FI >> ed[i].SE;
    ed[i].FI--;
    ed[i].SE--;
  }
  zap.resize(q);
  us.resize(m);
  R(i,q){
    cin >> zap[i].FI >> zap[i].SE;
    zap[i].SE--;
    if(zap[i].FI == 2){
      us[zap[i].SE] = 1;
    }
  }
  R(i,m){
    if(us[i] == 0){
      uni(ed[i].FI,ed[i].SE);
    }
  }
  waz.resize(q);
  for(int i = q-1;i >= 0;i--){
    if(zap[i].FI == 2){
      int j = zap[i].SE;
      if(uni(ed[j].FI,ed[j].SE)){
        waz[i] = 1;
      }
    }
  }
  R(i,n)if(f[i] == i){
    dfs(i,i);
    sort(ALL(kt[i]));
    debug(i,kt[i]);
  }
  R(i,q){
    if(zap[i].FI == 1){
      int pom = find(zap[i].SE);
      debug(pom, kt[pom]);
      int res = 0;
      while(!kt[pom].empty()){
        int ak = kt[pom].back();
        kt[pom].pop_back();
        if(find(gd[ak]) == pom){
          res = ak;
          break;
        }
      }
      cout << res << "\n";
      if(res){
        val[gd[res]] = 0;
      }
    }else if(waz[i]){
      cof();
    }
  }
}