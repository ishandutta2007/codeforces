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

vector<int> t;
int n;
void apply(vector<int> x){
  vector<vector<int>> tt;
  tt.PB({});
  int j = 0;
  R(i,n){
    if(i == x[j]){
      tt.PB({});
      j++;
    }
    tt.back().PB(t[i]);
  }
  debug(t,x,tt);
  reverse(ALL(tt));
  t.clear();
  R(i,SZ(tt)){
    for(int el:tt[i]){
      t.PB(el);
    }
  }
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
    t[i]--;
  }
  vector<vector<int>> res;
  while(1){
    debug(t);
    int ak = 0;
    while(ak < n && t[ak] == ak)ak++;
    if(ak == n)break;
    vector<int> ruch;
    if(ak)ruch.PB(ak);
    for(int pom = ak; ;pom++){
      if(t[pom] + 1 != t[pom+1]){
        ruch.PB(pom + 1);
        break;
      }
    }
    for(int pom = ak;;pom++){
      if(t[pom] == t[ak]-1){
        ruch.PB(pom+1);
        if(pom != n-1){
          ruch.PB(n);
        }
        break;
      }
    }
    apply(ruch);
    for(int i = SZ(ruch) - 1;i;i--){
      ruch[i] -= ruch[i-1];
    }
    debug(ruch);
    res.PB(ruch);
  }
  cout << SZ(res) << "\n";
  R(i,SZ(res)){
    cout << SZ(res[i]) << " ";
    for(int el:res[i]){
      cout << el << " ";
    }
    cout << "\n";
  }
}