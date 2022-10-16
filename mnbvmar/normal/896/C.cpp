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
template<class L, class R> ostream &operator<<(ostream& os, map<L,R> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const LL Infty = 1e18;
map<int, LL> Intervals;
int N, M, Seed, VMax;

int rnd() {
  int Ret = Seed;
  Seed = ((LL)Seed * 7 + 13) % 1000000007;
  return Ret;
}

map<int, LL>::iterator splitBefore(int Pos) {
  if (Pos == 0)
    return Intervals.begin();
  
  auto Iter = prev(Intervals.upper_bound(Pos));
  if (Iter->first == Pos)
    return Iter;

  return Intervals.insert(make_pair(Pos, Iter->second)).first;
}

void increase(int L, int R, int x) {
  auto Begin = splitBefore(L);
  auto End = splitBefore(R + 1);

  for (auto It = Begin; It != End; ++It)
    It->second += x;
}

void setConst(int L, int R, int x) {
  auto Begin = splitBefore(L);
  auto End = splitBefore(R + 1);
  for (auto It = Begin; It != End;) {
    auto NextIt = next(It);
    Intervals.erase(It);
    It = NextIt;
  }
  Intervals.insert(make_pair(L, x));
}

LL findKth(int L, int R, int k) {
  auto Begin = splitBefore(L);
  auto End = splitBefore(R + 1);
  vector<pair<LL, int>> Data;
  for (auto It = Begin; It != End; ++It) {
    int Length = next(It)->first - It->first;
    Data.emplace_back(It->second, Length);
  }

  sort(ALL(Data));
  for (auto &El : Data) {
    if (El.second >= k)
      return El.first;
    else
      k -= El.second;
  }

  assert(false);
  return 0;
}

LL powMod(int a, int n, int m) {
  LL Result = 1;
  while (n) {
    if (n & 1) { Result = ((LL)Result * a) % m; }
    n >>= 1;
    a = ((LL)a * a) % m;
  }
  return Result;
}

LL sumPowers(int L, int R, int x, int Mod) {
  auto Begin = splitBefore(L);
  auto End = splitBefore(R + 1);
  long long Result = 0;
  for (auto It = Begin; It != End; ++It) {
    int Length = next(It)->first - It->first;
    Result += Length * powMod(It->second % Mod, x, Mod);
  }
  return Result % Mod;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M >> Seed >> VMax;
  for (int i = 0; i < N; ++i) {
    int a = rnd() % VMax + 1;
    debug(a);
    Intervals.insert(make_pair(i, a));
  }
  Intervals.insert(make_pair(N, 0));

  for (int i = 0; i < M; ++i) {
    int Op = rnd() % 4 + 1;
    debug(Op);
    int L = rnd() % N;
    int R = rnd() % N;

    if (L > R) { swap(L, R); }

    if (Op == 3) {
      int x = rnd() % (R - L + 1) + 1;
      cout << findKth(L, R, x) << "\n";
    } else {
      int x = rnd() % VMax + 1;

      if (Op == 1)
        increase(L, R, x);
      else if (Op == 2)
        setConst(L, R, x);
      else {
        int y = rnd() % VMax + 1;
        cout << sumPowers(L, R, x, y) << "\n";
      }
    }

#ifdef LOCAL
    debug(Intervals);
#endif
  }
}