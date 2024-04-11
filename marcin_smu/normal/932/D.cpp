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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const int MAX = 400100;
vector<vector<PII>> jp;
int w[MAX];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  int last = 0;
  jp.PB({});
  while(t--){
    int typ,p,q;
    cin >> typ >> p >> q;
    if(typ == 1){
      int r = p ^ last;
      int akw = q ^ last;
      r--;
      w[SZ(jp)] = akw;
      
      int krok = SZ(jp[r])-1;
      while(krok >= 0){
        if(SZ(jp[r]) > krok && w[jp[r][krok].FI] < akw){
          r = jp[r][krok].FI;
        }
        krok--;
      }
      if(w[r] < akw){
        if(SZ(jp[r]) == 0)
          r = -1;
        else
          r = jp[r][0].FI;
      }
      if(r == -1){
        jp.PB({});
      }else{
        assert(w[r] >= akw);
        vector<PII> pom = {{r,akw}};
        while(SZ(jp[pom.back().FI]) >= SZ(pom)){
          PII xx = jp[pom.back().FI][SZ(pom)-1];
          xx.SE += pom.back().SE;
          pom.PB(xx);
        }
        jp.PB(pom);
      }
    }else{
      int r = p ^ last;
      int x = q ^ last;
      r--;
      debug(r,x);
      last = 0;
      int krok = SZ(jp[r])-1;
      while(krok >= 0){
        if(SZ(jp[r]) > krok && jp[r][krok].SE <= x){
          x -= jp[r][krok].SE;
          r = jp[r][krok].FI;
          last += 1 << krok;
        }
        krok--;
      }
      if(w[r] <= x){
        last++;
      }
      cout << last << "\n";
    }
  }
}