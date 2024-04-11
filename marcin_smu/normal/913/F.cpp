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

const int P = 998244353;
const int MAX = 2111;
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1)
      r = r * a % P;
    w/=2;
    a = a * a % P;
  }
  return r;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a += P; 
}
int mnu(int a, int b){
  return a * b % P;
}
int n,a,b,ob;
int dp[MAX][MAX],ss[MAX],res[MAX];
int pa[MAX],pma[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> a >> b;
  ob = pot(b,P - 2);
  pa[0] = pma[0] = 1;
  R(i,n){
    pa[i+1] = mnu(pa[i], mnu(a,ob));
    pma[i+1] = mnu(pma[i], mnu(b - a, ob));
  }
  dp[0][0] = 1;
  R(i,n){
    R(j,i+1){
      add(dp[i+1][j], mnu(pa[j], dp[i][j]));
      add(dp[i+1][j+1], mnu(pma[i-j], dp[i][j]));
    }
  }
  for(int i = 1; i <= n; i++){
    ss[i] = 1;
    res[i] = 0;
    for(int j = 1; j < i; j++){
      int pr = mnu(dp[i][j], ss[j]);
      sub(ss[i], pr);
      int war = (2 * i - j - 1) * j / 2;
      add(war,res[j]);
      add(war,res[i-j]);
      debug(war,pr*4%P);
      add(res[i], mnu(war, pr)); 
    }
    debug(i,ss[i]*4%P,res[i]);
    if(i > 1){
      add(res[i], mnu(i * (i-1) / 2, ss[i]));
      debug(res[i]);
      res[i] = mnu(res[i], pot(P + 1 - ss[i],P-2));
    }
  }
  cout << res[n] << "\n";
}