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
const int MAX = 200100;
const int P = 998244353;
int mul(int a,int b){
  return a*b % P;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
int n;
vector<int> d[MAX];
int bez[MAX],z[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n-1){
    int pom;
    cin >> pom;
    d[pom-1].PB(i+1);
  }
  for(int v = n-1; v >= 0; v--){
    if(SZ(d[v]) == 0){
      bez[v] = 1;
      z[v] = 1;
    }else{
      int bez1 = 1;
      int jed1 = 0;
      int dwa1 = 0;
      for(int el:d[v]){
        int bez2 = mul (bez1, bez[el]);
        int jed2 = mul (bez1, z[el]);
        add(jed2, mul(jed1, bez[el]));
        int dwa2 = mul (jed1, z[el]);
        add(dwa2, mul(dwa1, z[el]));
        add(dwa2, mul(dwa1, bez[el]));
        bez1 = bez2;
        jed1 = jed2;
        dwa1 = dwa2;
      }
      bez[v] = bez1;
      add(bez[v], dwa1);
      z[v] = jed1;
      add(z[v], dwa1);
    }
  }
  cout << bez[0] << "\n";
}