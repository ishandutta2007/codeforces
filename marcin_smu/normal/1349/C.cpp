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

int n,m,q;
vector<string> z;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<vector<int>> odl;
vector<vector<int>> kol;
vector<vector<int>> vis;
void licz(int a,int b,int c){
  if(odl[a][b] > c){
    cout << z[a][b];
  }else{
    cout << ((kol[a][b] ^ c)&1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m >> q;
  z.resize(n);
  R(i,n){
    cin >> z[i];
  }
  if(n == 1 && m == 1){
    R(i,q)cout << z[0][0] << "\n";
    return 0;
  }
  odl.resize(n,vector<int>(m,2e18));
  kol.resize(n,vector<int>(m));
  vis.resize(n,vector<int>(m));
  vector<PII> k1,k2;
  int t = 0;
  auto add = [&](int a,int b,int ko){
    if(a >= 0 && a < n && b >= 0 && b < m){
      if(vis[a][b])return;
      vis[a][b] = 1;
      odl[a][b] = t;
      kol[a][b] = ko;
      k1.PB({a,b});
    }
  };
  R(i,n)R(j,m){
    bool ok = 0;
    R(k,4){
      int ni = i + dx[k];
      int nj = j + dy[k];
      if(ni >= 0 && ni < n && nj >= 0 && nj < m && z[i][j] == z[ni][nj]){
        ok = 1;
      }
    }
    if(ok)add(i,j,z[i][j]-'0');
  }
  while(SZ(k1)){
    swap(k1,k2);
    k1.clear();
    t++;
    for(PII el:k2){
      R(k,4){
        add(el.FI + dx[k], el.SE + dy[k], kol[el.FI][el.SE]);
      }
    }
  }
  debug(kol,odl);
  R(i,q){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    licz(a,b,c);
    cout << "\n";
  }
#ifdef LOCAL
  R(k,10){
    R(i,n){
      R(j,m)licz(i,j,k);
      cout << "\n";
    }
    cout << "\n";
  }
#endif
}