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

const int MAX = 100100;
const int INF = 1e9;
const int C = 61;
int n,t[MAX];
int zap[C];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  vector<int> kol;
  vector<int> res(n+1,INF);
  res[n] = 0;
  R(i,n){
    cin >> t[i];
    kol.PB(i);
    R(j,C)if((t[i] >> j) & 1){
      zap[j]++;
    }
  }
//  sort(t,t+n);
  R(bit,C){
    vector<int> ak(n+1,INF);
    vector<int> zer;
    vector<int> jed;
    R(i,n + 1){
      mini(ak[SZ(zer)], res[i] + SZ(jed) + n - zap[bit] - SZ(zer));
      mini(ak[n - zap[bit] + SZ(jed)], res[i] + SZ(zer) + zap[bit] - SZ(jed));
      if(i == n)break;
      int el = kol[i];
      if((t[el] >> bit) & 1){
        jed.PB(el);
      }else
        zer.PB(el);
    }
    for(int el:jed){
      zer.PB(el);
    }
    swap(zer, kol);
    swap(res, ak);
    //debug(res);
  }
  cout << res[n] << "\n";
}