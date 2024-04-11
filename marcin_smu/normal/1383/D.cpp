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

int n,m;
vector<vector<int>> t;
vector<vector<int>> res;
vector<int> a,b;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  t.resize(n,vector<int>(m));
  res.resize(n,vector<int>(m));
  R(i,n)R(j,m){
    cin >> t[i][j];
    maxi(a[i], t[i][j]);
    maxi(b[j], t[i][j]);
  }
  sort(ALL(a));reverse(ALL(a));
  sort(ALL(b));reverse(ALL(b));
  int ak = m * n;
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;
  int is = 0;
  vector<PII> smieci;
  a.PB(-1);b.PB(-1);
  while(ak){
    if(a[i] == ak){
      i++;
      if(b[j] == ak){
        j++;
        res[x][y] = ak;
        for(int xx = x - 1;xx >= 0;xx--)smieci.PB({xx,y});
        for(int yy = y - 1;yy >= 0;yy--)smieci.PB({x,yy});
        x++;y++;
      }else{
        res[x][y-1] = ak;
        for(int yy = y - 2;yy >= 0;yy--)smieci.PB({x,yy});
        x++;
      }
    }else{
      if(b[j] == ak){
        j++;
        res[x-1][y] = ak;
        for(int xx = x - 2;xx >= 0;xx--)smieci.PB({xx,y});
        y++;
      }else{
        if(SZ(smieci) == is){
          cout << "-1\n";
          return 0;
        }
        PII pom = smieci[is];is++;
        res[pom.FI][pom.SE] = ak;
      }
    }
    ak--;
  }
  R(ii,n){
    R(jj,m){
      cout << res[ii][jj] << " ";
    }
    cout << "\n";
  }
}