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

const int kMaxN = 3e5;

int n, m;
vector<pii> edges;
vi adj[kMaxN];
int min_in[kMaxN];
int min_out[kMaxN];
bool vis[kMaxN];
vi order;
int in_order[kMaxN];

void Dfs(int v) {
	vis[v] = true;
	for (int s : adj[v]) {
		if (!vis[s]) {
			Dfs(s);
		}
	}
	order.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		edges.emplace_back(u, v);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			Dfs(i);
		}
	}

	reverse(ALL(order));
	for (int i = 0; i < n; ++i) {
		in_order[order[i]] = i;
	}

	for (auto [u, v] : edges) {
		if (in_order[u] > in_order[v]) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 1; i <= n; ++i) {
		min_in[i] = min_out[i] = i;
	}

	for (int v : order) {
		for (int s : adj[v]) {
			min_in[s] = min(min_in[s], min_in[v]);
		}
	}

	reverse(ALL(order));
	for (int v : order) {
		for (int s : adj[v]) {
			min_out[v] = min(min_out[v], min_out[s]);
		}
	}

	string ans(n, 'E');
	int cntans = 0;

	for (int i = 1; i <= n; ++i) {
		if (min_in[i] == i && min_out[i] == i) {
			ans[i - 1] = 'A';
			++cntans;
		}
	}

	cout << cntans << "\n";
	cout << ans << "\n";
}