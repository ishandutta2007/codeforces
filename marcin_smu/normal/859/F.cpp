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

const int MAX = 4e5 + 10;
int n,c;
int a[MAX],b[MAX],res[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> c;
  R(i,n){
    cin >> a[i];
    mini(a[i],c);
    res[i] = a[i];
    if(i != n-1)
    cin >> b[i];
  }
  vector<PII> st;
  int ist = 0;
  st.PB({0,0});
  int zaw = 0;
  int kos = 0;
  R(i,n-1){
    zaw += a[i];
    zaw += b[i];
    kos += res[i];
    while(SZ(st) > ist && st.back().FI - st.back().SE >= zaw - kos){
      st.pop_back();
    }
    st.PB({zaw,kos});
    while(1){
      int za = zaw - st[ist].FI + a[i+1];
      int ko = kos - st[ist].SE + res[i+1];
      if(ko < min(za, c)){
        int pom = min(za, c) - ko;
        res[i+1] += pom;
      }
      if(za > c){
        ist++;
      }else break;
    }
  }
  
  int out = 0;
  R(i,n){
    out += res[i];
    cerr << res[i] << "\n";
  }
  cout << out << "\n";
}