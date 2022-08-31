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

const int P = 1e9 + 7;
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
const int C = 30;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  vector<int> il(C);
  R(i,n){
    int pom;
    cin >> pom;
    int x = 0;
    while(pom % 2 == 0){
      x ++;
      pom /=2;
    }
    il[x]++;
  }
  vector<int> p2(n + 1);
  p2[0] = 1;
  R(i,n){
    p2[i + 1] = p2[i];
    add(p2[i+1], p2[i]);
  }
  debug(p2);
  int res = p2[n];
  sub(res, 1);
  debug(il);
  int sum = 0;
  for(int i = C-1; i > 0; i--){
    sum += il[i];
    if(il[i])
      sub(res, p2[sum-1]);
  }
//   R(i,C)if(i){
//     int na = mul(a, p2[il[i]]);
//     add(na, mul(b, il[i]));
//     
//     int pom = p2[il[i]];
//     sub(pom, il[i]);
//     int nb = mul(b, pom);
//     swap(na,a);
//     swap(nb,b);
//     debug(a,b);
//   }
//   sub(res, a);
  cout << res << "\n";
}