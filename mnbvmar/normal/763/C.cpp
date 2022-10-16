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

const int MaxNums = 1e5 + 100;

int M, N;
int Nums[MaxNums];
int ModNums[MaxNums];
set<int> SetModNums;
int Mean;

int powMod(int a, int x) {
  int Res = 1;
  while (x) {
    if (x % 2 == 1) { Res = ((LL)Res * a) % M; }
    x >>= 1;
    a = ((LL)a * a) % M;
  }
  return Res;
}

inline int mulMod(int a, int b) {
  return (a * b) % M;
}

void check(int a, int b) {
  int t = a;
  for (int i = 0; i < N; ++i) {
    if (!SetModNums.count(t))
      return;
    t = (t + b) % M;
  }

  cout << (a + Mean) % M << " " << b << "\n";
  exit(0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> M >> N;

  if (N == M) {
    cout << "0 1\n";
    return 0;
  }

  long long Total = 0;

  for (int i = 0; i < N; ++i) {
    cin >> Nums[i];
    Total += Nums[i];
  }

  if (N == M - 1) {
    int Missing = (LL)M * (M - 1) / 2 - Total;
    debug(Missing);
    cout << (Missing + 1) % M << " 1\n";
    return 0;
  }

  if (N == 1) {
    cout << Total << " 0\n";
    return 0;
  }

  assert(M >= 5);

  int TotalM = Total % M;
  Mean = ((LL)TotalM * powMod(N, M - 2)) % M;

  for (int i = 0; i < N; ++i) {
    ModNums[i] = (Nums[i] + M - Mean) % M;
    SetModNums.insert(ModNums[i]);
  }

  debug(vector<int>(ALL(SetModNums)));

  int SumSq = 0;
  for (int x : ModNums)
    SumSq = (SumSq + (LL)x * x) % M;

  debug(Mean, SumSq);

  for (int aId = 0; aId < N; ++aId) {
    int a = ModNums[aId];
    int b = (2 * a * powMod(M + 1 - N, M - 2)) % M;

    int s = (N * a % M) * a % M;
    debug(s);
    s = (s + mulMod(mulMod(mulMod(a, b), N), N - 1)) % M;
    debug(s);
    s = (s + mulMod(mulMod(mulMod(mulMod(mulMod(b, b), N), N - 1), 2 * N - 1),
                    powMod(6, M - 2))) % M;
    debug(a, b, s);
    if (s == SumSq)
      check(a, b);
  }

  cout << "-1\n";

}