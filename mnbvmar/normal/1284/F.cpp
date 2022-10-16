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

const int kMaxN = 900 * 1000;

vector<pii> st_adj[kMaxN];
vector<pii> nd_adj[kMaxN];
pii st_edges[kMaxN];
pii nd_edges[kMaxN];
int st_size[kMaxN];
int id_mapping[kMaxN];

int edge_matching[kMaxN];

int n;
int curv;

vi component;

void DfsSize(int v, int p) {
	st_size[v] = 1;
	component.push_back(v);

	for (auto &edge : st_adj[v]) {
		if (edge.st == p) { continue; }
		DfsSize(edge.st, v);
		st_size[v] += st_size[edge.st];
	}
}

void ExploreSubtree(int v, int p, int cnt) {
	id_mapping[v] = cnt;
	for (auto &edge : st_adj[v]) {
		if (edge.st == p) { continue; }
		ExploreSubtree(edge.st, v, cnt);
	}
}

int centr;

void MatchEdges(int v, int p, pii &pnt_edge) {
	int rewrite = -1;
	if (id_mapping[v] != id_mapping[p] && v != centr && p != centr) {
		pnt_edge.st = -1;
		rewrite = centr;
	}

	for (auto &edge : nd_adj[v]) {
		if (edge.st == p) {
			if (rewrite != -1) { edge.st = centr; }
			continue;
		}
		MatchEdges(edge.st, v, edge);
	}

	vector<pii> new_nd_adj;
	swap(new_nd_adj, nd_adj[v]);
	for (auto [a, b] : new_nd_adj) {
		if (a != -1) {
			nd_adj[v].emplace_back(a, b);
		}
	}
}

void RunCentroid(int root) {
	component.clear();
	DfsSize(root, -1);
	if (SZ(component) == 1) { return; }
	debug() << imie(root) << imie(component);
	#ifdef LOCAL
	for (int v : component) {
		debug() << imie(v) << imie(nd_adj[v]);
	}
	#endif
	if (SZ(component) == 2) {
		int st_id = st_adj[root][0].nd;
		int nd_id = nd_adj[root][0].nd;
		assert(edge_matching[st_id] == -1);
		edge_matching[st_id] = nd_id;
		return;
	}
	
	centr = root;
	for (int v : component) {
		if (st_size[v] * 2 >= st_size[root] && st_size[v] < st_size[centr]) {
			centr = v;
		}
	}

	int cnt = 0;
	for (auto &edge : st_adj[centr]) {
		ExploreSubtree(edge.st, centr, cnt);
		++cnt;
	}

	debug() << imie(root) << imie(centr) << imie(cnt) << imie(st_size[root])
		<< imie(component);

	id_mapping[centr] = 0;
	vector<vi> subtrees(cnt);
	for (int v : component) {
		subtrees[id_mapping[v]].push_back(v);
	}

	for (auto &edge : nd_adj[centr]) {
		MatchEdges(edge.st, centr, edge);
	}

	#ifdef LOCAL
	for (int v : component) {
		debug() << imie(v) << imie(nd_adj[v]);
	}
	#endif

	const int copy_base = curv + 1;
	for (int v : component) {
		if (v == centr) { continue; }
		for (auto &edge : st_adj[v]) {
			if (edge.st == centr) {
				const int ns = copy_base + id_mapping[v];
				edge.st = ns;
				st_adj[ns].emplace_back(v, edge.nd);
			}
		}
		for (auto &edge : nd_adj[v]) {
			if (edge.st == centr) {
				const int ns = copy_base + id_mapping[v];
				edge.st = ns;
				nd_adj[ns].emplace_back(v, edge.nd);
			}
		}
	}

	curv += cnt;
	for (int v = 0; v < cnt; ++v) {
		RunCentroid(copy_base + v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		st_edges[i] = pii(u, v);
		st_adj[u].emplace_back(v, i);
		st_adj[v].emplace_back(u, i);
		edge_matching[i] = -1;
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		nd_edges[i] = pii(u, v);
		nd_adj[u].emplace_back(v, i);
		nd_adj[v].emplace_back(u, i);
	}
	
	curv = n;
	RunCentroid(1);
	debug() << range(edge_matching, edge_matching + n - 1);

	cout << n - 1 << "\n";
	for (int i = 0; i < n - 1; ++i) {
		assert(edge_matching[i] != -1);
		const int e = edge_matching[i];
		cout << st_edges[i].st << " " << st_edges[i].nd << " ";
		cout << nd_edges[e].st << " " << nd_edges[e].nd << "\n";
	}
}