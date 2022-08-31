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

const int MAX = 1001;
int n;
vector<PII> d[MAX];
int dfs(int v,int oj){
  if(SZ(d[v]) == 1){
    return v+1;
  }
  for(PII el:d[v])if(el.FI != oj){
    return dfs(el.FI,v);
  }
  assert(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n-1){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;c/=2;
    d[a].PB({b,c});
    d[b].PB({a,c});
  }
  R(i,n){
    if(SZ(d[i]) == 2){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  vector<vector<int>> op;
  R(i,n){
    for(PII el:d[i])if(el.FI < i){
      
      vector<int> p1;
      R(j,SZ(d[el.FI])){
        if(d[el.FI][j].FI != i){
          p1.PB(dfs(d[el.FI][j].FI, el.FI));
        }
        if(SZ(p1) == 2)break;
      }
      
      
      vector<int> p2;
      R(j,SZ(d[i])){
        if(d[i][j].FI != el.FI){
          p2.PB(dfs(d[i][j].FI, i));
        }
        if(SZ(p2) == 2)break;
      }
      debug(p1,p2);
      
      if(SZ(p1) == 0){
        p1.PB(el.FI + 1);
        p1.PB(el.FI + 1);
      }else
        op.PB({p1[0],p1[1],-el.SE});
      
      if(SZ(p2) == 0){
        p2.PB(i + 1);
        p2.PB(i + 1);
      }else
        op.PB({p2[0],p2[1],-el.SE});
      
      
      R(j,2){
        op.PB({p1[j],p2[j],el.SE});
      }
    }
  }
  cout << SZ(op) << "\n";
  for(auto el:op){
    R(i,3){
      cout << el[i] << " ";
    }
    cout << "\n";
  }
}