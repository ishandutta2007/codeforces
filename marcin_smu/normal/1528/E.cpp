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

const int P = 998244353;
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a += P;
}
int mul(int a,int b){
  return a * b % P;
}
int po3(int a){
  return mul(mul(a, mul(a-1, P+a-2)), (P + 1) / 6); 
}
int po2(int a){
  return mul(mul(a, a-1), (P + 1) / 2);
}
int32_t main() {
  assert((P + 1) % 6 == 0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<int> dp1(n+1);
  vector<int> dp2(n+1);
  dp1[0] = 1;
  int sum = 0;
  int res = 0;
  for(int i = 1; i <= n; i++){
    dp1[i] = dp1[i-1];
    add(dp1[i], dp2[i-1]);
    dp2[i] = mul(dp1[i], dp1[i]);
    add(dp2[i], dp1[i]);
    dp2[i] = mul(dp2[i], (P + 1) / 2);
    add(dp2[i], mul(dp1[i], sum));
    if(i == n){
      add(res, po3(dp1[i]));
      add(res, mul(dp1[i], dp1[i]-1));
      add(res, dp1[i]);
      
      add(res, mul(po2(dp1[i]),sum));
      add(res, mul(dp1[i], sum));
      
      add(res, mul(dp1[i], po2(sum)));
      add(res, mul(dp1[i], sum));
    }
    add(sum, dp1[i]);
  }
  debug(res);
  add(res,res);
  vector<int> spdp2(n + 2);
  spdp2[0] = 0;
  R(i,n+1){
    spdp2[i+1] = spdp2[i];
    add(spdp2[i+1], dp2[i]);
  }
  for(int i = 1; i < n; i++){
    add(res, mul(dp2[i], spdp2[n-i]));
  }
//   for(int i = 1; i < n; i++){
//     add(res, mul(dp1[i], dp1[n-i]));
//     add(res, mul(dp2[i], dp1[n-i]));
//     add(res, mul(dp1[i], dp2[n-i]));
//   }
  add(res, dp1[n]);
  add(res, dp1[n]);
  add(res, dp2[n]);
  add(res, dp2[n]);
  sub(res, 1);
  cout << ((res % P + P) % P) << "\n";
}