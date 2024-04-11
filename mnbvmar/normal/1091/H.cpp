#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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
//#define cerr if(0)cout
#endif

const int MaxSize = 2e5 + 100;

int N, F;
int mex_values[MaxSize];
bool is_prime[MaxSize];
bitset<MaxSize> is_gut;
bitset<MaxSize> is_not_gut;
bitset<MaxSize> is_unknown;

void Sieve() {
  fill_n(is_prime, MaxSize, true);
  for (int p = 2; p * p < MaxSize; ++p) {
    if (!is_prime[p]) { continue; }
    for (int i = p * p; i < MaxSize; i += p)
      is_prime[i] = false;
  }
}

bool has_mex[MaxSize];

void Preproc() {
  Sieve();
  for (int a = 2; a < MaxSize; ++a) {
    if (!is_prime[a]) { continue; }
    is_gut[a] = true;
    for (int b = 2; a * b < MaxSize; ++b) {
      is_gut[a * b] = is_gut[a * b] | is_prime[b];
    }
  }
  is_gut[F] = false;
  for (int i = 1; i < MaxSize; ++i)
    is_not_gut[i] = !is_gut[i];

  for (int i = 1; i < MaxSize; ++i) {
    is_unknown[i] = true;
  }

  for (int mval = 0; mval < MaxSize; ++mval) {
    bitset<MaxSize> c = is_unknown;

    auto Add = [&](int val) {
      c &= is_not_gut << val;
    };

    if (mval == 0) {
      Add(0);
    }
    int last_val = 0;

    while (c.any()) {
      int pos = c._Find_next(last_val);
      Add(pos);
      is_unknown[pos] = false;
      mex_values[pos] = mval;
      debug(mval, pos);
    }
  }

  for (int i = 0; i < 30; ++i) {
    cerr << i << " -> " << mex_values[i] << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> F;
  Preproc();

  int cur_mex = 0;

  for (int i = 0; i < N; ++i) {
    int b, w, r;
    cin >> b >> w >> r;
    const int ha = w - b - 1;
    const int hb = r - w - 1;
    cur_mex ^= mex_values[ha] ^ mex_values[hb];
  }

  if (cur_mex == 0) {
    cout << "Bob\nAlice\n";
  } else {
    cout << "Alice\nBob\n";
  }
}