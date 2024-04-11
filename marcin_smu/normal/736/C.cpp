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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#define MAX 101
int n, k;
vector<int> d[MAX];
const int P = 1e9 + 7;
struct info{
  int t[22][22];
  info(){
    R(i,22)R(j,22)t[i][j] = 0;
  }
}dp[MAX];
void lacz(info& a,info &b){
  info res;
  R(i,k+1)R(j,k+1)R(ii,k+1)R(jj,k+1){
    int iii = max(jj >= i ? 0 : i, j >= ii ? 0 : ii + 1);
    int jjj = max(j, jj - 1);
    res.t[iii][jjj] = (res.t[iii][jjj] + a.t[i][j] * b.t[ii][jj]) % P;
  }
  swap(res,a);
}

void dfs(int nr,int oj){
  dp[nr].t[1][0] = 1;
  dp[nr].t[0][k] = 1;
  for(int el:d[nr]){
    if(el == oj)continue;
    dfs(el, nr);
    lacz(dp[nr],dp[el]);
  }
}



int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  R(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  dfs(0,-1);
  int res = 0;
  R(i,k+1){
    res += dp[0].t[0][i];
  }
  cout << res % P << "\n";
}