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
vector<PII> t;
int kw(int a){
  return a * a;
}
bool spr(PII po, PII m, PII ko){
  debug("spr",po,m,ko);
  int a = ko.FI - po.FI;
  int b = (ko.SE - po.SE) - kw(ko.FI) + kw(po.FI);
  int c = a * po.SE - a * kw(po.FI) - b * po.FI;
  assert(c == a * ko.SE - a * kw(ko.FI) - b * ko.FI);
  debug(a,b,c,a * m.SE - a * kw(m.FI) - b * m.FI);
  return c >= a * m.SE - a * kw(m.FI) - b * m.FI;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  t.resize(n);
  R(i,n){
    cin >> t[i].FI >> t[i].SE;
  }
  sort(ALL(t));
  vector<PII> stos;
  R(i,n)if(i == n-1 || t[i].FI != t[i+1].FI){
    while(SZ(stos) >= 2 && 
  //    spr(stos[SZ(stos)-2], t[i], stos.back())
      spr(stos[SZ(stos)-2], stos.back(), t[i])){
      debug("zajm",stos.back());
      stos.pop_back();
    }
    stos.PB(t[i]);
  }
  cout << SZ(stos)-1 << "\n";
}