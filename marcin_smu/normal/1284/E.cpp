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


bool cmp(PII a,PII b){
  return a.FI * b.SE - a.SE * b.FI < 0;
}

int po3(int x){
  return x * (x-1) * (x-2) / 6;
}
int po4(int x){
  return x * (x-1) * (x-2) * (x-3) / 24;  
}
int n;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  vector<PII> p(n);
  R(i,n){
    cin >> p[i].FI >> p[i].SE;
  }
  int res = 0;
  R(i,n){
    vector<PII> x;
    vector<PII> y;
    int all = 0;
    R(j,n)if(i != j){
      PII pom = {p[j].FI - p[i].FI, p[j].SE - p[i].SE};
      if(pom.FI < 0 || (pom.FI == 0 && pom.SE < 0)){
        pom.FI *= -1;
        pom.SE *= -1;
        y.PB(pom);
      }else{
        all++;
        x.PB(pom);
      }
    }
    sort(ALL(x), cmp);
    sort(ALL(y), cmp);
    int j = 0;
#define i ii
    R(i,SZ(x) + 1){
      while(j < SZ(y) && (i == SZ(x) || cmp(y[j], x[i]))){
        all++;
        res += po3(n - 1 - all);
        j++;
      }
      if(i == SZ(x))break;
      all--;
      res += po3(all);
    }
  }
  cout << n * po4(n - 1) - res << "\n";
}