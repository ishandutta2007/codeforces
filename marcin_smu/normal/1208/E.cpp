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

const int MAX = 1e6 + 10;
int ps[MAX];
int n,w;

void dodaj(){
  multiset<int> secik;
  int l;cin >> l; l += 2;
  vector<int> t(l);
  R(i,l - 2)cin >> t[i + 1];
  int ost = 0;
  for(int i = 0; i < w; i++){
    bool zm = 0;
    if(i < l){
//       debug("dodej",i ,l);
      secik.insert(t[i]);
      zm = 1;
    }
    if(i + l > w){
      secik.erase(secik.find(t[i + l - w - 1]));
//       debug("us",i + l - w - 1, l);
      zm = 1;
    }
    if(zm == 0){
      maxi(i, w - l - 1);
    }
    int mi = *secik.rbegin();
    debug(mi);
    ps[i] += mi - ost;
    ost = mi;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> w;
  w += 2;
  R(i,n){
    dodaj();
  }
  int res = ps[0];
  R(i,w - 2){
    res += ps[1 + i];
    cout << res << " ";
  }
  cout << "\n";
}