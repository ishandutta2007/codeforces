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

const int P = 1e9 + 7;

struct Sol{
  int n,p;
  int pot(int a,int w){
    int r = 1;
    while(w){
      if(w & 1){
        r = r * a % P;
      }
      a = a * a % P;
      w/=2;
    }
    return r;
  }
  int mul(int a,int b){
    return a * b % P;
  }
  void sub(int &a,int b){
    a -= b;
    if(a < 0)a += P;
  }
  void add(int &a,int b){
    a += b;
    if(a >= P) a -= P;
  }
  vector<int> x;
  int sumuj(int i){
    int res = 0;
    for(int j = i; j < n; j++){
      add(res, pot(p,x[j]));
    }
    debug(res);
    return res;
  }
  void run(){
    cin >> n >> p;
    x.resize(n);
    R(i,n){
      cin >> x[i];
    }
    if(p == 1){
      cout << (n & 1) << endl;
      return;
    }
    
    sort(ALL(x));
    reverse(ALL(x));
    int i = 0;
    int ile = 0;
    int k = 0;
    while(1){
//       while(i + 1 < n && x[i] == x[i+1]) i+=2;
      ile = 1;
      k = x[i];
      i++;
      while(i < n && ile != 0){
        while(ile < n && k != x[i]){
          ile *= p;
          k--;
        }
        if(ile >= n){
          int res = mul(ile%P, pot(p,k));
          debug(res);
          sub(res,sumuj(i));
          cout << res << "\n";
          return;
        }
        ile--;
        i++;
      }
      if(i == n){
        cout << mul(ile, pot(p,k)) << "\n";
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