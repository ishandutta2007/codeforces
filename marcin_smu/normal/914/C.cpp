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

const int MAX = 1100;
int il[MAX],dp[MAX];
string x;
int k;
const int P = 1e9 + 7;
void add(int& a,int b){
  a += b;
  if(a >= P)
    a-=P;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> x;
  cin >> k;
  if(k == 0){
    cout << "1\n";
    return 0;
  }
  if(k == 1){
    cout << SZ(x) - 1 << "\n";
    return 0;
  }
  int ak = 0;
  R(i,SZ(x)){
    for(int j = 1000;j >= 0;j--){
      add(il[j+1],il[j]);
    }
    if(x[i] == '1'){
      add(il[ak],1);
      ak++;
    }
  }
  il[ak]++;
  R(i,20){
    cerr << il[i] << " ";
  }
  cerr << "\n";
  int res = 0;
  R(i,MAX)if(i > 1){
    dp[i] = dp[__builtin_popcount(i)] + 1;
    if(i < 20)debug(i,dp[i]);
    if(dp[i] == k-1){
      add(res,il[i]);
    }
  }
  cout << res << "\n";
}