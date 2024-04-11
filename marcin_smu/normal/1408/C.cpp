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
  int n,l;
  vector<int> t;
  vector<LD> odl1,odl2;
  void run(){
    cin >> n >> l;
    t.resize(n+2);
    odl1.resize(n+2);
    odl2.resize(n+2);
    t[0] = 0;
    R(i,n){
      cin >> t[i + 1];
    }
    t[n+1] = l;
    int ak = 0;
    R(i,n+1){
      odl1[i+1] = odl1[i] + (LD)(t[i+1] - ak) / (i + 1);
      ak = t[i+1];
    }
    ak = l;
    for(int i = n; i >= 0; i--){
      odl2[i] = odl2[i+1] + (LD)(ak - t[i]) / (n - i + 1);
      ak = t[i];
    }
    debug(odl1);
    debug(odl2);
    R(i,n+1){
      if(abs(odl1[i] - odl2[i]) < 1e-6){
        cout << odl1[i] << "\n";
        return;
      }
      if(odl1[i] < odl2[i] && odl1[i+1] > odl2[i+1]){
        LD x = 0;
        if(odl1[i] < odl2[i+1]){
          x = (LD)(odl2[i+1] - odl1[i]) * (i + 1);
          debug("A");
        }else{
          x = (LD)(odl1[i] - odl2[i+1]) * (n - i + 1);
          debug("B");
        }
        debug(x,t[i+1] - t[i]);
        cout << max(odl1[i],odl2[i+1]) + (LD)(t[i+1] - t[i] - x) / (n + 2) << "\n";
        return;
      }
    }
  }
};

int32_t main() {
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