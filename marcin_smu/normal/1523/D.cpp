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

vector<int> mb;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n,m,p;
  cin >> n >> m >> p;
  mb.resize(n);
  
  R(i,n){
    string s;
    cin >> s;
    R(j,m){
      if(s[j] == '1'){
        mb[i] += 1ll << j;
      }
    }
  }
  vector<int> naj;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  R(_,40){
    int kt = uniform_int_distribution<int>(0, n-1)(rng);
    vector<int> kan;
    R(i,m)if((mb[kt] >> i)&1){
      kan.PB(i);
    }
    debug(kt,kan);
    vector<int> dp(1 << SZ(kan));
    R(i,n){
      int ak = 0;
      R(j,SZ(kan)){
        if((mb[i] >> kan[j]) & 1){
          ak += 1 << j; 
        }
      }
      dp[ak]++;
    }
    debug(dp);
    R(i,SZ(kan))R(j,1 << SZ(kan)){
      if((j >> i) & 1){
        dp[j - (1 << i)] += dp[j];
      }
    }
    debug(dp);
    int aknaj = 0;
    int ilenaj = 0;
    R(j,1 << SZ(kan)){
      if(dp[j] >= (n + 1) / 2){
        if(ilenaj < __builtin_popcountll(j)){
          aknaj = j;
          ilenaj = __builtin_popcountll(j);
        }
      }
    }
    if(__builtin_popcountll(aknaj) > SZ(naj)){
      naj.clear();
      R(i,SZ(kan))if((aknaj >> i) & 1){
        naj.PB(kan[i]);
      }
    }
  }
  string res(m,'0');
  for(int el:naj)res[el] = '1';
  cout << res << "\n";
}