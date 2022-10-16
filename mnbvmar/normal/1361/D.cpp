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
using ld=long double;

int n, k;

ld GetIntv(const vector<ld> &P, int L, int R) {
	if (L > R) { return 0; }
	return P[R + 1] - P[L];
}

vector<ld> SolveAllK(vector<ld> dists) {
	sort(ALL(dists));
	const int S = SZ(dists);

	vector<ld> dists_pref(S + 1), dists_pref_w(S + 1);
	for (int i = 0; i < S; ++i) {
		dists_pref[i + 1] = dists_pref[i] + dists[i];
		dists_pref_w[i + 1] = dists_pref_w[i] + i * dists[i];
	}

	vector<ld> ans(S + 1);

	for (int take = 1; take <= S; ++take) {
		const int rem = k - take;
		const int min_weight = -(take - 1) + rem;
		const int num_left = max(0, (-min_weight + 1) / 2);
		const int num_right = take - num_left;
		assert(num_right >= 0);

		ld sum = 0;
		if (num_left) {
			sum += min_weight * GetIntv(dists_pref, 0, num_left - 1);
			sum += 2 * GetIntv(dists_pref_w, 0, num_left - 1);
		}
		if (num_right) {
			const int first_take = S - num_right;
			const int firstw = min_weight + 2 * num_left;
			sum += (firstw - 2 * first_take) * GetIntv(dists_pref, first_take, S - 1);
			sum += 2 * GetIntv(dists_pref_w, first_take, S - 1);
		}

		ans[take] = sum;
	}

	return ans;
}

struct Point {
	int x, y;
	pii GetLine() const {
		assert(x || y);
		int g = gcd(abs(x), abs(y));
		return {x / g, y / g};
	}
	ld Norm() const {
		return sqrtl(ll(x) * x + ll(y) * y);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> k;

	map<pii, vector<ld>> dist_set;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (!x && !y) { continue; }
		Point p{x, y};
		dist_set[p.GetLine()].push_back(p.Norm());
	}

	vector<ld> S;
	for (auto &rays : dist_set) {
		auto res = SolveAllK(rays.nd);
		debug() << imie(rays.st) << imie(res);
		const int sz = SZ(res);
		for (int i = 1; i < sz; ++i) {
			S.push_back(res[i] - res[i - 1]);
		}
	}

	sort(ALL(S), greater<ld>());

	vector<ld> pref_ans{0};
	for (ld x : S) {
		pref_ans.push_back(pref_ans.back() + x);
	}

	cout << max(pref_ans[k - 1], pref_ans[k]) << "\n";

	//~ int S;
	//~ cin >> n >> S;
	//~ vector<ld> vals(S);
	//~ for (ld &x : vals) { cin >> x; }

	//~ debug() << imie(SolveAllK(vals));
}