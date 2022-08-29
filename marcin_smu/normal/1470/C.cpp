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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,k;
int ILE = 0;
#ifdef LOCAL
vector<int> t;
int imp;
#endif
int pytaj(int x){
  cout << "? " << x + 1 << endl;
#ifdef LOCAL
  ILE ++;
  assert(ILE <= 1000);
  debug(ILE);
  int xx = t[x];
  vector<int> t2(n);
  R(i,n){
    if(i == imp){
      t2[(i + 1) % n] += t[i]; 
    }else{
      t2[(i + 1) % n] += (t[i] + 1) / 2; 
      t2[(i + n - 1) % n] += t[i] / 2; 
    }
  }
  swap(t,t2);
  return xx;
#else
  int pom;
  cin >> pom;
  return pom;
#endif
}


void odp(int x){
#ifdef LOCAL
  assert(x == imp);
#endif
  cout << "! " << x + 1 << endl;
  exit(0);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  #ifdef LOCAL
  t.resize(n,k);
  imp = rng() % n;
  #endif
  int pom;
  int ko = -1;
  int po = -1;
  while(po == -1 || ko == -1){
    pom = rng() % n;
    int il = pytaj(pom);
    if(il != k){
      if(il > k){
        ko = pom;
      }else{
        po = pom;
      }
    }
  }
  po++;
  if(po == n) po = 0;
  while(1){
    int od = ko - po;
    if(od < 0)od += n;
    if(od == 1){
      odp(po);
    }
    int m = (po + od / 2) % n;
    int il = pytaj(m);
    if(il > k){
      ko = m;
    }else{
      po = m;
    }
  }
}