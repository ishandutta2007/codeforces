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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#define MAX 100010
int n;
vector<int> d[MAX];
int siz[MAX];
int res[MAX];
int dfs(int nr,int oj){
  siz[nr] = 1;
  for(int ak:d[nr]){
    if(ak != oj)
      siz[nr] += dfs(ak,nr);
  }
  return siz[nr];
}
void licz(int nr,int oj,int war){
  res[nr] = war;
  for(int ak:d[nr])if(ak != oj)
    licz(ak,nr,war + (siz[nr] - siz[ak] + 1));
}

void add_edge(int a,int b){
  d[a].PB(b);
  d[b].PB(a);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n-1){
    int pom;
    cin >> pom;
    add_edge(i+1,pom-1);
  }
  dfs(0,-1);
  licz(0,-1,2);
  R(i,n){
    cout << res[i] * .5 << " ";
  }
  cout << "\n";
}