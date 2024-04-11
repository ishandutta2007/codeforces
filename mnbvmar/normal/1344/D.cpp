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
using ld = long double;

int NumAtLeast(int a, ll C) {
	ld delta = 9 - 12 * ld(C + 1 - a);
	if (delta < -1e-9) { return 0; }
	ld xsol = (3 + sqrtl(max<ld>(0, delta))) / 6;
	debug() << imie(a) << imie(C) << imie(delta) << imie(xsol);
	debug() << a - 3*xsol*xsol + 3*xsol - 1;

	int x = max<ll>(0, (ll)xsol - 5);
	while (true) {
		int y = x + 1;
		if (a - 3LL * y * y + 3LL * y - 1 >= C) {
			x = y;
		} else {
			break;
		}
	}
	return x;
}

const int kMaxN = 2e5;
int projs[kMaxN];
int n;

int taken_lo[kMaxN];
int taken_hi[kMaxN];
int taken_cur[kMaxN];

ll SolveProjs(ll C) {
	ll nprojs = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = min(projs[i], NumAtLeast(projs[i], C));
		taken_cur[i] = cnt;
		nprojs += cnt;
	}
	return nprojs;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	ll k;
	
	cin >> n >> k;
	for (int i = 0; i < n; ++i) { cin >> projs[i]; }

	//~ cout << SolveProjs(k) << "\n";
	//~ for (int i = 0; i < n; ++i) {
		//~ cout << taken_cur[i] << " ";
	//~ }
	//~ cout << "\n";
	//~ return 0;

	ll minc = -4e18, maxc = 1e18;
	while (maxc - minc > 1) {
		ll midc = (minc + maxc) / 2;
		int *dest;
		if (SolveProjs(midc) > k) {
			minc = midc;
			dest = taken_hi;
		} else {
			maxc = midc;
			dest = taken_lo;
		}

		for (int i = 0; i < n; ++i) {
			dest[i] = taken_cur[i];
		}
	}

	ll cur_taken = 0;
	for (int i = 0; i < n; ++i) {
		cur_taken += taken_lo[i];
	}
	assert(cur_taken <= k);

	for (int i = 0; i < n; ++i) {
		while (cur_taken < k && taken_lo[i] < taken_hi[i]) {
			++taken_lo[i];
			++cur_taken;
		}
	}

	assert(cur_taken == k);
	for (int i = 0; i < n; ++i) {
		cout << taken_lo[i] << " ";
	}
	cout << "\n";
}