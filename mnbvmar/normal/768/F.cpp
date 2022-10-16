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



using T = LL;
//using LT = __int128_t;

const T SmallMod = 1e9 + 7;
const T Mod = SmallMod * SmallMod;


T mulMod(T a, T b) {
  T vals[3], at[2], bt[2];
  at[0] = a % SmallMod;
  at[1] = a / SmallMod;
  bt[0] = b % SmallMod;
  bt[1] = b / SmallMod;

  vals[0] = (at[0] * bt[0]) % Mod;
  vals[1] = (at[0] * bt[1] + at[1] * bt[0]) % SmallMod;

  LL res = (vals[0] + vals[1] * SmallMod) % Mod;
  //debug(a, b, res);
  return res;
}

T powMod(T a, T n) {
  T res = 1;
  while (n) {
    if (n & 1) { res = mulMod(res, a) % Mod; }
    n >>= 1;
    a = mulMod(a, a) % Mod;
  }
  return res;
}

T invMod(T a) {
  return powMod(a, (SmallMod - 1) * SmallMod - 1);
}


int F, W, H;

const int MaxN = 1e5 + 6;

T facts[MaxN];
T invFacts[MaxN];


void preproc() {
  facts[0] = 1;
  invFacts[0] = 1;

  for (int i = 1; i < MaxN; i++) {
    facts[i] = mulMod(facts[i - 1], i);
    invFacts[i] = mulMod(invFacts[i - 1], invMod(i));
  }
}

T newton(int n, int k) {
  if (k < 0 || k > n) { return 0; }
  T res = facts[n];
  res = mulMod(res, invFacts[k]);
  res = mulMod(res, invFacts[n - k]);
  return res;
}

T combs(int n, int k) {
  return newton(n + k - 1, k - 1);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> F >> W >> H;
  T cntGood = 0, cntTotal = 0;

  preproc();

  if (W == 0) {
    cout << "1\n";
    return 0;
  } else if (F == 0) {
    cout << (W > H ? "1\n" : "0\n");
    return 0;
  }

  for (int s = 1; s <= W; s++) {
    T coefTotal = combs(W - s, s); //powMod(s, W - s);
    T coef2 = 0;

    for (int k = s - 1; k <= s + 1; k++) {
      if (k > F) { break; }
      T smallCoef = k == s ? 2 : 1;
      coef2 += mulMod(smallCoef, combs(F - k, k));
    }

    cntTotal = (cntTotal + mulMod(coefTotal, coef2 % Mod)) % Mod;

    if (s * (H + 1) > W) { continue; }
    T coef = combs(W - s * (H + 1), s); //powMod(s, W - s * (H + 1));

    cntGood = (cntGood + mulMod(coef, coef2 % Mod)) % Mod;
  }

  assert(cntTotal != 0);

  T denom = invMod(cntTotal);
  debug(cntGood, cntTotal, denom);

  if (denom % SmallMod == 0) {
    assert(cntGood % SmallMod == 0);
    denom /= SmallMod;
    cntGood /= SmallMod;
  } else {
    denom %= SmallMod;
    cntGood %= SmallMod;
  }

  cout << (cntGood * denom) % SmallMod << "\n";
}