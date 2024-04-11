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
int mul(int a,int b){
  return a * b % P;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
int sub(int a,int b){
  a -= b;
  if(a < 0)a += P;
  return a;
}
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}
const int MAX = 300010;
int sil[MAX],odw[MAX],odwsil[MAX];
int n,t[MAX];
int dwu(int a,int b){
  return mul(sil[a], mul(odwsil[b], odwsil[a-b]));
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  sil[0] = 1;
  R(i,MAX-1){
    sil[i+1] = mul(sil[i], i+1);
  }
  R(i,MAX){
    odwsil[i] = pot(sil[i],P-2);
    odw[i] = pot(i,P-2);
  }
  cin >> n;
  int sum = 0;
  R(i,n){
    cin >> t[i];
    sum += t[i];
  }
  R(i,n){
    if(t[i] == sum){
      cout << "0\n";
      return 0;
    }
  }
  vector<int> a(sum+1);
  vector<int> b(sum+1);
  a[1] = 1;
  int prefa = 1;
  int prefb = mul(sum,odw[2]);
  for(int i = 2;i <= sum; i++){
    a[i] = sub(mul(a[i-1], n), mul(prefa, n-1));
    b[i] = sub(mul(b[i-1], n), mul(prefb, n-1));
    prefa = mul(prefa, i);
    prefb = mul(prefb, i);
    add(prefa, a[i]);
    add(prefb, b[i]);
    add(prefb, sum);
    prefa = mul(prefa, odw[i+1]);
    prefb = mul(prefb, odw[i+1]);
  }
  int x = mul(sub(0,b[sum]), pot(a[sum],P-2));
  debug(x,x*2 % P,x*3 % P);
  int res = 0;
  vector<int> xx(sum + 1);
  xx[0] = 0;
  R(i,sum){
    xx[i + 1] = xx[i];
    add(xx[i+1], mul(sum, odw[sum-i]));
  }
  debug(xx);
  R(i,n){
    int m = pot(dwu(sum,t[i]),P-2);
    debug(m,2 * m % P);
    for(int j = 1; j <= t[i]; j++){
      int mn = dwu(sum - j - 1, t[i] - j);
      debug(mn);
      mn = mul(mn, m);
      int pom = mul(a[j],x);
      add(pom, b[j]);
      debug(pom);
      add(pom, xx[sum - j]);
      add(res, mul(mn,pom));
    }
  }
  cout << mul(mul(res,odw[n]),n-1) << "\n";
}