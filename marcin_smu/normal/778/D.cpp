#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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

const int MAX = 51;
string t[MAX];
int n,m;
vector<PII> licz(int x){
  int bil = 0;
  R(i,n){
    cin >> t[i];
    R(j,m){
      if(t[i][j] == 'U')bil++;
      if(t[i][j] == 'L')bil--;      
    }
  }
  vector<PII> res;
  bool co = 0;
  while(bil != x){
    if(co){
      R(i,n-1)R(j,m-1){
        if(t[i][j] == 'L' && t[i][j+1] == 'R' &&
          t[i+1][j] == 'L' && t[i+1][j+1] == 'R'){
          t[i][j] = t[i][j+1] = 'U';
          t[i+1][j] = t[i+1][j+1] = 'D';
          bil += 4;
          res.PB({i,j});
        }
      }
    }else{
      R(i,n-1)R(j,m-1){
        if(t[i][j] == 'U' && t[i][j+1] == 'U' &&
          t[i+1][j] == 'D' && t[i+1][j+1] == 'D'){
          t[i][j] = 'L'; t[i][j+1] = 'R';
          t[i+1][j] = 'L'; t[i+1][j+1] = 'R';
          bil -= 4;
          res.PB({i,j});
        }
      }
    }
    co = !co;
  }
  return res;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  int pom = n * m / 2;
  if(n&1)pom*=-1;
  debug(pom);
  vector<PII> a = licz(pom);
  debug("xxx");
  vector<PII> b = licz(pom);
  cout << SZ(a) + SZ(b) << "\n";
  for(PII el:a){
    cout << el.FI+1 << " " << el.SE + 1 << "\n";
  }
  reverse(ALL(b));
  for(PII el:b){
    cout << el.FI+1 << " " << el.SE + 1 << "\n";
  }
}