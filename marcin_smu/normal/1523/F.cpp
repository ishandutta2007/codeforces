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
vector<int> xw,yw;
vector<int> xq,yq,t;
const int MAXN = 14;
const int MAXM = 100;
int odlww[MAXN][MAXN];
int odlqw[MAXM][MAXN];
int odlqq[MAXM][MAXM];
int odlzww[1 << MAXN][MAXN];
int odlzwq[1 << MAXN][MAXM];
int odl[1 << MAXN][MAXM + 1];
int ilemam[1 << MAXN][MAXM];
bool czmoge[MAXM][MAXM];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  xw.resize(n);
  yw.resize(n);
  R(i,n){
    cin >> xw[i] >> yw[i];
  }
  xq.resize(m);
  yq.resize(m);
  t.resize(m);
  vector<int> p(m);
  R(i,m){
    p[i] = i;
    cin >> xq[i] >> yq[i] >> t[i];
  }
  
  sort(ALL(p), [&](int a,int b){
    return t[a] < t[b];
  });
  
  vector<int> xxq(m),yyq(m),tt(m);
  R(i,m){
    xxq[i] = xq[p[i]];
    yyq[i] = yq[p[i]];
    tt[i] = t[p[i]];
  }
  swap(xxq,xq);
  swap(yyq,yq);
  swap(tt,t);
  debug(t);
  
  R(i,n)R(j,n){
    odlww[i][j] = abs(xw[i] - xw[j]) + abs(yw[i] - yw[j]);
  }
  R(i,m)R(j,n){
    odlqw[i][j] = abs(xq[i] - xw[j]) + abs(yq[i] - yw[j]);
  }
  R(i,m)R(j,m){
    odlqq[i][j] = abs(xq[i] - xq[j]) + abs(yq[i] - yq[j]);
  }
  R(i,m)R(j,m){
    czmoge[i][j] = t[j] - t[i] >= odlqq[i][j];
  }
  R(i,n)odlzww[0][i] = 1e12;
  R(i,m)odlzwq[0][i] = 1e12;
  
  R(mb, 1 << n){
    R(i,n)if((mb >> i)&1){
      R(j,n)
        odlzww[mb][j] = min(odlzww[mb - (1 << i)][j], odlww[i][j]);
      R(j,m)
        odlzwq[mb][j] = min(odlzwq[mb - (1 << i)][j], odlqw[j][i]);
      break;
    }
  }
  
  priority_queue<pair<int,PII>> secik;
  R(mb, 1 << n)R(j,m+1)odl[mb][j] = 1e10;
  R(mb, 1 << n)R(j,m)ilemam[mb][j] = -1;
  auto dodaj = [&](int mb,int ile,int mom){
    if(odl[mb][ile] > mom){
      odl[mb][ile] = mom;
      secik.push({-mom, {mb,ile}});
    }
  };
  R(i,n){
    dodaj(1 << i, 0, 0);
  }
  R(i,m){
    ilemam[0][i] = 0;
  }
  int res = 0;
  int gdp = 0;
  while(gdp != m){
    if(!secik.empty() && t[gdp] > -secik.top().FI){
      auto pom = secik.top();
      int mb = pom.SE.FI;
      int ile = pom.SE.SE;
      int mom = -pom.FI;
      secik.pop();
      if(odl[mb][ile] != mom)continue;
      debug(mb,ile,mom);
      R(i,n){
        int od = odlzww[mb][i];
        if(od != 0){
          dodaj(mb | (1 << i), ile, mom + od);
        }
      }
      for(int i = gdp; i < m; i++){
        int od = odlzwq[mb][i];
        if(t[i] >= od + mom){
          maxi(ilemam[mb][i], ile);
        }
      }
    }else{
      int i = gdp; 
      gdp++;
      R(mb, 1 << n){  
        int ile = ilemam[mb][i] + 1;
        if(ile == 0)continue;
        debug(i, mb, ile, t[i]);
        maxi(res, ile);
        for(int j = gdp; j < m; j++){
          if(czmoge[i][j]){
            maxi(ilemam[mb][j], ile);
          }
        }
        dodaj(mb, ile, t[i]);
        R(j,n){
          dodaj(mb | (1 << j), ile, t[i] + odlqw[i][j]);
        }
      }
    }
  }
  cout << res << "\n";
}