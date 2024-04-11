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


const int MaxVal = 3e5 + 100;

int next_prime[MaxVal];

void Sieve() {
  iota(next_prime, next_prime + MaxVal, 0);
  for (int p = 2; p * p < MaxVal; ++p) {
    if (next_prime[p] != p) { continue; }
    for (int i = p * p; i < MaxVal; i += p)
      next_prime[i] = p;
  }
}

int MakeSquarefree(int n) {
  int res = 1;
  while (n > 1) {
    const int p = next_prime[n];
    if (res % p != 0) { res *= p; }
    n /= p;
  }
  return res;
}

int dist[MaxVal * 2];
bool has_num[MaxVal];
bool has_square[MaxVal];
int N;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  Sieve();

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    v = MakeSquarefree(v);
    debug(v);
    has_num[v] = true;
  }

  fill_n(dist, MaxVal, (int)1e9);
  dist[1] = 0;

  for (int d = 1; d < MaxVal; ++d) {
    vector<int> coefs(MaxVal / d + 5);
    int cnt_nums = 0;

    for (int i = d; i < MaxVal; i += d) {
      if (!has_num[i]) { continue; }
      ++cnt_nums;
      const int v = i / d;

      vector<int> primes;
      int v_copy = v;
      while (v_copy > 1) {
        primes.push_back(next_prime[v_copy]);
        v_copy /= primes.back();
      }

      if (d < 10) { debug(d, i, primes); }

      for (int m = 1; m < (1 << SZ(primes)); ++m) {
        int x = -1;
        int which = 1;
        for (int z = 0; z < SZ(primes); ++z) {
          if (!((m >> z) & 1)) { continue; }
          x = -x;
          which *= primes[z];
        }
        if (d < 10) { debug(which, x); }
        coefs[which] += x;
      }
    }

    if (d < 10)
      debug(d, vector<int>(coefs.begin(), coefs.begin() + 10));

    vector<int> occurs(MaxVal / d + 1);

    for (int e = 1; e <= MaxVal / d; ++e) {
      if (!coefs[e]) { continue; }
      for (int i = e; i <= MaxVal / d; i += e)
        occurs[i] += coefs[e];
    }

    for (int i = 1; i <= MaxVal / d; ++i) {
      if (occurs[i] != cnt_nums) {
        if (d < 10 && i < 10) { debug(d, d * i); }
        mini(dist[i * d], 1 + dist[d]);
      }
    }
  }

  int ans = 1e9;
  for (int i = 0; i < MaxVal; ++i)
    if (has_num[i])
      mini(ans, 1 + dist[i]);

  if (ans > 1e7)
    ans = -1;
  cout << ans << "\n";
}