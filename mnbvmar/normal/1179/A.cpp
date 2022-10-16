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


int32_t main() {
  int n, q;
  scanf("%d%d", &n, &q);

  vi cur(n);
  for (int &x:cur) { scanf("%d", &x); }
  cur.resize(2 * n + 10);

  vector<pii> ans(n + 1);

  int L = 0, R = n;

  for (int i = 0; i < n; ++i) {
    int A = cur[L];
    int B = cur[L + 1];
    ans[i + 1] = pii{A, B};
    if (A < B) { swap(A, B); }
    cur[L + 1] = A;
    cur[R] = B;
    ++L; ++R;
  }

  for (int i = 0; i < q; ++i) {
    ll which;
    scanf("%lld", &which);
    if (which <= n) {
      printf("%d %d\n", ans[which].st, ans[which].nd);
    } else {
      const int pos = L + 1 + (which - n - 1) % (n - 1);
      printf("%d %d\n", cur[L], cur[pos]);
    }
  }
}