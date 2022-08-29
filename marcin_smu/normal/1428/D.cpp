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

int n;
vector<int> t;
void nope(){
  cout << "-1\n";
  exit(0);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  t.resize(n);
  R(i,n){
    cin >> t[i];
  }
  vector<PII> res;
  vector<PII> gd1;
  vector<int> gd2;
  for(int i = n - 1; i >= 0; i--){
    int h = n - i - 1;
    if(t[i] == 1){
      gd1.PB({i,h});
      res.PB({i,h});
    }else if(t[i] == 2){
      if(!SZ(gd1))nope();
      int pom = gd1.back().SE;gd1.pop_back();
      res.PB({i,pom});
      gd2.PB(i);
    }else if(t[i] == 3){
      if(SZ(gd2)){
        int pom = gd2.back(); gd2.pop_back();
        res.PB({i,h});
        res.PB({pom,h});
        gd2.PB(i);
      }else if(SZ(gd1)){
        PII pom = gd1.back(); gd1.pop_back();
        res.PB({i,h});
        res.PB({pom.FI, h});
        gd2.PB(i);
      }else nope();
    }
  }
  cout << SZ(res) << "\n";
  for(PII el:res){
    cout << n - el.SE  << " " << el.FI + 1 << "\n";
  }
}