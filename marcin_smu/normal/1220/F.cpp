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

int n;
vector<int> licz(vector<int> x){
  vector<int> wyn(n);
  int res = 0;
  vector<PII> st;
  R(i,n-1){
    wyn[i] = res;
    int il = 0;
    while(SZ(st) && st.back().FI > x[i]){
      il = max(il, st.back().SE) + 1;
      st.pop_back();
    }
    st.PB({x[i], il});
    maxi(res, SZ(st) + st.back().SE);
  }
  wyn[n-1] = res;
  return wyn;
}
const int MAX = 200100;
int p[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  int gd = -1;
  R(i,n){
    cin >> p[i];
    if(p[i] == 1){
      gd = i;
    }
  }
  vector<int> pom;
  for(int i = gd + 1; i < n;i++){
    pom.PB(p[i]);
  }
  R(i,gd){
    pom.PB(p[i]);
  }
  auto a = licz(pom);
  reverse(ALL(pom));
  auto b = licz(pom);
  debug(a);
  debug(b);
  int gl = 1e9;
  int kt = 0;
  R(i,n){
    int ak = max(a[i], b[n-i-1]) + 1;
    if(gl > ak){
      gl = ak;
      kt = i;
    }
  }
  cout << gl << " " << (kt + gd  + 1) % n << "\n";
}