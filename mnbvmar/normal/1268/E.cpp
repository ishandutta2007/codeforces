//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

//~ using namespace __gnu_pbds;
using namespace std;
 
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
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int kMaxN = 7e5;

struct FU {
	vi parent;

	FU(int n) : parent(n) {
		iota(ALL(parent), 0);
	}
	int Find(int v) {
		if (parent[v] == v) { return v; }
		return parent[v] = Find(parent[v]);
	}
	bool Union(int u, int v) {
		u = Find(u); v = Find(v);
		if (u != v) {
			parent[u] = v;
			return true;
		}
		return false;
	}
};

int num_reach[kMaxN];

vector<pii> adj[kMaxN];
int n, m;

vector<pii> tree[kMaxN];
int pre[kMaxN], post[kMaxN], ctm;
pii pnt[kMaxN];

void Dfs(int v, int p) {
	debug() << "Dfs " << imie(v) << imie(p);
	pre[v] = ctm++;
	for (auto &edge : tree[v]) {
		int s = edge.st;
		if (s == p) { continue; }
		pnt[s] = pii(v, edge.nd);
		Dfs(s, v);
	}
	post[v] = ctm;
}

bool Par(int p, int v) {
	return pre[p] <= pre[v] && post[v] <= post[p];
}

vector<pii> Path(int a, int b) {
	debug() << "Path " << imie(a) << imie(b);
	#define pre xxx
	vector<pii> pre, suf;
	while (!Par(a, b) && !Par(b, a)) {
		debug() << imie(a) << imie(b) << imie(pnt[a]);
		pre.push_back(pnt[a]);
		a = pnt[a].st;
	}
	while (!Par(a, b)) {
		pre.push_back(pnt[a]);
		a = pnt[a].st;
	}
	while (!Par(b, a)) {
		suf.push_back(pii(b, pnt[b].nd));
		b = pnt[b].st;
	}
	reverse(ALL(suf));
	for (auto x : suf) pre.push_back(x);
	return pre;
	#undef pre
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m;
	vector<pii> order;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		order.emplace_back(u, v);
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	vector<pii> max_edges, min_edges;
	vector<vector<pii>> paths;

	{
		FU fu_max(n + 2);
		for (auto [a, b] : order) {
			if (!fu_max.Union(a, b)) {
				max_edges.emplace_back(min(a,b), max(a,b));
			}
		}
	}
	reverse(ALL(order));
	{
		FU fu_min(n + 2);
		int idx = 0;
		for (auto [a, b] : order) {
			if (!fu_min.Union(a, b)) {
				min_edges.emplace_back(a, b);
			} else {
				tree[a].emplace_back(b, idx);
				tree[b].emplace_back(a, idx);
			}
			++idx;
		}
	}
	Dfs(1, -1);
	for (int i = 0; i < SZ(min_edges); ++i) {
		paths.push_back(Path(min_edges[i].st, min_edges[i].nd));
	}

	
	//~ reverse(ALL(order));

	debug() << imie(max_edges) << imie(min_edges) << imie(paths);

	for (int i = 1; i <= n; ++i) {
		num_reach[i] = 1;
	}

	map<pii, int> cnts;

	FU fu_add(n + 2);
	int idx = 0;
	for (auto [a, b] : order) {
		debug() << imie(a) << imie(b);
		int x = num_reach[a], y = num_reach[b];
		num_reach[a] += y;
		num_reach[b] += x;
		if (fu_add.Union(a, b)) {
			cnts[pii(a, b)] = x + y;
			cnts[pii(b, a)] = x + y;
		} else {
			debug() << range(num_reach+1, num_reach+n+1) << imie(a) << imie(b);
			auto path = paths[idx];
			debug() << imie(path);

			const int s = SZ(path);
			int num_top = 0;
			int xx = -1, yy = -1;
			for (int i = 0; i < s; ++i) {
				int left = i ? path[i-1].nd : (int)1e9;
				int right = i<s-1 ? path[i+1].nd : (int)1e9;
				if (path[i].nd < left && path[i].nd < right) {
					++num_top;
					xx = path[i].st;
					yy = i ? path[i-1].st : a;
				}
			}

			if (num_top == 1) {
				debug() << imie(xx) << imie(yy);
				num_reach[a] -= cnts[pii(xx, yy)];
				num_reach[b] -= cnts[pii(yy, xx)];
			}
			
			++idx;
		}

		debug() << range(num_reach+1, num_reach+n+1);
	}

	for (int i = 1; i <= n; ++i) {
		cout << num_reach[i]-1 << " ";
	}
	cout << "\n";
}