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

const int MAX = 1001;

int n,m;
vector<string> t;
void nope(){
  cout << "-1\n";
  exit(0);
}
bool vis[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void dfs(int x,int y){
  if(vis[x][y] || t[x][y] != '#')return;
  vis[x][y] = 1;
  R(i,4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
    dfs(nx,ny);
  }
  
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  t.resize(n);
  R(i,n){
    cin >> t[i];
  }
  
  bool pusa = 0;
  bool pusb = 0;
  R(i,n){
    int stan = 0;
    R(j,m){
      if(t[i][j] == '#'){
        if(stan <= 1){
          stan = 1;
        }else{
          nope();
        }
      }else{
        if(stan == 1){
          stan = 2;
        }
      }
    }
    if(stan == 0){
      pusa = 1;
    }
  }
  
  R(j,m){
    int stan = 0;
    R(i,n){
      if(t[i][j] == '#'){
        if(stan <= 1){
          stan = 1;
        }else{
          nope();
        }
      }else{
        if(stan == 1){
          stan = 2;
        }
      }
    }
    if(stan == 0){
      pusb = 1;
    }
  }
  if(pusa ^ pusb){
    nope();
  }
  
  int res = 0;
  R(i,n)R(j,m)if(t[i][j] == '#' && vis[i][j] == 0){
    dfs(i,j);
    res++;
  }
  cout << res << "\n";
}