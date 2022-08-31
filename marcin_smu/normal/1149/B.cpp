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

const int MAX = 260;
const int MAXn = 100100;
const int ALFA = 'z' - 'a' + 1;
int n,q;
int dp[MAX][MAX][MAX];
int gd[MAXn][ALFA];
vector<int> s[3];
int dl[3];
void licz(int a,int b,int c){
  int& res = dp[a][b][c];
  res = n + 1;
  if(a != 0){
    mini(res, gd[dp[a-1][b][c]][s[0][a-1]] + 1);
  }
  if(b != 0){
    mini(res, gd[dp[a][b-1][c]][s[1][b-1]] + 1);
  }
  if(c != 0){
    mini(res, gd[dp[a][b][c-1]][s[2][c-1]] + 1);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  {
    string z;
    cin >> n >> q >> z;
    R(i,ALFA)
      gd[n + 1][i] = gd[n][i] = n + 1;
    for(int i = n - 1; i >= 0; i--){
      R(j,ALFA){
        gd[i][j] = gd[i+1][j];
      }
      gd[i][(int)z[i] - 'a'] = i; 
    }
    R(i,n){
      R(j,ALFA)
        cerr << gd[i][j] << " ";
      cerr << "\n";
    }
  }
  dp[0][0][0] = 0;
  R(_,q){
    char z;
    int kt;
    cin >> z >> kt;
    kt--;
    if(z == '+'){
      dl[kt]++;
      char x;
      cin >> x;
      s[kt].PB(x - 'a');
      if(kt == 0){
        R(i,dl[1] + 1)R(j,dl[2] + 1){
          licz(dl[0], i, j);
        }
      }else if(kt == 1){
        R(i,dl[0] + 1)R(j,dl[2] + 1){
          licz(i, dl[1], j);
        }
      }else{
        R(i,dl[0] + 1)R(j,dl[1] + 1){
          licz(i, j, dl[2]);
        }
      }
    }else{
      s[kt].pop_back();
      dl[kt]--;
    }
    debug(dp[dl[0]][dl[1]][dl[2]]);
    if(dp[dl[0]][dl[1]][dl[2]] <= n){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
}