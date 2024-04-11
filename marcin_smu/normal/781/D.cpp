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

int n,m;
const int MAX = 501;
struct mac{
  bitset<MAX> t[MAX];
  void mnu(mac& a,mac& b){
    R(i,n)R(j,n){
      if(a.t[i][j])
        t[i] |= b.t[j];
    }
  }
  bitset<MAX> idz(bitset<MAX>& x){
    bitset<MAX> res;
    R(i,n){
      if(x[i])res |= t[i];
    }
    return res;
  }
}t[62][2];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  bool cz0 = 0;
  R(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    t[0][c].t[a][b] = 1;
    if(c == 0 && a == 0)cz0 = 1;
  }
  if(!cz0){
    cout << "0\n";
    return 0;
  }
  R(i,61){
    t[i+1][0].mnu(t[i][0], t[i][1]);
    t[i+1][1].mnu(t[i][1], t[i][0]);
    bitset<MAX> ak;
    ak[0] = 1;
    ak = t[i+1][0].idz(ak);
    if(!ak.any()){
      int res = 1ll << i;
      ak[0] = 1;
      ak = t[i][0].idz(ak);
      bool p = 1;
      while(i){
        i--;
        bitset<MAX> pom = t[i][p].idz(ak);
        if(pom.any()){
          swap(ak,pom);
          res += 1ll << i;
          p = !p;
        }
      }
      if(res > (int)(1e9) * (int)(1e9)){
        cout << "-1\n";
        return 0;
      }
      cout << res << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  
}