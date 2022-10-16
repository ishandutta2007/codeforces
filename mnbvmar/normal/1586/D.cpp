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
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int n;

int Ask(vi seq) {
	cout << "?";
	for (int x : seq) { cout << " " << x; }
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

int IncAndAsk(int idx) {
	vi seq(n, 1);
	seq[idx - 1] = 2;
	return Ask(seq);
}

int DecAndAsk(int idx) {
	vi seq(n, 2);
	seq[idx - 1] = 1;
	return Ask(seq);
}

int main() {
	cin >> n;
	vector<int> prev_idx(n + 1, -1);
	vector<int> next_idx(n + 1, -1);

	for (int idx = 1; idx <= n; ++idx) {
		const int pi = DecAndAsk(idx);
		if (pi < idx && pi != 0) {
			prev_idx[idx] = pi;
			next_idx[pi] = idx;
		}
		const int ni = IncAndAsk(idx);
		if (ni < idx && ni != 0) {
			next_idx[idx] = ni;
			prev_idx[ni] = idx;
		}
	}

	debug() << imie(prev_idx);
	debug() << imie(next_idx);

	vi ans(n, -1);

	int cur = 1;
	while (prev_idx[cur] != -1) { ++cur; }
	debug() << imie(cur);
	ans[cur - 1] = 1;

	for (int val = 2; val <= n; ++val) {
		cur = next_idx[cur];
		assert(cur != -1);
		ans[cur - 1] = val;
	}

	cout << "!";
	for (int x : ans) { cout << " " << x; }
	cout << endl;

}