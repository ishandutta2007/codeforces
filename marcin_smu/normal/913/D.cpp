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

const int MAX = 2e5 + 100;
pair<PII,int> e[MAX];
int n,t;
bool spr(int k, bool pok){
  int il = 0;
  int czas = 0;
  R(i,n){
    if(e[i].FI.SE >= k){
      if(pok)cout << e[i].SE + 1 << " ";
      czas += e[i].FI.FI;
      il++;
      if(czas > t)return 0;
      if(il == k)return 1;
    }
  }
  return 0;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> t;
  R(i,n){
    cin >> e[i].FI.SE >> e[i].FI.FI;
    e[i].SE = i;
  }
  sort(e,e+n);
  int po = 0, ko = n+1;
  while(po + 1 != ko){
    int m = (po + ko) / 2;
    if(spr(m,0)){
      po = m;
    }else{
      ko = m;
    }
  }
  cout << po << "\n" << po << "\n";
  if(po)spr(po,1);
  cout << "\n";
}