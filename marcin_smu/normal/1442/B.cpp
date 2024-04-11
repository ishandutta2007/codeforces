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

const int P = 998244353;
struct Sol{
  int n,k;
  vector<int> a;
  vector<int> pop;
  vector<int> nast;
  vector<int> b;
  vector<int> inb;
  
  void us(int x){
    if(pop[x] != -1){
      nast[pop[x]] = nast[x];
    }
    if(nast[x] != -1){
      pop[nast[x]] = pop[x];
    }
  }
  void run(){
    cin >> n >> k;
    pop.resize(n,-1);
    nast.resize(n,-1);
    inb.resize(n);
    a.resize(n);
    R(i,n){
      cin >> a[i];
      a[i]--;
    }
    R(i,n-1){
      pop[a[i+1]] = a[i];
      nast[a[i]] = a[i+1];
    }
    b.resize(k);
    int res = 1;
    R(i,k){
      cin >> b[i];
      b[i]--;
      inb[b[i]] = 1;
    }
    R(i,k){
      bool x = 1,y = 1;
      if(nast[b[i]] == -1 || inb[nast[b[i]]]){
        x = 0;
      }
      if(pop[b[i]] == -1 || inb[pop[b[i]]]){
        y = 0;
      }
      if(x && y){
        res += res;
        if(res >= P)res -= P;
      }
      if(x == 0 && y == 0){
        cout << "0\n";
        return;
      }
      if(x){
        us(nast[b[i]]);
      }else{
        us(pop[b[i]]);
      }
      inb[b[i]] = 0;
    }
    cout << res << "\n";
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