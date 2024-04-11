#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define R(i,n) for(int i = 0; i < (n); i++)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
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

template<class T> ostream &operator<<(ostream& os, set<T> V) {
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

const int MAX = 52;
int n,k;
int dp[MAX][MAX];
int sp[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  R(i,n){
    int pom;
    cin >> pom;
    sp[i + 1] = sp[i] + pom;
  }
  int ak = 0;
  for(int bit = 60;bit >= 0;bit--){
    R(i,n+1)R(j,k+1)dp[i][j] = 0;
    dp[0][0] = ak | (1ll << bit);
    R(i,n)R(j,k)for(int l = i + 1; l <= n; l ++){
      maxi(dp[l][j+1], dp[i][j] & (sp[l] - sp[i]));
    }/*
    if(bit == 4){
      R(i,n+1){
        R(j,k+1){
          cerr << dp[i][j] << " ";
        }
        cerr << "\n";
      }
    }*/
    ak = dp[n][k];
    debug(ak);
  }
  cout << ak << "\n";
}