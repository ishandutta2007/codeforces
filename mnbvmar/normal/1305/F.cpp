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

#define int ll

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	srand(time(NULL) * 1298472U);

	int n;
	cin >> n;

	vll elems(n);
	for (auto &x : elems) { cin >> x; }

	set<int> which_checked;
	ll ans = n;

	auto Check = [&](ll g) {
		if (which_checked.insert(g).second) {
			ll cand = 0;
			for (ll num : elems) {
				if (num < g) {
					cand += g - num;
					continue;
				}
				ll r = num % g;
				cand += min(r, g - r);
			}
			debug() << imie(g) << imie(cand);
			ans = min(ans, cand);
		}
	};

	clock_t cur = clock();

	while (clock() - cur < 2 * CLOCKS_PER_SEC) {
	//~ for (int iter = 0; iter < 250; ++iter) {
		int a, b;
		do {
			a = rand() % n;
			b = rand() % n;
		} while (a == b);

		int da = rand() % 5 - 2, db = rand() % 5 - 2;

		const ll ea = elems[a] + da;
		const ll eb = elems[b] + db;
		if (ea <= 0 || eb <= 0) { continue; }

		set<ll> g_seen;
		ll g = gcd(ea, eb);
		if (!g_seen.insert(g).second) { continue; }

		for (int p = 2; (ll)p * p <= g; ++p) {
			if (g % p == 0) {
				while (g % p == 0) { g /= p; }
				Check(p);
			}
		}
		if (g > 1) {
			Check(g);
		}
	}

	cout << ans << "\n";
}