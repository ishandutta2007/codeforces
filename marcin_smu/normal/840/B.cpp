#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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

const int MAX = 3e5 + 10;


int n,m;
int t[MAX],vis[MAX];
vector<PII> d[MAX];
vector<int> res;

bool dfs(int v){
  if(vis[v])return 0;
  vis[v] = 1;
  bool pom = t[v] == 1;
  for(PII el:d[v]){
    if(dfs(el.FI)){
      pom ^= 1;
      res.PB(el.SE);
    }
  }
  return pom;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  int kt = 0;
  int il = 0;
  bool minus = 0;
  R(i,n){
    cin >> t[i];
    if(t[i] == 1){
      il++;
    }
    if(t[i] == -1){
      minus = 1;
      kt = i;
    }
  }
  if(minus == 0 && il % 2 == 1){
    cout << "-1\n";
    return 0;
  }
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB({b,i});
    d[b].PB({a,i});
  }
  dfs(kt);
  cout << SZ(res) << "\n";
  for(int el : res){
    cout << el+1 << "\n";
  }
}