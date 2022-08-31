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


const int MAX = 1e6 + 5;
int kro[MAX];

int dziel(int pom){
  int res = 1;
  if(pom % 2 == 0){
    int ile = 0;
    while(pom % 2 == 0){
      pom /= 2;
      ile ++;
    }
    if(ile & 1){
      pom *= 2;
    }
  }
  for(int x = 3;x * x <= pom; x+=2){
    if(pom % x == 0){
      int ile = 0;
      while(pom % x == 0){
        pom /= x;
        ile ++;
      }
      if(ile & 1){
        pom *= x;
      }
    }
  }
  return res * pom;
}

struct Sol{
  vector<int> a;
  int n;
  int res0 = 1, res1 = 1;
  void run(){
    cin >> n;
    a.resize(n);
    R(i,n){
      int pom;
      cin >> pom;
      a[i] = dziel(pom);
      kro[a[i]]++;
      if(kro[a[i]] > res0) res0++;
    }
    res1 = res0;
    for(int i:a){
      if(i != 1 && kro[i] % 2 == 0){
        kro[1] += kro[i];
        kro[i] = 0;
      }
    }
    maxi(res1, kro[1]);
    int q;
    cin >> q;
    while(q--){
      int pom;
      cin >> pom;
      if(pom == 0){
        cout << res0 << "\n";
      }else{
        cout << res1 << "\n";
      }
    }
    
    kro[1] = 0;
    R(i,n){
      kro[a[i]] = 0;
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