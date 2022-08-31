#include <bits/stdc++.h>

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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const int MAX = 100;
int n;
LD t[MAX][MAX];
vector<pair<LD,LD>> licz(int po,int ko){
  if(po == ko-1){
    return {{1., 0.}};
  }
  auto a = licz(po, (po + ko) / 2);
  auto b = licz((po + ko) / 2 , ko);
  vector<pair<LD,LD>> res(ko-po);
  R(i, SZ(a))R(j, SZ(b)){
    res[i].FI += a[i].FI * b[j].FI * t[i + po][j + (po + ko)/2];
    res[j + SZ(a)].FI += a[i].FI * b[j].FI * (1 - t[i + po][j + (po + ko)/2]);
    maxi(res[i].SE, a[i].SE + b[j].SE);
    maxi(res[j + (SZ(a))].SE, a[i].SE + b[j].SE);
  }
  for(auto& el:res){
    el.SE += el.FI * (ko - po) / 2;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,1 << n)R(j, 1 << n){
    cin >> t[i][j];
    t[i][j] /= 100;
  }
  auto pom = licz(0,1 << n);
  LD res = 0;
  for(auto el:pom){
    maxi(res,el.SE);
  }
  cout << res << "\n";
}