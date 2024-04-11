#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define st first
#define nd second
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

using ll = long long;
#define int ll
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;
using LL = ll;

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
  // Jesli n > 2^32: losowac kilkanascie razy wit
  for (int i = 0; i < 20; ++i) {
    if (witness(T(rand() % (n - 2) + 2), n)) { return false; }
  }
  return true;
}

// SOLOVAY-STRASSEN
// Computes jacobi symbol; m must be odd
// if m prime => result = 0 if m | n, 1 if n is a quadr. resid. mod m, -1 otherwise
template<class T> int jacobi(T n, T m) {
  int r = 1; n %= m;
  while (n > 1) {
    while (n % 2 == 0) {
      n /= 2;
      if (m % 8 == 3 || m % 8 == 5) { r *= -1; }
    }
    swap(n, m);
    if (n % 4 == 3 && m % 4 == 3) { r *= -1; }
    n %= m;
  }
  return r;
}

// POLARD'S RHO
// a - parameter, shall not be equal to 0 or -2.
// returns a divisor, a proper one when succeeded, equal to n if failed
// in case of failure, change a
template<class T> T rho(const T &n, const T a) {
  auto addmod = [&](const T &a, const T &b) { return (a + b) % n; };
  auto mulmod = [&](const T &a, const T &b) { return fastop(a, b, T(0), addmod); };
  auto f = [&](const T &x) { return addmod(mulmod(x, x), a); };
  T x = 2, y = 2;
  while (true) {
    x = f(x); y = f(f(y)); T d = __gcd(n, abs(x - y)); if (d != 1) { return d; }
  }
}

template<class T> T get_factor(T n) {
  if (n % 2 == 0) { return 2; } if (n % 3 == 0) { return 3; }
  if (n % 5 == 0) { return 5; }
  while (true) {
    T d = rho(n, T(rand()%100 + 2)); if(d != n) { return d; }
  }
}

template<class T> void __factorize(const T &n, vector<T> &x) {
  if (n == 1) { return; }
  else if (miller(n)) { x.push_back(n); }
  else {
    T d = get_factor(n); __factorize(d, x); __factorize(n / d, x);
  }
}

template<class T> vector<T> factorize(const T &n) {
  vector<T> x; __factorize(n, x); return x;
}
const ld kEps = 1e-3;

void Fail() {
  printf("-1\n"); exit(0);
}

int32_t main() {
  ll n, p, m;
  scanf("%lld%lld%lld", &n, &m, &p);

  ll q = m, pwr = 1;

  auto addmod = [&](LL a, LL b) { return (a + b) % m; };
  auto mulmod = [&](LL a, LL b) { return fastop(a, b, 0LL, addmod); };
  auto powmod = [&](LL a, LL b) { return fastop(a, b, 1LL, mulmod); };

  for (int alpha = 60; alpha >= 2; --alpha) {
    const int x = (int)(pow(m, (ld)1 / alpha) + 0.01);

    int t = 1;
    for (int i = 0; i < alpha; ++i) {
      int u = mulmod(t, x);
      if (i != alpha - 1 && u / x != t) { t = -1; break; }
      t = u;
    }

    if (t == 0) {
      q = x; pwr = alpha; break;
    }
  }

  assert(q != -1);
  debug(q, pwr);

  const ll gsize = m / q * (q - 1);
  if (n >= gsize) { Fail(); }

  if (p % q == 0) {
    int nfound = 0;
    for (ll x = 2; x < m; ++x) {
      if (x % q == 0) { continue; }
      ++nfound;
      printf("%lld ", x);
      if (nfound == n) { break; }
    }
    printf("\n");
    return 0;
  }
  if (n <= gsize - 2 && p == m - 1) {
    int nfound = 0;
    for (ll x = 2; x < m - 1; ++x) {
      if (x % q == 0) { continue; }
      ++nfound;
      printf("%lld ", x);
      if (nfound == n) { break; }
    }
    printf("\n");
    return 0;
  }

  vector<ll> order_facts(pwr - 1, q);

  for (ll x : factorize(q - 1)) {
    order_facts.PB(x);
  }

  auto GetOrder = [&](ll num) {
    ll m_order = gsize;
    for (ll pr : order_facts) {
      if (powmod(num, m_order / pr) <= 1) {
        m_order /= pr;
      }
    }
    return m_order;
  };


  ll m_order = GetOrder(p);
  debug(gsize, m_order);

  const ll num_rem = gsize - m_order;
  if (n > num_rem) {
    Fail();
  }
  //if (m > 1e9) { assert(false); }

  vector<ll> answers;

  ll gen;
  ll ord;
  if (q == 2) {
    assert(pwr >= 2);
    gen = 5 % m;
    ord = gsize / 2;

    ll baddiv = ord / m_order;

    // pos
    ll num = 1;
    for (ll x = 0; x < ord; ++x) {
      if (x % baddiv != 0) {
        answers.PB(num);
        answers.PB(m - num);
      } else {
        if (x % (baddiv * 2) == 0 || p % 4 == 1) {
          answers.PB(m - num); 
        } else {
          answers.PB(num);
        }
      }
      num = mulmod(num, gen);
      if (SZ(answers) >= n) {
        answers.resize(n); break;
      }
    }

  } else {
    ord = gsize;
    while (true) {
      gen = rand();
      gen <<= 16;
      gen ^= rand();
      gen <<= 16;
      gen %= m;
      gen = abs(gen);
      if (GetOrder(gen) == gsize) { break; }
    }

    const ll maxg = ord / m_order;
    ll num = 1;

    debug(gen, maxg);
    
    for (ll g = 1; g < maxg; ++g) {
      num = mulmod(num, gen);
      ll cnum = num;
      for (ll h = 0; h < m_order; ++h) {
        answers.PB(cnum);
        cnum = mulmod(cnum, p);
        if (SZ(answers) >= n) { break; }
      }
      if (SZ(answers) >= n) { break; }
    }
  }

  assert(SZ(answers) >= n);
  answers.resize(n);
  sort(ALL(answers));
  answers.resize(unique(ALL(answers)) - answers.begin());
  assert(SZ(answers) == n);

  for (ll x : answers) {
    printf("%lld ", x);

  }
  printf("\n");

    
}