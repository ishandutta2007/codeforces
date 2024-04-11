#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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


vector<LL> factors(LL n) {
  vector<LL> result;

  for (LL p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      while (n % p == 0) {
        n /= p;
      }
      result.push_back(p);
    }
  }

  if (n > 1) { result.push_back(n); }
  return result;
}


LL almostPhi(LL n) {
  if (n == 1) { return 1; }
  auto x = factors(n);

  for (LL p : x) {
    debug(n, p);
    n /= p;
    n *= p - 1;
  }
  return n;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  const int Mod = 1e9 + 7;

  LL N, K;
  cin >> N >> K;

  while (K > 0) {
    if (N == 1) { break; }

    if (K % 2 == 1) {
      N = almostPhi(N);
    }
    K--;
  }

  cout << N % Mod << "\n";
}