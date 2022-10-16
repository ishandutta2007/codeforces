#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

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

const LD kPi = 2 * acos(0);

struct CD {
  LD re, im;
  CD operator=(LD a) { re = a; im = 0; return *this; }
  CD operator*(CD& z) { return {re * z.re - im * z.im, re * z.im + im * z.re}; }
  void operator*=(CD& z) { *this = (*this * z); }
  CD operator+(CD& z) { return {re + z.re, im + z.im}; }
  CD operator-(CD& z) { return {re - z.re, im - z.im}; }
  void operator/=(LD f) { re /= f; im /= f; }
};

int powMod(int a, int n, int p) {
  int res = 1;
  while (n) {
    if (n & 1) { res = ((LL)res * a) % p; }
    n >>= 1; a = ((LL)a * a) % p;
  }
  return res;
}

struct FFT {
private:
  CD *A, *B, *tmp, *res, *omega;
  int *perm;
  int maxh;
  // not needed if this is going to be used just once
  void Clear(int n) {
    REP (i, n) { A[i] = B[i] = res[i] = tmp[i] = 0; }
  }
  
  void fft(CD* from, CD* to, int depth, bool inv){
    int N = (1 << depth);
    for (int i = 0; i < N; i++) { to[perm[i] >> (maxh - depth)] = from[i]; }
    RE (m, depth) {
      int step = 1 << m;
      for (int pos = 0; pos < N; pos += step){
        int cur = 0;
        int delta = 1 << (maxh - m);
        if (!inv) { cur = 1 << maxh; delta *= -1; }
        CD *lft = to + pos, *rgt = lft + step / 2;
        REP (k, step / 2) {
          CD a = *lft, b = omega[cur] * *rgt;
          *lft++ = a + b; *rgt++ = a - b;
          cur += delta;
        }
      }
    }

    if (inv) { REP (i, N) { to[i] /= N; } }
  }
  
public:
  FFT(int deg) { // max degree of a polynomial given as input
    maxh = 0; int N = 1, h = -1;
    while (N <= 2 * deg) { maxh++; N *= 2; }
    deg = N + 20;
    A = new CD[deg];
    B = new CD[deg];
    res = new CD[deg];
    tmp = new CD[deg];
    omega = new CD[deg];
    perm = new int[deg];
    LD ang = 2 * kPi / N;
    REP (i, N + 1) { omega[i] = {cos(i * ang), sin(i * ang)}; }
    perm[0] = 0;
    RE (i, N - 1) {
      if ((i & (i - 1)) == 0) { h++; }
      perm[i] = perm[i ^ (1 << h)] | (1 << (maxh - h - 1));
    }
  }
  VI mul_less_exact(VI Q, VI R, int P) {
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
    REP (i, size) tmp[i] *= res[i];
    // koniec
    fft(tmp, res, depth, true);
    VI ans;
    REP (i, N) { ans.PB((long long)round(res[i].re) % P); }
    return ans;
  }
  
  VI Prepare(VI& v, int base, int bpow) {
    VI ans;
    for (int x : v) { ans.PB(bpow ? x / base : x % base); }
    return ans;
  }
  int Sum(VI& v, int P) { // debug/assert purposes only
    return accumulate(ALL(v), 0LL) % P;
  }
  VI mul_exact(VI Q, VI R, int P) {
    int base = 32000;
    int pows[] = {1, base, (int)1LL * base * base % P};
    VI ans(SZ(Q) + SZ(R) - 1);
    REP (q, 2) {
      VI W = Prepare(Q, base, q);
      REP (r, 2) {
        VI V = Prepare(R, base, r);
        // jezeli bedzie za wolno, to mona policzyc tylko 4 transformaty w przod
        // bo teraz dla kazdej z 4 czesci jest liczona podwojnie (przyspieszenie * 2/3)
        VI C = mul_less_exact(W, V, P);
        REP (i, SZ(C)) { ans[i] = (ans[i] + 1LL * C[i] * pows[q + r]) % P; }
      }
    }
    /*debug(Sum(ans, P), 1LL * Sum(Q, P) * Sum(R, P) % P);    // DEBUG!!
    assert(Sum(ans, P) == 1LL * Sum(Q, P) * Sum(R, P) % P); // DEBUG!!*/
    return ans;
  }
};

map<int, int> sizes;

void RecSort(int L, int R, int depth) {
  if (R == L || depth == 1) {
    ++sizes[R - L + 1];
    return;
  }
  const int m = (L + R) / 2;
  RecSort(L, m, depth - 1);
  RecSort(m + 1, R, depth - 1);
}

int N, K, Q;

int PowMod(int a, int n) {
  int r = 1;
  while (n) {
    if (n % 2 == 1) { r = (LL)r * a % Q; }
    n >>= 1;
    a = (LL)a * a % Q;
  }
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> N >> K >> Q;
  RecSort(1, N, K);
  assert(SZ(sizes) <= 2);

  map<int, VI> exp_lens_map;

  int answer = 0;

  vector<int> szs;

  for (auto [size, cnt] : sizes) {
    vector<int> exp_lens(size + 1);

    LL suf_sum = PowMod(size, Q - 2);

    for (int l = size; l >= 1; --l) {
      if (l < size) {
        LL coef = PowMod((LL)l * (l + 1) % Q, Q - 2);
        suf_sum = (suf_sum + coef) % Q;
      }
      exp_lens[l] = suf_sum;
    }

    debug(size, cnt, exp_lens);
    exp_lens_map[size] = exp_lens;

    answer = (answer + (LL)size * (size - 1) % Q * PowMod(4, Q - 2) % Q * cnt) % Q;

    szs.PB(size);
  }

  if (K == 1) {
    cout << answer << "\n";
    return 0;
  }

  FFT fft(N + 2);

  auto Prepare = [&](int L, bool more_mul) {
    vector<int> ans(L + 1);
    auto exp_len = exp_lens_map[L];
    debug(L, exp_len);
    for (int i = 1; i <= L; ++i) {
      ans[i] = (LL)exp_len[i] * i % Q;
      if (more_mul)
        ans[i] = (LL)ans[i] * (i - 1) % Q;
    }
    return ans;
  };

  auto GetSingleAns = [&](int L, int R) {
    vector<int> ans_l = Prepare(L, false);
    vector<int> ans_r = Prepare(R, true);
    auto mul = fft.mul_exact(ans_l, ans_r, Q);
    debug(ans_l, ans_r, mul);
    int ans = 0;
    for (int i = 1; i <= L + R; ++i) {
      ans = (ans + (LL)mul[i] * PowMod(2 * i, Q - 2)) % Q;
    }
    debug(ans);
    return ans;
  };

  for (int i = 0; i < SZ(szs); ++i) {
    for (int j = 0; j < SZ(szs); ++j) {
      int single_ans = GetSingleAns(szs[i], szs[j]);
      const int a = szs[i];
      const int b = szs[j];
      int num_types =
        (i == j ? (LL)sizes[a] * (sizes[a] - 1) : (LL)sizes[a] * sizes[b]) % Q;
      debug(i, j, num_types);
      int multi_ans = (LL)single_ans * num_types % Q;
      answer = (answer + multi_ans) % Q;
    }
  }

  /*debug(answer);

  
  for (int i = 0; i < SZ(szs); ++i)
    for (int j = 0; j < SZ(szs); ++j) {
      if (i == j) { continue; }
      for (int l = 1; l <= szs[i]; ++l) 
        for (int r = 1; r <= szs[j]; ++r) {
          LL coef = (LL)exp_lens_map[szs[i]][l] * l % Q;
          coef = coef * exp_lens_map[szs[j]][r] % Q;
          coef = coef * r % Q;
          coef = coef * (r - 1) % Q;
          coef = coef * PowMod(2 * (l + r), Q - 2) % Q;
          answer = (answer + coef) % Q;
        }
    }*/

  cout << answer << "\n";


}