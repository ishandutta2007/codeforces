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

const int MAX = 200100;
int n,k;
vector<int> d[MAX];
int res = 0;
struct info{
  int t[5];
  int cale;
  int ile;
  info(){
    R(i,k)t[i] = 0;
    t[0] = 1;
    cale = 0;
    ile = 1;
  };
  void lacz(info x){
    res += cale *  x.ile + ile * x.cale;
    R(i,k)R(j,k){
      if(i + j + 1 > k){
        res += 2 * t[i] * x.t[j];
      }else{
        if(i == 0 && j== 0) debug(t[i],x.t[j]);
        res += t[i] * x.t[j];
      }
    }
    R(i,k-1){
      t[i+1] += x.t[i];
    }
    t[0] += x.t[k-1];
    cale += x.t[k-1];
    cale += x.cale;
    ile  += x.ile;
  }
};
info dfs(int a,int oj){
  info x;
  for(int el:d[a])if(el != oj){
    x.lacz(dfs(el,a));
    debug(el,res);
  }
  debug(a, x.t[0]);
  return x;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  
  info x = dfs(0,-1);
  cout << res << "\n";
}