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

struct DynSet {
  ordered_set<ll> os;
  ll shift;

  void Insert(ll x) {
    os.insert(x - shift);
  }
  void AddAll(ll x) {
    shift += x;
  }
  int CountSmallerThan(ll x) {
    return os.order_of_key(x - shift);
  }
};

struct Testcase {
  vi nums;
  int n;
  int ans = 0;
  vll pref_sum;

  ll GetIntv(int L, int R) {
    return pref_sum[R + 1] - pref_sum[L];
  }

  int GetRes(bool p_left, bool p_right) {
    ll delta = (p_left ? 1 : -1) * nums[0];
    delta += (p_right ? 1 : -1) * nums.back();
    if (n == 2) {
      return (delta > 0);
    }
    debug() << imie(delta);
    int this_ans = 0;
    for (int firstp = 1; firstp <= n - 1; ++firstp) {
      const ll val = delta + GetIntv(firstp, n - 2) - GetIntv(1, firstp - 1);
      debug() << imie(firstp) << imie(val);
      if (val > 0) {
        add_mod(this_ans, 1);
      }
    }
    if (p_left && !p_right) {
      for (int lastp = 1; lastp < n - 2; ++lastp) {
        const ll val = delta + GetIntv(1, lastp) - GetIntv(lastp + 1, n - 2);
        debug() << imie(lastp) << imie(val);
        if (val > 0) {
          add_mod(this_ans, 1);
        }
      }
    }

    int minl = 1, maxr = n - 2;
    if (p_left) { ++minl; }
    if (!p_right) { --maxr; }
    if (maxr <= minl) {
      debug() << "!" << imie(p_left) << imie(p_right) << imie(this_ans);
      debug() << imie(minl) << imie(maxr);
      return this_ans;
    }

    for (int parity : {0, 1}) {
      DynSet ds;
      int startl = n;
      while (startl >= maxr || startl % 2 != parity) { --startl; }
      for (int L = startl; L >= minl; L -= 2) {
        ds.Insert(0);
        ds.AddAll(nums[L + 1]);
        ll bound = delta + GetIntv(L, n - 2) - GetIntv(1, L - 1);
        if (bound % 2 != 0) { ++bound; }
        bound /= 2;
        add_mod(this_ans, ds.CountSmallerThan(bound));
        debug() << imie(parity) << imie(L) << imie(bound) << imie(this_ans);
      }
    }

    debug() << imie(p_left) << imie(p_right) << imie(this_ans);
    return this_ans;
  }

  int Run() {
    cin >> n;
    nums.resize(n);
    for (int &x : nums) { cin >> x; }
    if (n == 1) {
      return 1;
    }
    pref_sum.resize(n + 1);
    for (int i = 0; i < n; ++i) {
      pref_sum[i + 1] = pref_sum[i] + nums[i];
    }
    for (bool L : {false, true}) {
      for (bool R: {false, true}) {
        add_mod(ans, GetRes(L, R));
      }
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int t;
  cin >> t;
  while (t--) {
    cout << Testcase().Run() << "\n";
  }
}