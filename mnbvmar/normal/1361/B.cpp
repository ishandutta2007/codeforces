//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;

//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ using namespace __gnu_pbds;
//~ template <typename T>
//~ using ordered_set =
	//~ tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

#ifdef LOCAL
mt19937 rng(unsigned(69));
#else
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
#define rand rng

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int mod = 1e9 + 7;

int PowMod(int a, int n) {
	int r = 1;
	while (n) {
		if (n & 1) { r = (ll)r * a % mod; }
		n >>= 1;
		a = (ll)a * a % mod;
	}
	return r;
}

void Test() {
	int n, p;
	cin >> n >> p;

	vi exps(n);
	for (int &x : exps) { cin >> x; }

	if (p == 1) {
		cout << (n%2) << "\n";
		return;
	}

	sort(ALL(exps));

	map<int, int> num;

	auto Add = [&](int e) {
		while (++num[e] == p) {
			num.erase(e);
			++e;
		}
	};

	while (!exps.empty()) {
		int v = exps.back();
		int L = SZ(exps) - 2;
		num.clear();
		while (L >= 0) {
			Add(exps[L]);
			if (num[v]) {
				break;
			} else {
				--L;
			}
		}

		if (L == -1) { break; }

		while (SZ(exps) > L) {
			exps.pop_back();
		}
	}

	int ans = 0;
	if (!exps.empty()) {
		ans = PowMod(p, exps.back());
	}
	for (int i = 0; i < SZ(exps) - 1; ++i) {
		ans -= PowMod(p, exps[i]);
		if (ans < 0) { ans += mod; }
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int t;
	cin >> t;
	while (t--) { Test(); }
}