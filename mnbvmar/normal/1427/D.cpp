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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;
	vi cur(n);
	for (int &x : cur) { cin >> x; }
	vector<vi> ops;

	auto Apply = [&](vi op) {
		ops.push_back(op);
		debug() << imie(op);
		assert(accumulate(ALL(op), 0) == n);
		assert(count(ALL(op), 0) == 0);
		vector<vi> parts;
		int pos = 0;
		for (int len : op) {
			parts.emplace_back();
			for (int i = 0; i < len; ++i) {
				parts.back().push_back(cur[pos + i]);
			}
			pos += len;
		}
		reverse(ALL(parts));
		cur.clear();
		for (auto &V : parts) for (int x : V) { cur.push_back(x); }
		debug() << imie(cur);
	};

	while (!is_sorted(ALL(cur))) {
		int part_solved = 0;
		while (cur[part_solved] == part_solved + 1 && cur[n - part_solved - 1] == n - part_solved) {
			++part_solved;
		}
		debug() << imie(cur) << imie(part_solved);

		const int a = part_solved + 1;
		const int b = n - part_solved;
		int loc_a = 0, loc_b = 0;
		while (cur[loc_a] != a) { ++loc_a; }
		while (cur[loc_b] != b) { ++loc_b; }

		if (loc_b != part_solved) {
			debug() << 1;
			vi oper;
			for (int i = 0; i < part_solved; ++i) { oper.push_back(1); }
			oper.push_back(loc_b - part_solved);
			oper.push_back(n - loc_b - part_solved);
			for (int i = 0; i < part_solved; ++i) { oper.push_back(1); }
			Apply(oper);
		} else if (part_solved) {
			debug() << 1.5;
			vi oper;
			for (int i = 0; i < part_solved; ++i) { oper.push_back(1); }
			oper.push_back(n - 2 * part_solved);
			for (int i = 0; i < part_solved; ++i) { oper.push_back(1); }
			Apply(oper);
		}

		loc_a = 0;
		while (cur[loc_a] != a) { ++loc_a; }
		{
			debug() << 2;
			vi oper;
			for (int i = 0; i <= part_solved; ++i) { oper.push_back(1); }
			if (loc_a != part_solved + 1) {
				oper.push_back(loc_a - part_solved - 1);
			}
			oper.push_back(n - loc_a - part_solved);
			for (int i = 0; i < part_solved; ++i) { oper.push_back(1); }
			Apply(oper);
		}
		debug() << imie("a");
	}

	cout << SZ(ops) << "\n";
	for (auto &op : ops) {
		cout << SZ(op);
		for (int x : op) { cout << " " << x; }
		cout << "\n";
	}
}