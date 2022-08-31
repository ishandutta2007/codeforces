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

const int MAX = 200010;
int n,m,k;
vector<int> d[MAX];
int spec[MAX];
void bfs(int x,vector<int> &odl){
  odl.resize(n);
  vector<int> kol;
  kol.PB(x);
  odl[x] = 1;
  R(i,SZ(kol)){
    int ak = kol[i];
    for(int el:d[ak])if(!odl[el]){
      odl[el] = odl[ak] + 1;
      kol.PB(el);
    }
  }
}

vector<int> dist[2];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> k;
  R(i,k){
    cin >> spec[i];
    spec[i]--;
  }
  R(i,m){
    int a,b;
    cin >> a >> b;a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  bfs(0,dist[0]);
  bfs(n-1,dist[1]);
  int res = dist[0][n-1] - 1;
  debug(res);
  vector<PII> t;
  R(i,k){
    t.PB({dist[0][spec[i]], dist[1][spec[i]]});
  }
  sort(ALL(t));
  int res2 = 0;
  R(i,k-1){
    maxi(res2, min(t[i].FI + t[i+1].SE, t[i+1].FI + t[i].SE));
  }
  res2--;
  cout << min(res,res2) << "\n";
}