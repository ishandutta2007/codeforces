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

const int MAX = (1 << 19) + 10;
int n,q;
vector<int> gd[MAX];
const int C = 5;
struct info{
  vector<PII> x;
  info(){x.reserve(10);}
  void dodaj(info& a){
    for(PII el:a.x){
      for(PII& el2:x){
        if(el2.SE == el.SE){
          el2.FI += el.FI;
          goto ok;
        }
      }
      x.PB(el);
      ok:;
    }
    sort(ALL(x),greater<PII>());
    if(SZ(x) >= 6){
      R(i,5){
        x[i].FI -= x[5].FI;
      }
      x.resize(5);
    }
  }
}dp[MAX * 2];


inline int ile(int po,int ko,int co){
  int res = lower_bound(ALL(gd[co]), ko) - lower_bound(ALL(gd[co]), po);
  debug(po,ko,co,res);
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  int nn = 1;while(nn <= n)nn *= 2;
  R(i,n){
    int pom;
    cin >> pom;
    gd[pom].PB(i);
    dp[i + nn].x.PB({1,pom});
  }
  for(int i = nn-1; i; i--){
    dp[i] = dp[i*2];
    dp[i].dodaj(dp[i*2+1]);
  }
  R(i,q){
    int po,ko,k;
    cin >> po >> ko >> k;
    po--;
    info pom;
    function<void(int,int,int)> rec = [&](int nr,int be,int en){
      if(po >= en || be >= ko)return;
      if(po <= be && en <= ko){
        debug(dp[nr].x);
        pom.dodaj(dp[nr]);
        return;
      }
      rec(nr*2,be,(be+en)/2);
      rec(nr*2+1,(be+en)/2,en);
    };
    rec(1,0,nn);
    debug(pom.x);
    int res = -1;
    for(PII el:pom.x){
      if((res == -1 || el.SE < res) && ile(po,ko,el.SE) * k > ko - po){
        res = el.SE;
      }
    }
    cout << res << "\n";
  }
}