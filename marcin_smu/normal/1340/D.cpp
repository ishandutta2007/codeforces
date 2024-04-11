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

vector<vector<int>> d;
vector<PII> res;
int t = 1e9,n;
void dfs(int v,int oj, int kt){
  int il = max(0ll, SZ(d[v]) - kt - 1);
  int nowy = max(0ll, kt - SZ(d[v]) + 1);
  debug(v,oj,kt,il,nowy);
  for(int el:d[v])if(el != oj){
    if(il == 0){
      if(t != nowy){
        res.PB({v,nowy});
        t = nowy;
      } 
    }
    t++;
    res.PB({el,t});
    dfs(el, v, t - 1);
    il--;
  }
  if(oj != -1){
    if(kt != t){
      t = kt;
      res.PB({v,t});
    }
    t++;
    res.PB({oj, t});
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  if(n == 1){
    cout << "1\n1 0\n";
    return 0;
  }
  d.resize(n);
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  d[0].PB(-1);
  dfs(0,-1,SZ(d[0]) - 1);
  cout << SZ(res) << "\n";
  for(PII el:res){
    cout << el.FI + 1 << " " << el.SE << "\n";
  }
}