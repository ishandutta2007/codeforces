#include <bits/stdc++.h>

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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const int MAX = 300100;
int n,m;
int vis[MAX];
vector<int> d[MAX];
vector<PII> zap[MAX];
int zle[MAX];
int par[MAX];
void dfs(int v,int oj){
  debug("dfs",v,oj);
  vis[v] = 1;
  par[v] = oj;
  for(int el : d[v])if(el != oj){
    debug(el);
    if(!vis[el]){
      dfs(el, v);
    }else if(vis[el] == 1){
      int ak = v;
      int mi = v;
      int ma = v;
      do{
        ak = par[ak];
        mini(mi,ak);
        maxi(ma,ak);
      }while(ak != el);
      maxi(zle[ma],mi);
      debug("zly", mi,ma);
    }
  }
  vis[v] = 2;
}
int dp[MAX * 4];
int il[MAX * 4];
int nn;

void touch(int nr){
  if(il[nr]){
    int pom = il[nr] / 2;
    dp[nr*2] += pom;
    il[nr*2] += pom;
    dp[nr*2+1] += pom;
    il[nr*2+1] += pom;
    il[nr] = 0; 
  }
}

void add(int po, int ko){
  debug("add",po,ko);
  function<void(int,int,int)> rec = [&](int nr,int be,int en){
  //  debug(nr, be,en);
    if(be >= ko || po >= en)return;
    if(po <= be && en <= ko){
      dp[nr] += en - be;
      il[nr] += en - be;
      return;
    }
    touch(nr);
    rec(nr*2, be, (be + en)/2);
    rec(nr*2+1, (be + en)/2, en);
    dp[nr] = dp[nr*2] + dp[nr*2+1];
  };
  rec(1,0,nn);
}
int sum(int po,int ko){
  debug("sum",po,ko);
  int res = 0;
  function<void(int,int,int)> rec = [&](int nr,int be,int en){
    if(be >= ko || po >= en)return;
    if(po <= be && en <= ko){
      res += dp[nr];
      return;
    }
    touch(nr);
    rec(nr*2, be, (be + en)/2);
    rec(nr*2+1, (be + en)/2, en);
  };
  rec(1,0,nn);
  return res;
}

int res[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  nn=1;while(nn <= n)nn *= 2;
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  R(i,n){
    zle[i] = -1;
  }
  R(i,n){
    debug(i);
    if(!vis[i])
     dfs(i,-1);
  }
  int q;
  cin >> q;
  R(i,q){
    int l,r;
    cin >> l >> r;
    zap[r].PB({l-1, i});
  }
  int ak = 0;
  R(i,n){
    maxi(ak,zle[i]+1);
    add(ak,i+1);
    for(auto el:zap[i+1]){
      res[el.SE] = sum(el.FI, i+1);
    }
  }
  R(i,q){
    cout << res[i] << "\n";
  }
}