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

string s;
int n;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> s;
  n = SZ(s);
  int sq = 400;
  vector<int> war(n + 1);
  int res = 0;
  R(j,sq - 1){
    war[0] = 0;
    R(i,n){
      if(s[i] == '0'){
        war[i+1] = war[i] + 1;
      }else{
        war[i+1] = war[i] - j;
      }
    }
    sort(ALL(war));
    debug(war);
    int ak = 0;
    R(i,n + 1){
      if(i == 0 || war[i] != war[i-1]){
        ak = 1;
      }else{
        ak++;
      }
      res += ak - 1;
    }
  }
  vector<int> jed;
  jed.PB(-1);
  R(i,n){
    if(s[i] == '1'){
      jed.PB(i);
    }
    int ko = i + 1;
    for(int j = SZ(jed) - 1; j; j--){
      int ile = SZ(jed) - j;
      if(sq * ile > ko) break;
      int popo = jed[j-1] + 1;
      int poko = jed[j];
      int minkr = max(sq, (ko - poko - 1) / ile + 1);
      int maxkr = (ko - popo) / ile;
      if(maxkr < minkr)continue;
      res += maxkr - minkr + 1;
    }
  }
  cout << res << "\n";
}