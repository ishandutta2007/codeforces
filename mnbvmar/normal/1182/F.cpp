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
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using ld = long double;
using LL = ll;

const int M = 5e5;

LL gcd(LL a, LL b, LL& x, LL& y){
  if (a < b) return gcd(b, a, y, x);
  if (b == 0) { x = 1; y = 0; return a; }
  LL xp; LL pom = gcd(b, a % b, xp, x);
  y = xp - x * (a / b);
  return pom;
}

void Test() {
  int a, b, p, q;
  scanf("%d%d%d%d", &a, &b, &p, &q);

  p %= q;
  const int g = gcd(p, q);
  p /= g; q /= g;

  ll coef_p, coef_q;

  gcd(p, q, coef_p, coef_q);
  coef_p %= q;
  if (coef_p < 0) { coef_p += q; }
  int inv_p = coef_p;
  debug(p, q, inv_p);


  auto Get = [&](int x) {
    return (ll)x * p % q;
  };

  const int lbound = min(b, a + M);
  int cur = Get(a);
  int best_res = min(cur, q - cur);
  int who_best = a;

  for (int i = a; i <= lbound; ++i) {
    const int res = min(cur, q - cur);
    if (res > best_res) {
      best_res = res; who_best = i;
    }
    cur += p;
    if (cur >= q) { cur -= q; }
  }

  const int rbound = max(a, b - M);
  cur = Get(rbound);
  for (int i = rbound; i <= b; ++i) {
    const int res = min(cur, q - cur);
    if (res > best_res) {
      best_res = res; who_best = i;
    }
    cur += p;
    if (cur >= q) { cur -= q; }
  }

  const int resl = max(0, q / 2 - M);
  const int resr = min(q - 1, q / 2 + M);

  for (int r = resl; r <= resr; ++r) {
    const int score = min(r, q - r);
    if (score < best_res) { continue; }

    int base_x = ((ll)r * inv_p) % q;
    if (base_x < a) {
      const int dist = a - base_x;
      const int njumps = (dist + q - 1) / q;
      base_x += njumps * q;
    }
    if (base_x > b) { continue; }
    debug(r, base_x);

    if (best_res == score) {
      mini(who_best, base_x);
    } else {
      best_res = score;
      who_best = base_x;
    }
  }


  printf("%d\n", who_best);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int t;
  scanf("%d", &t);
  while (t--) { Test(); }

}