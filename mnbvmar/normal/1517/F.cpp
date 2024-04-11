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

const int kMaxN = 310;

int dp_a[kMaxN][kMaxN];
int dp_b[kMaxN][kMaxN];
int sz[kMaxN];

int n;
vi adj[kMaxN];

int CountSmaller(int k) {
  auto Merge = [&](int dst, int src) {
    // const int tmp = 0;
    memcpy(dp_a[0], dp_a[dst], sizeof(dp_a[0]));
    memcpy(dp_b[0], dp_b[dst], sizeof(dp_b[0]));
    memset(dp_a[dst], 0, sizeof(dp_a[0]));
    memset(dp_b[dst], 0, sizeof(dp_b[0]));

    vi iter_i, iter_j;
    for (int i = 0; i <= k; ++i) {
      if (dp_a[0][i] || dp_b[0][i] ) { iter_i.push_back(i); }
      if (dp_a[src][i] || dp_b[src][i] ) { iter_j.push_back(i); }
    }

    // int total_src = 0;
    // for (int i = 0; i <= k; ++i) {
    //   add_mod(total_src, dp_a[src][i]);
    //   add_mod(total_src, dp_b[src][i]);
    // }
    // add_mod(total_src, dp_x[src]);

    for (int i : iter_i) {
      for (int j : iter_j) {
        // A(i), A(j)
        {
          const int x = min(i, j + 1);
          add_mod(dp_a[dst][x], mul_mod(dp_a[0][i], dp_a[src][j]));
        }
        // A(i), B(j)
        if (i >= j) {
          const int x = j - 1;
          if (x > 0) {
            add_mod(dp_b[dst][x], mul_mod(dp_a[0][i], dp_b[src][j]));
          }
        } else {
          // const int x = i;
          add_mod(dp_a[dst][i], mul_mod(dp_a[0][i], dp_b[src][j]));
        }
        // B(i), A(j)
        if (j >= i) {
          add_mod(dp_b[dst][i], mul_mod(dp_b[0][i], dp_a[src][j]));
        } else {
          add_mod(dp_a[dst][j + 1], mul_mod(dp_b[0][i], dp_a[src][j]));
        }
        // B(i), B(j)
        {
          const int x = min(i, j - 1);
          if (x > 0) {
            add_mod(dp_b[dst][x], mul_mod(dp_b[0][i], dp_b[src][j]));
          }
        }
      }
    }
  };

  function<void(int, int)> Dfs = [&](int v, int p) {
    sz[v] = 1;
    dp_a[v][0] = 1;
    dp_b[v][k] = 1;
    for (int s : adj[v]) {
      if (s == p) { continue; }
      Dfs(s, v);
      sz[v] += sz[s];
      Merge(v, s);
    }
  };

  memset(dp_a, 0, sizeof(dp_a));
  memset(dp_b, 0, sizeof(dp_b));
  memset(sz, 0, sizeof(sz));

  Dfs(1, -1);

  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    add_mod(ans, dp_a[1][i]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = 0;
  const int all_ass = pow_mod(2, n);
  for (int k = 1; k <= n; ++k) {
    const int smaller = CountSmaller(k);
    debug() << imie(k) << imie(smaller);
    add_mod(ans, all_ass);
    sub_mod(ans, smaller);
  }
  sub_mod(ans, 1);
  debug() << imie(ans);
  cout << div_mod(ans, all_ass) << "\n";
}