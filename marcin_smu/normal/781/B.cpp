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

const int MAX = 1001;
int n;
string a[MAX],b[MAX];
string res[MAX][2];
int vis[MAX];
int d[MAX][MAX];
void dfs(int a){
  if(vis[a])return;
  vis[a] = 1;
  R(i,n)if(d[a][i])dfs(i);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  R(i,n){
    cin >> a[i] >> b[i];
    res[i][0] = a[i].substr(0,3);
    res[i][1] = a[i].substr(0,2) + b[i][0];
  }
  R(i,n){
    R(j,n){
      if(res[i][1] == res[j][0]){
        d[i][j] = 1;
      }
    }
  }
  R(i,n)R(j,i){
    if(res[i][0] == res[j][0]){
      dfs(i);
      dfs(j);
    }
  }
  R(i,n)R(j,i){
    if(res[i][vis[i]] == res[j][vis[j]]){
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  R(i,n){
    cout << res[i][vis[i]] << "\n";
  }
}