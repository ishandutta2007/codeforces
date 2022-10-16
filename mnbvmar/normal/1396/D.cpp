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

inline int add(int a, int b) {
	a += b;
	if (a >= mod) { a -= mod; }
	return a;
}

inline int sub(int a, int b) {
	a -= b;
	if (a < 0) { a += mod; }
	return a;
}

inline int mul(int a, int b) {
	return ll(a) * b % mod;
}

int N, K, X;

struct IntvCounter {
	vector<int> colors, locations;
	int sum;
	set<pii> min_intvs;
	vector<set<int>> color_locs;

	void DelIntv(int L, int R) {
		auto iter = min_intvs.find(pii(L, R));
		assert(iter != min_intvs.end());
		const int delta = locations[L] - locations[prev(iter)->first];
		if (next(iter) != min_intvs.end()) {
			sum = add(sum, mul(delta, X - locations[next(iter)->second]));
		}
		sum = sub(sum, mul(delta, X - locations[R]));
		min_intvs.erase(iter);
	}

	void AddIntv(int L, int R) {
		if (R >= SZ(colors)) { return; }
		auto [iter, succ] = min_intvs.emplace(L, R);
		if (!succ) { return; }
		auto piter = prev(iter);
		if (piter->first == L) {
			min_intvs.erase(iter);
			return;
		} else if (next(iter) != min_intvs.end() && next(iter)->second <= R) {
			min_intvs.erase(iter);
			return;
		}

		const int delta = locations[L] - locations[piter->first];

		if (next(iter) != min_intvs.end()) {
			sum = sub(sum, mul(delta, X - locations[next(iter)->second]));
		}
		sum = add(sum, mul(delta, X - locations[R]));
	}

	IntvCounter(const vi &cols, const vi &locs) : colors(cols), locations(locs) {
		min_intvs.emplace(0, 0);
		colors.insert(colors.begin(), -1);
		locations.insert(locations.begin(), -1);
		debug() << "IntvCounter" << imie(colors) << imie(locations);
		sum = 0;

		const int M = SZ(colors);
		int lft = 1, rgt = 0;
		map<int, int> mp;
		vector<pii> add_intvs;
		while (lft <= M - 1) {
			while (rgt < M - 1 && SZ(mp) < K) {
				++rgt;
				++mp[colors[rgt]];
			}
			if (rgt == M - 1 && SZ(mp) < K) { break; }
			while (!add_intvs.empty() && add_intvs.back().second == rgt) {
				add_intvs.pop_back();
			}
			add_intvs.emplace_back(lft, rgt);
			if (--mp[colors[lft]] == 0) {
				mp.erase(colors[lft]);
			}
			++lft;
		}

		for (auto &intv : add_intvs) {
			AddIntv(intv.first, intv.second);
		}

		color_locs.resize(K + 1);
		for (int i = 1; i < M; ++i) {
			color_locs[colors[i]].insert(i);
		}

		debug() << imie(min_intvs) << imie(sum);
	}

	void DelItem(int loc) {
		++loc;
		const int col = colors[loc];
		debug() << imie(loc) << imie(col);
		auto &CL = color_locs[col];
		auto iter = CL.find(loc);
		assert(iter != CL.end());

		bool is_ok = iter != CL.begin();

		int from_where = iter == CL.begin() ? 1 : *prev(iter) + 1;
		int to_where = next(iter) == CL.end() ? SZ(colors) + 5 : *next(iter);
		CL.erase(iter);

		auto intv_iter = min_intvs.lower_bound(make_pair(from_where, -1));
		vector<pii> to_erase;
		while (intv_iter != min_intvs.end() && intv_iter->first <= loc) {
			if (intv_iter->second >= to_where) { break; }
			to_erase.push_back(*intv_iter);
			++intv_iter;
		}
		if (to_erase.empty()) { return; }
		for (auto &elem : to_erase) {
			DelIntv(elem.first, elem.second);
		}
		if (is_ok) {
			AddIntv(from_where - 1, to_erase[0].second);
		}
		AddIntv(to_erase.back().first, to_where);
		debug() << imie(min_intvs) << imie(sum);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> N >> K >> X;

	vector<tuple<int, int, int>> items(N);
	for (auto &[x, y, c] : items) {
		cin >> x >> y >> c;
	}
	sort(ALL(items));
	for (auto &[x, y, c] : items) {
		debug() << imie(x) << imie(y) << imie(c);
	}

	int ans = 0;

	for (int i = 0; i < N; ++i) {
		const int diff_left = get<0>(items[i]) - (i == 0 ? -1 : get<0>(items[i-1]));
		
		vector<pii> small_items(N);
		for (int j = 0; j < N; ++j) {
			small_items[j] = pii(get<1>(items[j]), get<2>(items[j]));
		}
		debug() << imie(small_items);
		const int S = N - i;
		vector<int> order(S);
		iota(ALL(order), i);
		sort(ALL(order), [&](int lhs, int rhs) {
			return small_items[lhs] < small_items[rhs];
		});
		debug() << imie(order);

		vector<int> in_order(N, -1);
		for (int j = 0; j < S; ++j) {
			in_order[order[j]] = j;
		}

		debug() << imie(i) << imie(in_order);

		vi locs, cols;
		for (int idx : order) {
			locs.push_back(small_items[idx].first);
			cols.push_back(small_items[idx].second);
		}

		IntvCounter intv_counter(cols, locs);

		for (int j = N - 1; j >= i; --j) {
			const int diff_right = (j==N-1 ? X-1 : get<0>(items[j+1])-1) - get<0>(items[j]);
			debug() << imie(diff_left) << imie(diff_right) << imie(intv_counter.sum);
			ans = add(ans, mul(diff_left, mul(diff_right + 1, intv_counter.sum)));
			const int where = in_order[j];
			assert(where >= 0);
			intv_counter.DelItem(where);
		}
	}
	cout << ans << "\n";
}