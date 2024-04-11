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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif

const int MaxSize = 3e5;
const int MaxK = 2015;
const int Mod = 1e9 + 7;
const int Base = 24;


int facts[MaxSize], invFacts[MaxSize];

int powMod(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) { res = ((LL)res * a) % Mod; }
    n >>= 1;
    a = ((LL)a * a) % Mod;
  }
  return res;
}

void preproc() {
  facts[0] = 1;
  for (int i = 1; i < MaxSize; i++) {
    facts[i] = ((LL)facts[i - 1] * i) % Mod;
  }
  invFacts[MaxSize - 1] = powMod(facts[MaxSize - 1], Mod - 2);

  for (int i = MaxSize - 2; i >= 0; i--) {
    invFacts[i] = ((LL)invFacts[i + 1] * (i + 1)) % Mod;
  }
}

int newton(int n, int k) {
  int res = facts[n];
  res = ((LL)res * invFacts[k]) % Mod;
  return ((LL)res * invFacts[n - k]) % Mod;
}


int posR[MaxK], posC[MaxK];
int N, M, K, S;

int dp[MaxK][Base];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  preproc();
  cin >> N >> M >> K >> S;

  int ptr = 1;
  for (int i = 1; i <= K; i++) {
    cin >> posR[ptr] >> posC[ptr];
    if (posR[ptr] == 1 && posC[ptr] == 1) {
      S = (S + 1) / 2;
    } else if (posR[ptr] == N && posC[ptr] == M) {
      S = (S + 1) / 2;
    } else {
      ptr++;
    }
  }

  K = ptr;
  posR[0] = posC[0] = 1;
  posR[K] = N;
  posC[K] = M;
  vector<int> order(K + 1);
  iota(order.begin(), order.end(), 0);
  sort(ALL(order), [&](int lhs, int rhs) {
        return make_pair(posR[lhs], posC[lhs]) < make_pair(posR[rhs], posC[rhs]);
      });

  dp[0][0] = 1;

  for (int i = 0; i < K + 1; i++) {
    debug(i, posR[i], posC[i]);
  }

  for (int i = 1; i < K + 1; i++) {
    int pi = order[i];
    debug(i, pi, posR[pi], posC[pi]);

    for (int j = 0; j < i; j++) {
      int pj = order[j];
      if (posR[pj] > posR[pi] || posC[pj] > posC[pi]) { continue; }

      int dr = posR[pi] - posR[pj],
          dc = posC[pi] - posC[pj];
      int coef = newton(dr + dc, dr);

      for (int cnt = 0; cnt < Base; cnt++) {
        int dps = Mod;
        if (i != K) { dps -= dp[pj][cnt]; }
        if (cnt) { dps += dp[pj][cnt - 1]; }

        dp[pi][cnt] = (dp[pi][cnt] + (LL)coef * dps) % Mod;
        if (cnt < 4) {
          debug(pj, pi, cnt, dp[pi][cnt]);
        }
      }
    }
  }


  int res = 0, rem = newton(N + M - 2, N - 1);
  for (int cnt = 1; cnt < Base; cnt++) {
    res = (res + (LL)S * dp[K][cnt]) % Mod;
    rem = (rem + Mod - dp[K][cnt]) % Mod;
    S = (S + 1) / 2;
  }

  res = (res + rem) % Mod;
  res = ((LL)res * powMod(newton(N + M - 2, N - 1), Mod - 2)) % Mod;

  cout << res << "\n";

}