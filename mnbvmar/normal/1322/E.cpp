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

struct IntvMax {
	vector<vi> data;
	int n, lg;

	IntvMax(const vi &what) {
		debug() << imie(what);
		n = SZ(what);
		lg = 1;
		while ((1 << lg) < n) { ++lg; }
		n = (1 << lg);
		data = vector<vi>(lg + 1, vi(n, -1e9));

		for (int i = 0; i < SZ(what); ++i) {
			data[0][i] = what[i];
		}

		for (int lvl = 1; lvl <= lg; ++lvl) {
			data[lvl] = data[lvl - 1];
			const int jump = (1 << (lvl-1));
			for (int i = 0; i + jump < n; ++i) {
				data[lvl][i] = max(data[lvl-1][i], data[lvl-1][i + jump]);
			}
		}

		debug() << imie(data);
	}

	int GetMax(int L, int R) {
		L = max(L, 0);
		R = min(R, n - 1);
		assert(L <= R);

		int len = R - L + 1;
		int lvl = 31 - __builtin_clz(len);
		debug() << imie(lvl) << imie(data[lvl]);
		return max(data[lvl][L], data[lvl][R - (1 << lvl) + 1]);
	}
};

int n;
vi h;

int Median(int a, int b, int c) {
	return a ^ b ^ c ^ min({a,b,c}) ^ max({a,b,c});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;
	h.resize(n);
	for (int &x : h) { cin >> x; }

	vi h_even, h_odd;
	for (int i = 0; i < n; ++i) {
		(i % 2 == 0 ? h_even : h_odd).push_back(h[i]);
	}

	IntvMax max_even(h_even), max_odd(h_odd);
	for (int &x : h_even) { x = -x; }
	for (int &x : h_odd) { x = -x; }
	IntvMax min_even(h_even), min_odd(h_odd);

	auto GetEx = [&](int L, int R, bool max) {
		debug() << imie(L) << imie(R) << imie(max);
		if (L < 0) {
			L = (L % 2 == 0) ? 0 : 1;
		}
		if (R >= n) {
			if (R % 2 == n % 2) {
				R = n;
			} else {
				R = n - 1;
			}
		}

		assert(L % 2 == R % 2);
		if (L % 2 == 0) {
			if (max) {
				return max_even.GetMax(L/2, R/2);
			} else {
				return -min_even.GetMax(L/2, R/2);
			}
		} else {
			if (max) {
				return max_odd.GetMax(L/2, R/2);
			} else {
				return -min_odd.GetMax(L/2, R/2);
			}
		}
	};

	vi lasth(n);
	vi ans(n);

	for (int i = 0; i < n; ++i) {
		if (i == 0 || i == n - 1) {
			lasth[i] = h[i];
			continue;
		}

		if (Median(h[i-1], h[i], h[i+1]) == h[i]) {
			lasth[i] = h[i];
			continue;
		}

		bool small = (h[i] < h[i-1] && h[i] < h[i+1]);

		debug() << imie(i);

		auto Can = [&](int steps) {
			int radl = steps / 2;
			int radr = (steps + 1) / 2;

			if (small) {
				return GetEx(i - 2 * radl, i + 2 * radl, true) <
				       GetEx(i - 2 * radr + 1, i + 2 * radr - 1, false);
			} else {
				int a = GetEx(i - 2 * radl, i + 2 * radl, false);
				int b = GetEx(i - 2 * radr + 1, i + 2 * radr - 1, true);
				debug() << imie(steps) << imie(a) << imie(b);
				return a > b;
			}
		};

		int L = ans[i - 1];
		if (Can(L + 1)) {
			++L;
		} else if (!Can(L)) {
			--L;
		}

		L = min(L, i);
		L = min(L, (n-1)-i);
		ans[i] = L;

		int A = i - L;
		int B = i + L;
		bool mx = small ^ (L % 2 == 1);

		debug() << imie(A) << imie(B) << imie(mx) << " !!!!";

		lasth[i] = GetEx(A, B, mx);
	}

	debug() << imie(ans);

	cout << *max_element(ALL(ans)) << "\n";
	for (int x : lasth) { cout << x << " "; }
	cout << "\n";
}