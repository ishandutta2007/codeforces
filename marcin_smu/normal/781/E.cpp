#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

int h,w,n;

const int MAX = 1e5 + 5;

vector< set<pair<int,pair<int,int>>>> dp;
int nn;

void add(int po,int ko,int war,int znika,int y){
  function<void(int,int,int)> dod = [&](int nr,int beg,int end){
    if(beg >= ko || end <= po)return;
    if(po <= beg && ko >= end){
      dp[nr].insert({-y,{war,znika}});
      return;
    }
    dod(nr*2,beg,(beg+end)/2);
    dod(nr*2+1,(beg+end)/2,end);
  };
  dod(1,0,nn);
}

int daj(int a,int h){
  a += nn;
  pair<int,pair<int,int>> pom = {1,{1,2e9}};
  while(a){
    while(!dp[a].empty() && dp[a].begin()->SE.SE < h){
      dp[a].erase(dp[a].begin());
    }
    if(!dp[a].empty()){
      mini(pom,*dp[a].begin());
    }
    a/=2;
  }
  debug(a,h,pom.SE.FI);
  return pom.SE.FI;
}

const int P = 1e9 + 7;

struct bar{
  int u,l,r,s;
  void pob(){
    cin >> u >> l >> r >> s;
    l--;
  }
  void licz(){
    int pom = 0;
    if(l != 0){
      pom += daj(l-1,u);
    }
    if(r != w){
      pom += daj(r,u);
    }
    if(l == 0 || r == w)
      pom *= 2;
    if(pom >= P)pom-=P;
    debug(pom);
    add(l,r,pom,s + u, u);
  }
};
bar b[MAX];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> h >> w >> n;
  nn = 1;
  while(nn <= w)nn*=2;
  dp.resize(nn*2);
  R(i,n){
    b[i].pob();
  }
  sort(b, b+n, [](bar x,bar y){
    return x.u < y.u;
  });
  R(i,n){
    b[i].licz();
  }
  int res = 0;
  R(i,w){
    res += daj(i,h+1);
    if(res >= P)res %= P;
  }
  cout << res << "\n";
}