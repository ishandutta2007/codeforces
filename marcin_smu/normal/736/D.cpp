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

const int C = 4010;

const int MAX = 500010;
bitset<C> g[MAX];
int n,m;
PII x[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,m){
    cin >> x[i].FI >> x[i].SE;
    x[i].FI--;
    x[i].SE--;
    g[x[i].FI][x[i].SE] = 1;
  }
  R(i,n){
    debug(g[i]);
  }
  cerr << "\n";
  
  
  
  R(i,n){
    g[i][i+n] = 1;
  }
  
  R(i,n){
    debug(g[i]);
  }
  cerr << "\n";
  R(i,n){
    int kt = -1;
    for(int j = i; j < n; j++){
      if(g[j][i]){
        kt = j;
        break;
      }
    }
    swap(g[kt], g[i]);
    R(j,n)if(j!=i){
      if(g[j][i]){
        g[j] ^= g[i];
      }
    }
  }
  R(i,n){
    debug(g[i]);
  }
  R(i,m){
    cout << (g[x[i].SE][x[i].FI+n] ? "NO" : "YES") << "\n";
  }
  
  
  
  
}