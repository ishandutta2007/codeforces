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

int n,k;

int f(int x){
  return 3 * (x * x + x) + 1;
}

const int MAX = 100100;
int ile[MAX];
int a[MAX];
int spr(int x){
  int res = 0;
  R(i,n){
    int po = 0, ko = a[i] + 1;
    while(po + 1 != ko){
      int m = (po + ko) / 2;
      if(a[i] - f(m) > x){
        po = m;
      }else{
        ko = m;
      }
    }
    ile[i] = po;
    res += po;
  }
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  R(i,n){
    cin >> a[i];
  }
  int po = -4e18,ko = 2e9;
  while(po + 1 != ko){
    int m = (po + ko) >> 1;
    if(spr(m) > k){
      po = m;
    }else{
      ko = m;
    }
  }
  int pom = k - spr(ko);
  R(i,n){
    if(pom && a[i] - f(ile[i] + 1) == ko){
      ile[i]++;
      pom--;
    }
    cout << ile[i] << " ";
  }
  cout << "\n";
}