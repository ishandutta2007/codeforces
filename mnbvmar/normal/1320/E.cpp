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

const int kMaxN = 3e5 + 100;
const int kLogMaxN = 19;

int n, q;

vi adj[kMaxN];
int pnt[kMaxN][kLogMaxN];
int preorder[kMaxN], postorder[kMaxN];
int depth[kMaxN];
int curtm;

void Dfs(int v, int p) {
	preorder[v] = curtm++;
	pnt[v][0] = p;
	for (int i = 1; i < kLogMaxN; ++i) {
		pnt[v][i] = pnt[pnt[v][i-1]][i-1];
	}

	for (int s : adj[v]) {
		if (s == p) { continue; }
		depth[s] = depth[v] + 1;
		Dfs(s, v);
	}
	postorder[v] = curtm;
}

inline bool IsAbove(int top, int bot) {
	return preorder[top] <= preorder[bot] && postorder[bot] <= postorder[top];
}

int Lca(int u, int v) {
	if (depth[u] > depth[v]) { swap(u, v); }
	const int diff = depth[v] - depth[u];
	for (int i = 0; i < kLogMaxN; ++i) {
		if ((diff >> i) & 1) {
			v = pnt[v][i];
		}
	}

	if (u == v) { return u; }
	for (int i = kLogMaxN - 1; i >= 0; --i) {
		const int pv = pnt[v][i], pu = pnt[u][i];
		if (pv != pu) {
			v=  pv; u = pu;
		}
	}
	return pnt[v][0];
}

map<int, vector<pii>> new_adj;

void Query() {
	vi epoints;

	int k, m;
	cin >> k >> m;

	vector<pii> virus(k);
	for (auto &[a,b] : virus) {
		cin >> a >> b;
		epoints.push_back(a);
	}

	vi que(m);
	for (int &x : que) {
		cin >> x;
		epoints.push_back(x);
	}

	sort(ALL(epoints), [&](int lhs, int rhs) {
			return preorder[lhs] < preorder[rhs];
		});
	epoints.resize(unique(ALL(epoints)) - epoints.begin());
	debug() << imie(epoints);

	const int s_init = SZ(epoints);

	for (int i = 0; i < s_init - 1; ++i) {
		const int a = epoints[i];
		const int b = epoints[i + 1];
		epoints.push_back(Lca(a, b));
	}

	sort(ALL(epoints), [&](int lhs, int rhs) {
			return preorder[lhs] < preorder[rhs];
		});
	epoints.resize(unique(ALL(epoints)) - epoints.begin());
	debug() << imie(epoints);
	const int s_full = SZ(epoints);

	new_adj.clear();

	vi stk{epoints[0]};
	for (int i = 1; i < s_full; ++i) {
		while (!IsAbove(stk.back(), epoints[i])) {
			stk.pop_back();
		}
		const int p = stk.back();
		const int v = epoints[i];
		const int d = depth[v] - depth[p];

		debug() << imie(p) << imie(v) << imie(d);

		new_adj[p].emplace_back(v, d);
		new_adj[v].emplace_back(p, d);
		stk.push_back(epoints[i]);
	}

	set<tuple<ll, int, int, int>> Q;

	map<int, int> owned_by;
	for (int i = 0; i < SZ(virus); ++i) {
		auto [where, rad] = virus[i];
		//~ owned_by[where] = i + 1;
		Q.emplace(i, where, 0, i + 1);
	}

	while (!Q.empty()) {
		const auto [dist, v, remrad, vir] = *Q.begin();
		Q.erase(Q.begin());
		if (!owned_by.emplace(v, vir).second) { continue; }

		for (auto [s, len] : new_adj[v]) {
			if (len <= remrad) {
				Q.emplace(dist, s, remrad - len, vir);
			} else {
				const int rad = virus[vir-1].nd;
				const int need = (len - remrad + rad - 1) / rad;
				const int newrem = remrad - len + (ll)need * rad;
				assert(0 <= newrem && newrem < rad);
				const ll ndist = dist + (ll)need * k;
				Q.emplace(ndist, s, newrem, vir);
			}
		}
	}

	for (int v : que) {
		cout << owned_by[v] << " ";
	}
	cout << "\n";
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
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	Dfs(1, 1);

	cin >> q;
	for (int i = 0; i < q; ++i) {
		Query();
	}
}