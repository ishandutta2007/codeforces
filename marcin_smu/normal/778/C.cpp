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

int n;

const int MAX = 3e5 + 100;
const int ALFA = 'z' - 'a' + 1;
int d[MAX][30];
int res[MAX];

int licz(vector<int> pom){
  int res = SZ(pom) - 1;
  R(i,ALFA){
    vector<int> x;
    for(int el:pom){
      if(d[el][i] != 0){
        x.PB(d[el][i]);
      }
    }
    if(SZ(x) > 1){
      res += licz(x);
    }
  }
  return res;
}

void dfs(int a,int gl){
  vector<int> pom;
  R(i,ALFA){
    if(d[a][i] != 0){
      pom.PB(d[a][i]);
    }
  }
  if(SZ(pom))res[gl]++;
  if(SZ(pom) > 1)
    res[gl] += licz(pom);
  for(int el:pom)dfs(el,gl+1);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n-1){
    int a,b;
    char c;
    cin >> a >> b >> c;
    a--;b--;
    d[a][c-'a'] = b;
  }
  dfs(0,0);
  int kt = 0;
  R(i,n){
    debug(i,res[i]);
    if(res[i] > res[kt]){
      kt = i;
    }
  }
  cout << n - res[kt] << "\n" << kt + 1 << "\n";
}