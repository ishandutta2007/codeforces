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

const int mod = 998244353;

int n, m;
int mul = 1;

inline void Add(int &x, int y) {
	x += y;
	if (x >= mod) { x -= mod; }
}

vi SolveDp(int rsize, vll basis) {
	debug() << imie(rsize) << imie(basis);
	vector<vi> dp[2];
	int tsz = SZ(basis);
	for (int i = 0; i < 2; ++i) {
		dp[i].resize(tsz + 1, vi(1 << rsize));
	}
	dp[0][0][0] = 1;

	for (int i = 0; i < SZ(basis); ++i) {
		int from = i % 2;
		int to = (i + 1) % 2;
		for (int row = 0; row <= tsz; ++row) {
			fill(ALL(dp[to][row]), 0);
		}

		for (int cnt = 0; cnt <= i; ++cnt) {
			for (int mask = 0; mask < (1 << rsize); ++mask) {
				int src = dp[from][cnt][mask];
				if (!src) { continue; }
				Add(dp[to][cnt][mask], src);
				Add(dp[to][cnt + 1][mask ^ basis[i]], src);
			}
		}
	}

	vi ans(m + 1);
	int last = SZ(basis) % 2;
	for (int cnt = 0; cnt <= tsz; ++cnt) {
		for (int mask = 0; mask < (1 << rsize); ++mask) {
			Add(ans[cnt + __builtin_popcountll(mask)], dp[last][cnt][mask]);
		}
	}

	return ans;
}

vi SolveBrute(int, vll basis) {
	vi ans(m + 1);
	int tsz = SZ(basis);
	for (int mask = 0; mask < (1 << tsz); ++mask) {
		ll rem = 0;
		for (int i = 0; i < tsz; ++i) {
			if ((mask >> i) & 1) {
				rem ^= basis[i];
			}
		}

		++ans[__builtin_popcountll(mask) + __builtin_popcountll(rem)];
	}
	return ans;
}

void Out(vi ans) {
	for (int val : ans) {
		cout << ((ll)val * mul) % mod << " " ;
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m;

	vll basis(m, -1);

	for (int i = 0; i < n; ++i) {
		ll val;
		cin >> val;

		for (int b = 0; b < m; ++b) {
			if (basis[b] != -1 && ((val >> b) & 1)) {
				val ^= basis[b];
			}
		}

		if (!val) {
			mul = (mul * 2) % mod;
		} else {
			int bit = 0;
			while (!((val >> bit) & 1)) { ++bit; }
			assert(basis[bit] == -1);

			for (int j = 0; j < m; ++j) {
				if (basis[j] != -1 && (basis[j] >> bit) & 1) {
					basis[j] ^= val;
				}
			}
			basis[bit] = val;
		}

		debug() << imie(i) << imie(basis);
	}

	vi nonbits;
	for (int i = 0; i < m; ++i) {
		if (basis[i] == -1) {
			nonbits.push_back(i);
		}
	}

	int rsize = SZ(nonbits);
	vll comp_basis;
	for (int i = 0; i < m; ++i) {
		if (basis[i] != -1) {
			ll new_val = 0;
			for (int j = 0; j < SZ(nonbits); ++j) {
				int b = nonbits[j];
				new_val |= (((basis[i] >> b) & 1) << j);
			}
			comp_basis.push_back(new_val);
		}
	}

	debug() << imie(rsize) << imie(comp_basis);

	if (rsize <= 16) {
		Out(SolveDp(rsize, comp_basis));
	} else {
		Out(SolveBrute(rsize, comp_basis));
	}
}