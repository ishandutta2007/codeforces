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

#define MAX 1001
short t[11][11][MAX][MAX];
int n,m;
int p2[MAX];
inline int licz(int a,int b,int c,int d){
  int p21 = p2[c-a];
  int p22 = p2[d-b];
  return max(
    max(t[p21][p22][a][b],t[p21][p22][c-(1<<p21)][b]),
    max(t[p21][p22][a][d-(1<<p22)],t[p21][p22][c-(1<<p21)][d-(1<<p22)])
  );
}
void test(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  a--;b--;
  int po = 0,ko = min(d-b,c-a)+1;
  while(po+1 != ko){
    int m = (po+ko)/2;
    if(licz(a+m-1,b+m-1,c,d) >= m){
      po = m;
    }else
      ko = m;
  }
  cout << po << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  for(int i=2;i<MAX;i++){
    if((i & i-1) == 0){
      p2[i] = p2[i-1]+1;
    }else
      p2[i] = p2[i-1];
  }
  cin >> n >> m;
  R(i,n)R(j,m){
    cin >> t[0][0][i][j];
    if(i && j && t[0][0][i][j]){
      t[0][0][i][j] = 1 + min(
        min(t[0][0][i-1][j],t[0][0][i][j-1]),
        t[0][0][i-1][j-1]);
    }
  }
  R(ii,10){
    int a = 1 << ii;
    R(i,n-a)R(j,m){
      t[ii+1][0][i][j] = max(t[ii][0][i][j],t[ii][0][i+a][j]);
    }
  }
  R(jj,10){
    int b = 1 << jj;
    R(i,n)R(j,m-b){
      t[0][jj+1][i][j] = max(t[0][jj][i][j],t[0][jj][i][j+b]);
    }
  }
  
  
  R(ii,10)R(jj,10){
    int a = 1 << ii;
    int b = 1 << jj;
    R(i,n-a)R(j,m-b){
      t[ii+1][jj+1][i][j] = max(
        max(t[ii][jj][i][j],t[ii][jj][i+a][j]),
        max(t[ii][jj][i][j+b],t[ii][jj][i+a][j+b])
      );
    }
  }
  int t;
  cin >> t;
  while(t--)test();
}