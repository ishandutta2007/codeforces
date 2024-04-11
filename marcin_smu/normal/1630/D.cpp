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

struct Sol{
  vector<int> t;
  int n,m;
  void run(){
    cin >> n >> m;
    t.resize(n);
    R(i,n){
      cin >> t[i];
    }
    int cd = 0;
    R(i,m){
      int pom;
      cin >> pom;
      cd = __gcd(pom, cd);
    }
    debug(cd);
    int res1 = 0, res2 = 0;
    R(i,cd){
      debug(i);
      int parz = 0;
      int ak = 0;
      int mi = 1e10;
      for(int j = i; j < n; j += cd){
        debug(t[j]);
        if(t[j] < 0)parz++;
        ak += abs(t[j]);
        mini(mi, abs(t[j]));
      }
      debug(ak, parz, mi);
      if(parz % 2){
        res1 += ak;
        res2 += ak - 2 * mi;
      }else{
        res2 += ak;
        res1 += ak - 2 * mi;
      }
    }
    cout << max(res1,res2) << "\n";
  }
};


int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}