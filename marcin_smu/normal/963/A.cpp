#include <bits/stdc++.h>

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
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

const int P = 1e9 + 9;
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = r * a % P;
    }
    a = a * a % P;
    w/=2;
  }
  return r;
}
int n,a,b,k;
string z;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> a >> b >> k >> z;
  int sum = 0;
  int ak = pot(a, n);
  int krok = pot(a, P-2) * b % P;
  R(i,k){
    debug(ak);
    sum += (z[i] == '+' ? 1 : P-1) * ak % P;
    ak = ak * krok % P;
  }
  sum %= P;
  debug(sum);
  krok = pot(krok, k);
  int m = (n + 1) / k;
  if(krok == 1){
    cout << sum * m % P << "\n";
    return 0;
  }
//   debug(m,krok);
//   debug(P + 1 - pot(krok,m));
//   debug(pot((P + 1 - krok)%P , P-2));
  sum *= (P + 1 - pot(krok,m)) * pot((P + 1 - krok)%P , P-2) %P;
  cout << sum % P << "\n";
}