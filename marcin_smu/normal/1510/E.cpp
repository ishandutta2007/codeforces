#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
// #define int LL
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

struct opis{
  int xm,ym,m;
  bool cz;
  opis* bez;
  bool operator ==(const opis &pom)const{
    return xm == pom.xm && ym == pom.ym && m == pom.m;
  }
  bool operator <(const opis &pom)const{
    if(xm != pom.xm)return xm < pom.xm;
    if(ym != pom.ym)return ym < pom.ym;
    return m < pom.m;
  }
};

string get(opis* x){
  if(x->bez == nullptr)return "";
  return get(x->bez) + (x->cz ? "(" : ")");
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  LD x,y;
  cin >> n >> x >> y;
  n/=2;
  vector<vector<vector<opis>>> t(n + 1, vector<vector<opis>>(n + 1));
  t[0][0].PB({0, 0, 0, false, nullptr});
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= i; j++){
      sort(ALL(t[i][j]));
      t[i][j].resize(unique(ALL(t[i][j])) - t[i][j].begin());
      t[i][j].shrink_to_fit();
      debug(i,j);
      for(auto &el:t[i][j]){
        debug(get(&el), el.xm, el.ym, el.m);
      }
      if(i == n)continue;
      for(auto &el : t[i][j]){
        t[i+1][j+1].PB({
          el.xm + 6 * i * j + 3 * j + 3 * i + 2,
          el.ym + 3 * j * j + 3 * j + 1,
          el.m + 2 * j + 1,
          true,
          &el
        });
        if(j >= 1){
          t[i+1][j-1].PB({
            el.xm + 6 * i * j + 3 * j - 6 * i - 3 + 3 * i + 1,
            el.ym + 3 * j * j - 6 * j + 3 + 3 * j - 2,
            el.m + 2 * j - 1,
            false,
            &el
          });
        }
      }
    }
  }
  LD err = 1e9;
  opis *naj1 = nullptr;
  opis *naj2 = nullptr;
  R(j,n + 1)for(opis &el1:t[n][j])for(opis &el2:t[n][j]){
    LD ak = abs((el1.xm + 6 * el2.m * n - el2.xm) * 1. / (el1.m + el2.m) / 3 - x);
    ak += abs((el1.ym + el2.ym) * 1. / (el1.m + el2.m) / 3 - y);
    if(ak < err){
      err = ak;
      naj1 = &el1;
      naj2 = &el2;
    }
  }
  debug(err);
  string res2 = get(naj2);
  reverse(ALL(res2));
  for(char &el:res2){
    el ^= '(' ^ ')';
  }
  cout << get(naj1) << res2 << "\n";
}