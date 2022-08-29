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

int n,k,l,r;
int res = -1;

void spr(int ob){
  if(ob <= 0)return;
  
  int kk = k - r - n * ob;

  if(kk < 0)return;
  
  int res1 = kk / ob;
  int res2 = kk % ob;
  if(res1 > n){
    res2 += ob * (res1 - n);
    res1 = n;
  }
  debug(res2,res1,ob,kk);
  if(res2 < r - 1 - n + res1){
    int pom = r - 1 - n + res1 - res2;
    debug(pom);
    int il = (pom + ob) / (ob + 1);
    res1 -= il;
    res2 += ob * il;
  }
  debug(res2,res1);
  assert(res2 >= r - 1 - n + res1);
  if(res2 > r || res1 < res2){
    return;
  }
  maxi(res,res1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> l >> r >> k;
  r = (r - l + 1 + n) % n;
  if(r == 0)r = n;
  if(k < r){
    cout << "-1\n";
    return 0;
  }
  if(k <= 2 * r){
    int jed = max(0ll, 2 * r - k - 1);
    cout << n - jed << "\n";
    return 0;
  }
  vector<int> can;
  if(k / n < 1e6){
    for(int ob = 0; ob * n <= k; ob ++){
      spr(ob);
    }
  }else{
    R(i,n+1){
      int ob = k / (n + i);
      spr(ob);
      spr(ob + 1);
      spr(ob - 1);
    }
  }
  cout << res << "\n";
}