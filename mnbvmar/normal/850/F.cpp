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


const int MaxN = 3000;
const int Mod = 1e9 + 7;

int powMod(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2) { res = ((LL)res * a) % Mod; }
    n >>= 1;
    a = ((LL)a * a) % Mod;
  }
  return res;
}

int invMod(int a) { return powMod(a, Mod - 2); }

const int MaxRange = 1e5 + 500;

int S, N;
int balls[MaxN];
int coefsD[MaxRange], coefsE[MaxRange];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> S;
  N = 0;

  int M = 0;

  for (int i = 0; i < S; i++) {
    cin >> balls[i];
    N += balls[i];
    maxi(M, balls[i]);
  }

  /*coefsD[0] = 0;
  coefsD[1] = 1;
  for (int a = 1; a < N; a++) {
    coefsD[a + 1] = 2 * coefsD[a] - coefsD[a - 1];
    coefsE[a + 1] = 2 * coefsE[a] - coefsE[a - 1] - 2 -
       (LL)2 * (a - 1) * invMod(N - a);

    coefsD[a + 1] = (Mod + coefsD[a + 1] % Mod) % Mod;
    coefsE[a + 1] = (Mod + coefsE[a + 1] % Mod) % Mod;
  }

  debug(coefsD[N], coefsE[N]);
  debug(Mod - coefsE[N]);

  LL t1 = (Mod - coefsE[N]) * invMod(coefsD[N]) % Mod;*/

  coefsE[0] = 0;
  coefsE[1] = 2 * (N - 1) * (N - 1);
  coefsE[1] %= Mod;
  coefsE[1] = (coefsE[1] * invMod(N)) % Mod;

  for (int a = 1; a < M + 3; a++) {
    coefsE[a + 1] = 2 * coefsE[a] - coefsE[a - 1] - 2 -
       (LL)2 * (a - 1) * invMod(N - a);
    coefsE[a + 1] = (Mod + coefsE[a + 1] % Mod) % Mod;
  }


  LL result = 0;
  for (int i = 0; i < S; i++) {
    result += coefsE[balls[i]];
  }

  result %= Mod;

  cout << (result * invMod(2)) % Mod << "\n";
}