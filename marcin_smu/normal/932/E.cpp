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

const int P = 1e9 + 7;
const int MAX = 5001;
int n,k;
int dp[MAX][MAX];
void add(int &a, int b){
  a += b;
  if(a >= P)
    a-=P;
}
int mul(int a,int b){
  return a * b % P;
}
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w&1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  dp[0][0] = 1;
  R(i,k){
    R(j,i+1){
      add(dp[i+1][j], mul(dp[i][j], j));
      if(n > j)
        add(dp[i+1][j+1], mul(dp[i][j], n - j));
    }
  }
  int res = 0;
  R(j,k+1){
    if(n >= j)
      add(res, mul(dp[k][j], pot(2,n - j)));
  }
  cout << res << "\n";
}