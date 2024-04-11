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

const int MAX = 1e6 + 1;
int f[MAX],g[MAX];
vector<int> gd[11];

int licz(int a,int k){
  int po = -1,ko = SZ(gd[k]);
  while(po+1 != ko){
    int m = (po + ko) / 2;
    if(gd[k][m] <= a){
      po = m;
    }else{
      ko = m;
    }
  }
  return po;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  f[0] = 1; 
  R(i,MAX){
    if(i < 10){
      f[i] = max(1ll,i);
    }else{
      f[i] = f[i / 10] * (i % 10 == 0? 1 : i % 10);
      assert(f[i] < i);
    }
  }
  R(i,MAX){
    if(i < 10){
      g[i] = i;
    }else{
      g[i] = g[f[i]];
    }
    gd[g[i]].PB(i);
  }
  int q;
  cin >> q;
  R(i,q){
    int l,r,k;
    cin >> l >> r >> k;
    cout << licz(r,k) - licz(l-1,k) << "\n";
  }
}