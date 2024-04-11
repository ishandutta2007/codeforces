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

int dp[11][11],res[11][11],res2[11][11];

PII prze(int pier,int ile, int oile){
  debug(pier,ile,oile);
  while(oile){
    ile += pier - 1;
    pier ++;
    if(pier == 11)pier = 0;
    oile --;
  }
  ile%=11;
  return {pier,ile};
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  string s;
  cin >> s;
  for(char &el:s){
    el -= '0';
  }
  R(i,11)R(j,11){
    dp[i][j] = 0;
    R(k,j){
      dp[i][j] += k + i;
    }
    dp[i][j] %= 11;
  }
  int wyn = 0;
  R(i,SZ(s)){
    R(j,11)R(k,11)res2[j][k] = 0;
    R(j,11)R(k,11)if(j > s[i]){
      wyn += res[j][k];
      PII x = prze((j + k) % 11, dp[j][k], s[i]);
      debug(x);
      res2[x.FI][x.SE] += res[j][k];
    }
    R(j,11)R(k,11)res[j][k] = res2[j][k];
    if(s[i] != 0){
      wyn++;
      PII x = prze(1,9,s[i]-1);
      res[x.FI][x.SE] ++;
    }
  }
  cout << wyn << "\n";
}