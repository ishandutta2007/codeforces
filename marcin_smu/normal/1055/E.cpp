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

int n,s,m,k;
vector<int> a;
vector<vector<int>> d;
bool spr(int x){
  vector<int> sp(n + 1);
  R(i,n){
    sp[i+1] = sp[i] + (a[i] <= x);
  }
  vector<int> dp(n+1);
  R(j,m){
    R(i,n)
      maxi(dp[i+1],dp[i]);
    for(int i = n;i;i--){
      maxi(dp[i-1],dp[i] - (a[i-1] <= x));
    }
    vector<int> pom(n+1);
    R(i,n){
      for(int el:d[i]){
        maxi(pom[el],dp[i] + sp[el] - sp[i]);
      }
    }
    swap(dp,pom);
  }
  int res = 0;
  for(int el:dp){
    maxi(res,el);
  }
  debug(x,res);
  return res >= k;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> s >> m >> k;
  a.resize(n);
  R(i,n){
    cin >> a[i];
  }
  d.resize(n);
  R(i,s){
    int l,r;
    cin >> l >> r;
    l--;
    d[l].PB(r);
  }
  int po = 0, ko = 1e9 + 1;
  while(po + 1 != ko){
    int me = (po + ko) / 2;
    if(spr(me)){
      ko = me;
    }else{
      po = me;
    }
  }
  if(ko > 1e9){
    cout << "-1\n";
  }else
    cout << ko << "\n";
}