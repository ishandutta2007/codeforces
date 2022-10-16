#include <bits/stdc++.h>

#define ALL(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i <= b; i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define RE(i,n) FOR(i,1,n)
#define PB push_back
#define SZ(x) (int)(x).size()
#define VI vector<int>
#define LL long long

using namespace std;

template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int powMod(int a, LL n, int p) {
  int res = 1;
  while (n) {
    if (n & 1) res = ((LL)res * a) % p;
    n >>= 1;
    a = ((LL)a * a) % p;
  }
  return res;
}

int invMod(int a, int p) { return powMod(a, p - 2, p); }

const int Mod = 998244353,
          Gen = 3;

struct FFT {
private:
  int* A;
  int* B;
  int* tmp;
  int* res;
  int* omega;
  int* perm;
  int maxh;
  // not needed if this is going to be used just once
  void Clear(int n) {
    REP (i, n) {
      A[i] = B[i] = res[i] = tmp[i] = 0;
    }
  }

  void fft(int* from, int* to, int depth, bool inv){
    int N = (1 << depth);
    for (int i = 0; i < N; i++) {
      to[perm[i] >> (maxh - depth)] = from[i];
    }
    for (int m = 1; m <= depth; m++) {
      int step = 1 << m;
      for (int pos = 0; pos < N; pos += step){
        int cur = 0;
        int delta = 1 << (maxh - m);
        if (!inv) {
          cur = 1 << maxh;
          delta *= -1;
        }
        int *lft = to + pos, *rgt = lft + step / 2;
        for (int k = 0; k < step / 2; k++) {
          int a = *lft, b = ((LL)omega[cur] * *rgt) % Mod;
          *lft++ = (a + b) % Mod; *rgt++ = (a - b + Mod) % Mod;
          cur += delta;
        }
      }
    }

    if (inv) {
      int Ninv = invMod(N, Mod);
      for (int i = 0; i < N; i++) to[i] = (LL)to[i] * Ninv % Mod;
    }
  }
  
public:
  FFT(int deg) { // max degree of a polynomial given as input
    maxh = 0; int N = 1, h = -1;
    while (N <= 2 * deg) { maxh++; N *= 2; }
    deg = N + 20;
    A = new int[deg];
    B = new int[deg];
    res = new int[deg];
    tmp = new int[deg];
    omega = new int[deg];
    perm = new int[deg];

    int pwr = powMod(Gen, (Mod - 1) / N, Mod);
    omega[0] = 1;
    RE (i, N + 1) { omega[i] = (LL)omega[i - 1] * pwr % Mod; }
    perm[0] = 0;
    RE (i, N) {
      if ((i & (i - 1)) == 0) { h++; }
      perm[i] = perm[i ^ (1 << h)] | (1 << (maxh - h - 1));
    }
  }
  VI mul(VI Q, VI R) {
    int depth = 0, size = 1;
    int N = SZ(Q) + SZ(R) - 1;
    while (size < N) { depth++; size *= 2; }
    Clear(size);
    // start miejsca, w ktorym jak mozna mniejsza dokladnosc, to podmienic na komentarze
    // P,Q \in R[x], A = Q * (1+i)/2 + R * (1-i)/2 -> Re(A^2) = P*Q
    copy(ALL(Q), A); copy(ALL(R), B);
    // REP (i, SZ(Q)) { A[i] = CD{.5 * Q[i], .5 * Q[i]}; }
    // REP (i, SZ(R)) { A[i] = A[i] + CD{.5 * R[i], -.5 * R[i]}; }
    // fft(A, tmp, depth, false);
    // REP (i, size) tmp[i] *= tmp[i];
    fft(A, res, depth, false);
    fft(B, tmp, depth, false);
    REP (i, size) tmp[i] = ((LL)tmp[i] * res[i]) % Mod;
    // koniec
    fft(tmp, res, depth, true);
    VI ans;
    REP (i, N) { ans.PB(res[i]); }
    return ans;
  }
  
  VI inv(VI Q, int coefs) {   // n log n
    int P = Mod; Q.resize(coefs);
    VI R(coefs); R[0] = invMod(Q[0], P); assert(Q[0]);
    function<void(int)> getInv = [&](int deg) {
      if (deg == 1) { return; }
      int mid = (deg + 1) / 2;
      getInv(mid);
      auto T = mul(VI(Q.begin(), Q.begin() + deg), VI(R.begin(), R.begin() + mid));
      for (int i = 0; i < mid; i++) { T[i] = P - T[i + mid]; }
      T = mul(VI(R.begin(), R.begin() + mid), VI(T.begin(), T.begin() + mid));
      for (int i = mid; i < deg; i++) { R[i] = T[i - mid]; }
    };
    getInv(coefs); return R;
  }

  // log(Q)=R: assert(Q[0] = 1), R[0] = 0, R'(x) = Q'(x) / Q(x)

  VI fsqrt(VI Q, int coefs) {   // n log^2 n
    int P = Mod;
    int sz = coefs; while (!sz || (sz & (sz - 1))) { sz++; }
    Q.resize(sz);
    assert(Q[0] != 0); int invFst = invMod(Q[0] * 2, P);
    vector<int> R = Q;
    function<void(int, int)> getSqrt = [&](int minDeg, int maxDeg) {
      if (minDeg == maxDeg - 1) {
        R[minDeg] = minDeg ? ((LL)invFst * R[minDeg]) % P : (int)sqrt(Q[0]);
        return;
      }
      int mid = (minDeg + maxDeg) / 2;
      getSqrt(minDeg, mid);
      if (!minDeg) {
        auto T = mul(VI(R.begin(), R.begin() + mid), VI(R.begin(), R.begin() + mid));
        for (int i = mid; i < maxDeg - 1; i++) { R[i] = (R[i] - T[i] + P) % P; }
      } else {
        auto T = mul(VI(R.begin() + minDeg, R.begin() + mid),
                     VI(R.begin(), R.begin() + (maxDeg - minDeg)));
        for (int i = mid; i < maxDeg; i++) { R[i] = (R[i] + 2LL * (P - T[i - minDeg])) % P; }
      }
      getSqrt(mid, maxDeg);
    };
    getSqrt(0, sz);
    return VI(R.begin(), R.begin() + coefs);
  }

  VI fsqrtFast(VI Q, int coefs) {   // n log n
    int P = Mod, Inv2 = (P + 1) / 2; Q.resize(coefs + 1);
    VI R(coefs), I(coefs); R[0] = (int)round(sqrt(Q[0])); I[0] = invMod(Q[0], Mod);
    function<void(int)> getSqrt = [&](int deg) {
      if (deg == 1) { return; }
      int mid = (deg + 1) / 2;
      getSqrt(mid);
      auto T = mul(VI(R.begin(), R.begin() + deg), VI(R.begin(), R.begin() + deg));
      T.PB(0);
      for (int i = 0; i < mid; i++) {
        T[i] = (LL)(Q[i + mid] - T[i + mid] + P) * Inv2 % P;
      }
      T = mul(VI(T.begin(), T.begin() + mid), VI(R.begin(), R.begin() + mid));
      T = mul(VI(T.begin(), T.begin() + mid), VI(I.begin(), I.begin() + mid));
      for (int i = mid; i < deg; i++) { R[i] = T[i - mid]; }

      T = mul(VI(Q.begin(), Q.begin() + deg), VI(I.begin(), I.begin() + mid));
      for (int i = 0; i < mid; i++) { T[i] = P - T[i + mid]; }
      T = mul(VI(I.begin(), I.begin() + mid), VI(T.begin(), T.begin() + mid));
      for (int i = mid; i < deg; i++) { I[i] = T[i - mid]; }
    };
    getSqrt(coefs);
    return R;
  }
};


const int MaxRange = 1e5 + 100;
FFT fft(MaxRange);

int32_t main() {
  int N, M;
  cin >> N >> M;

  //for (auto x : fft.fsqrtFast(VI{1, 4, 4}, 8)) { cerr << x << " "; } cerr << "\n";

  vector<int> costPoly(MaxRange);

  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    costPoly[x] = Mod - 4;
  }
  costPoly[0] = 1;

  //for (auto x : costPoly) { cerr << x << " "; } cerr << "\n";
  costPoly = fft.fsqrtFast(costPoly, MaxRange);
  //for (auto x : costPoly) { cerr << x << " "; } cerr << "\n";
  costPoly[0]++;
  costPoly = fft.inv(costPoly, MaxRange);
  //for (auto x : costPoly) { cerr << x << " "; } cerr << "\n";
  for (int i = 0; i < MaxRange; i++) { costPoly[i] = (costPoly[i] * 2) % Mod; }

  for (int i = 1; i <= M; i++) {
    cout << costPoly[i] << "\n";
  }
}