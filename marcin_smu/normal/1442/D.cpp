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

vector<int> dp;
vector<int> ile;
vector<int> val;
vector<vector<int>> all;
int res = 0;
int n,k;

void dodaj(int x){
  if(ile[x] <= k){
    for(int i = k - ile[x]; i >= 0; i--){
      maxi(dp[i + ile[x]],dp[i] + val[x]);
    }
  }
}
void licz(int po,int ko){
  if(po + 1 == ko){
    int sum = 0;
    R(i,min(k, SZ(all[po])) + 1){
      maxi(res, dp[k - i] + sum);
      if(i < SZ(all[po]))
        sum += all[po][i];
    }
    return;
  };
  int m = (po + ko) / 2;
  vector<int> pam = dp;
  for(int i = po; i < m; i++){
    dodaj(i);
  }
  licz(m,ko);
  dp = pam;
  for(int i = m; i < ko; i++){
    dodaj(i);
  }
  licz(po,m);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> k;
  dp.resize(k + 1);
  ile.resize(n);
  val.resize(n);
  all.resize(n);
  R(i,n){
    cin >> ile[i];
    all[i].resize(ile[i]);
    R(j,ile[i]){
      cin >> all[i][j];
      val[i] += all[i][j];
    }
  }
  licz(0,n);
  cout << res << "\n";
}