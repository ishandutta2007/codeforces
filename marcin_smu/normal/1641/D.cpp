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

int n,m;
const int inf = 1e12;
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  map<int,int> scal;
  vector<vector<int>> x(n,vector<int>(m));
  vector<int> w(n); 
  R(i,n){
    R(j,m){
      cin >> x[i][j];
      scal[x[i][j]] = 0;
    }
    cin >> w[i];
  }
  int ile = 0;
  for(auto &el:scal){
    el.SE = ile;
    ile++;
  }
  R(i,n)R(j,m)x[i][j] = scal[x[i][j]];
  
  debug(x);
  
  int wyn = inf;
  vector<int> col(ile);
  const int C = 16;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  R(_,70){
    R(i,ile){
      col[i] = uniform_int_distribution<int>(0, C-1)(rng);
    }
    vector<int> res(1 << C, inf);
    R(i,n){
      int pom = 0;
      R(j,m){
        pom |= 1 << col[x[i][j]];
      }
      mini(res[pom], w[i]);
    }
    R(i,1 << C){
      R(j,C)if(((i >> j) & 1) == 0){
        mini(res[i + (1 << j)], res[i]);
      }
    }
    R(i,1 << C){
      mini(wyn, res[i] + res[(1 << C) - 1 - i]);
    }
  }
  if(wyn == inf){
    cout << "-1\n";
  }else{
    cout << wyn << "\n";
  }
}