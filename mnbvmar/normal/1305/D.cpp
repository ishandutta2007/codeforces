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

int n;
vi adj[2000];

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vi avail(n);
	iota(ALL(avail), 1);
	while (SZ(avail) > 1) {
		const int k = SZ(avail);
		vi leaves;
		for (int v : avail) {
			if (SZ(adj[v]) == 1) {
				leaves.push_back(v);
			}
		}
		int a = leaves.back();
		int b = leaves[SZ(leaves) - 2];
		cout << "? " << a << " " << b << endl;
		int which;
		cin >> which;

		if (which == a || which == b) {
			cout << "! " << which << endl;
			return 0;
		}

		vi vis;

		function<bool(int,int)> Dfs = [&](int v, int p) {
			if (v == a || v == b) { return false; }
			vis.push_back(v);
			for (int s : adj[v]) {
				if (s == p) { continue; }
				if (!Dfs(s, v)) { return false; }
			}
			return true;
		};

		vi new_adj;
		for (int s : adj[which]) {
			if (Dfs(s, which)) {
				new_adj.push_back(s);
			}
		}

		adj[which] = new_adj;
		vis.clear();
		Dfs(which, which);
		avail = vis;

		debug() << imie(avail);
	}

	assert(!avail.empty());
	cout << "! " << avail[0] << endl;
}