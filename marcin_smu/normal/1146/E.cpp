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

const int MAX = 100001;
int t[MAX];
int n,q;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  R(i,n){
    cin >> t[i];
  }
  vector<int> st;
  st.PB(0);
  bool swa = 0;
  R(i,q){
    char c;
    int ile;
    cin >> c >> ile;
    debug(c,ile);
    if(c == '<'){
      int pom;
      if(ile <= 0){
        pom = -ile + 1;
      }else{
        swa^=1;
        pom = ile;
      }
      debug(pom);
      while(st.back() >= pom)st.pop_back();
      if(SZ(st) == 1)st.PB(pom);
      if((SZ(st) & 1) ^ swa){
        st.PB(pom);
      }
    }else{
      int pom;
      if(ile >= 0){
        pom = ile + 1;
      }else{
        swa^=1;
        pom = -ile;
      }
      debug(pom);
      while(st.back() >= pom)st.pop_back();
      if(SZ(st) == 1)st.PB(pom);
      if(((SZ(st) & 1) ^ swa) == 0){
        st.PB(pom);
      }
    }
    debug(st,(int)swa);
  }
  R(i,n){
    int po = 0, ko = SZ(st);
    while(po + 1 != ko){
      int m = (po + ko) / 2;
      if(st[m] <= abs(t[i])){
        po = m;
      }else{
        ko = m;
      }
    }
    if(po == 0){
      if(swa){
        cout << -t[i] << " ";
      }else{
        cout << t[i] << " ";
      }
    }else{
      if(swa ^ (po & 1)){
        cout << abs(t[i]) << " ";
      }else{
        cout << -abs(t[i]) << " ";
      }
    }
  }
  cout << "\n";
}