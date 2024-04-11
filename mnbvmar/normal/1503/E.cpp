//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
  *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int mod = 998244353;

inline void add_mod(int &a, int b) {
	a += b;
	if (a >= mod) { a -= mod; }
}
inline void sub_mod(int &a, int b) {
	a -= b;
	if (a < 0) { a += mod; }
}
inline int mul_mod(int a, int b) {
	return (int)((ll)a * b % mod);
}
inline int pow_mod(int a, int n) {
	int r = 1;
	while (n) {
		if (n & 1) { r = mul_mod(r, a); }
		n >>= 1;
		a = mul_mod(a, a);
	}
	return r;
}
inline int inv_mod(int a) {
	return pow_mod(a, mod - 2);
}
inline int div_mod(int a, int b) {
	return mul_mod(a, inv_mod(b));
}

const int kMaxN = 2222;

int ngrid[kMaxN][kMaxN];

void Preproc() {
  ngrid[0][0] = 1;
  for (int r = 0; r < kMaxN; ++r) {
    for (int c = 0; c < kMaxN; ++c) {
      if (r) { add_mod(ngrid[r][c], ngrid[r - 1][c]); }
      if (c) { add_mod(ngrid[r][c], ngrid[r][c - 1]); }
    }
  }
}

int optr[kMaxN], optl[kMaxN];

int Solve(int n, int m, bool allow_touch) {
  int ans = 0;
  for (int c = 1; c <= m - 1; ++c) {
    int curup = 0;
    for (int r2 = 1; r2 <= n - 1; ++r2) {
      add_mod(curup, ngrid[m - c - 1][r2 - 1]);
      optr[r2] = mul_mod(ngrid[m - c - 1][n - r2], curup);
    }

    int curdn = 0;
    for (int r3 = n; r3 > 1; --r3) {
      add_mod(curdn, ngrid[c - 1][n - r3]);
      optl[r3] = mul_mod(ngrid[c - 1][r3 - 1], curdn);
    }

    for (int r3 = n - 1; r3 >= 0; --r3) {
      add_mod(optl[r3], optl[r3 + 1]);
    }

    for (int r2 = 1; r2 <= n - 1; ++r2) {
      const int min_r3 = r2 + 1 + !allow_touch;
      add_mod(ans, mul_mod(optr[r2], optl[min_r3]));
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  Preproc();

  int n, m;
  cin >> n >> m;
  if (n > m) { swap(n, m); }
  int ans = mul_mod(2, Solve(n, m, true));
  add_mod(ans, mul_mod(2, Solve(m, n, false)));
  cout << ans << "\n";
}