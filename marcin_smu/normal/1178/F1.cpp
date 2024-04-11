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

const int MAX = 1e6 + 100;
const int MAX2 = 501;
int n,m;
int t[MAX];
const int P = 998244353;
int mul(int a,int b){
  return a * b % P;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
int dp[MAX2][MAX2];
int cz[MAX2][MAX2];
int czas = 1;
int licz(int po,int ko){
  if(po == ko)return 1;
  if(cz[po][ko] == czas)return dp[po][ko];
  cz[po][ko] = 1;
  int mi = po;
  for(int i = po; i < ko; i++){
    if(t[mi] > t[i]){
      mi = i;
    }
  }
  int lewa = 0;
  int prawa = 0;
  for(int i = po; i <= mi; i++){
    add(lewa,mul(licz(po,i), licz(i,mi)));
  }
  for(int i = mi + 1; i <= ko; i++){
    add(prawa,mul(licz(mi+1,i), licz(i,ko)));
  }
  return dp[po][ko] = mul(lewa,prawa);
}
int gd[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  R(i,n)gd[i] = -1;
  int res = 1;
  int il = 0;
  R(i,m){
    cin >> t[il];
    t[il]--;
    il++;
    if(gd[t[i]] != -1){
      //TODO
      czas++;
    }else{
      gd[t[i]] = i;
    }
  }
  res = mul(res,licz(0,il));
  cout << res << "\n";
}