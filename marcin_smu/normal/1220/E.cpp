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

const int MAX = 2e5 + 10;
int n,m;
int w[MAX];
int res[MAX];
int deg[MAX];
bool vis[MAX];
vector<int> d[MAX];
void dfs(int v){
  if(vis[v] || deg[v] != 1)return;
  vis[v] = 1;
  debug(v);
  for(int el:d[v])if(vis[el] == 0){
    deg[el]--;
    maxi(res[el], res[v] + w[v]);
    dfs(el);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,n){
    cin >> w[i];
  }
  R(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    deg[a]++;
    deg[b]++;
    d[a].PB(b);
    d[b].PB(a);
  }
  int s;
  cin >> s;s--;
  deg[s]+=2;
  R(i,n)dfs(i);
  int ma = 0;
  int wyn = 0;
  R(i,n)if(!vis[i]){
    wyn += w[i];
    maxi(ma, res[i]);
  }
  cout << wyn + ma << "\n";
}