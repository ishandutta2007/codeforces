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
template<class T> ostream &operator<<(ostream& os, set<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}
template<class K, class W> ostream &operator<<(ostream& os, map<K,W> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 512;


template<class T, class U, class Op> T fastop(T a, U b, T r, const Op &op) {
  while (b > 0) {
    if (b % 2 == 1) { r = op(r, a); }
    a = op(a, a);
    b /= 2;
  }
  return r;
}

// MILLER-RABIN
template<class T> bool witness(T wit, T n) {
  if (wit >= n) { return false; }
  auto addmod = [&](T a, T b) { return (a + b) % n; };
  auto mulmod = [&](T a, T b) { return fastop(a, b, T(0), addmod); };
  auto powmod = [&](T a, T b) { return fastop(a, b, T(1), mulmod); };
  int s; T t;
  for (s = 0, t = n - 1; t % 2 == 0; s++, t /= 2);
  wit = powmod(wit, t);
  if (wit == 1 || wit == n - 1) { return false; }
  for (int i = 1; i < s; ++i) {
    wit = mulmod(wit, wit);
    if (wit == 1) { return true; } if (wit == n - 1) { return false; }
  }
  return true;
}

// Is n prime?
template<class T> bool miller(T n) {
  if (n == 2) { return true; }
  if (n % 2 == 0 || n < 2) { return false; }
  for (int x : vector<LL>{2, 325, 9375, 28178, 450775, 9780504, 1795265022LL})
    if (witness(T(x), n)) { return false; }
  return true;
}

const int Mod = 998'244'353;

int N;
vector<LL> tab;
map<int, int> primes;
map<LL, int> nonprimes;

LL IntPow(LL a, int n) {
  LL r = 1;
  for (int i = 0; i < n; ++i)
    r *= a;
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  tab.resize(N);
  for (LL &x : tab) cin >> x;

  for (LL &x : tab) {
    debug(x, primes, nonprimes);
    for (int a = 4; a >= 2; --a) {
      LL t = (int)(pow((LD)x, 1. / a) - 1);
      while (t <= 0) { ++t; }
      while (IntPow(t, a) < x) { ++t; }
      if (IntPow(t, a) == x) {
        primes[t] += a;
        x = 1;
        break;
      }
    }

    if (x == 1) { continue; }

    bool found = false;
    for (auto tp : nonprimes) {
      const LL t = tp.first;
      if (t == x) { ++nonprimes[t]; found = true; break; }

      const LL g = __gcd(t, x);
      if (g == 1) { continue; }
      primes[g] += 1 + tp.second;
      ++primes[x / g];
      primes[t / g] += tp.second;
      nonprimes.erase(tp.st);
      found = true;
      break;
    }

    if (!found)
      ++nonprimes[x];
  }
  debug(primes, nonprimes);

  map<int,int> new_primes;
  LL answer = 1;

  for (auto &np : nonprimes) {
    bool found = false;
    for (auto &P : primes) {
      if (np.st % P.st == 0) {
        new_primes[P.st] += np.nd;
        new_primes[np.st / P.st] += np.nd;
        found = true;
        break;
      }
    }
    if (!found) {
      answer = ((LL)answer * (np.nd + 1)) % Mod;
      answer = ((LL)answer * (np.nd + 1)) % Mod;
    }
  }

  for (auto &x : new_primes)
    primes[x.st] += new_primes[x.st];

  debug(primes, answer);

  for (auto &p : primes)
    answer = ((LL)answer * (p.nd + 1)) % Mod;

  cout << answer << "\n";
  
}