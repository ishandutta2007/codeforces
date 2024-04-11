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

const int kMaxN = 4e5;

vi adj[kMaxN];
vector<pii> ques;

bool visited[kMaxN];
int depth[kMaxN];
int parent[kMaxN];

void Dfs(int v) {
	visited[v] = true;
	for (int s : adj[v]) {
		if (visited[s]) { continue; }
		depth[s] = depth[v] + 1;
		parent[s] = v;
		Dfs(s);
	}
}

vi FindPath(int a, int b) {
	if (depth[a] > depth[b]) { swap(a, b); }
	vi ans_a{a}, ans_b{b};
	while (depth[b] > depth[a]) {
		b = parent[b];
		ans_b.push_back(b);
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
		ans_a.push_back(a);
		ans_b.push_back(b);
	}
	ans_a.pop_back();
	reverse(ALL(ans_b));
	for (int x : ans_b) { ans_a.push_back(x); }
	return ans_a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	Dfs(1);

	int q;
	cin >> q;
	ques.resize(q);

	vector<int> degs(n + 1);

	for (auto &[a, b] : ques) {
		cin >> a >> b;
		++degs[a];
		++degs[b];
	}

	int cnt_odd = 0;
	for (int i = 1; i <= n; ++i) {
		if (degs[i] % 2 == 1) {
			++cnt_odd;
		}
	}
	if (cnt_odd > 0) {
		cout << "NO\n";
		assert(cnt_odd % 2 == 0);
		cout << cnt_odd / 2 << "\n";
		return 0;
	}

	cout << "YES\n";
	for (auto [a, b] : ques) {
		vi path = FindPath(a, b);
		if (path[0] != a) { reverse(ALL(path)); }
		assert(path[0] == a);
		assert(path.back() == b);
		cout << SZ(path) << "\n";
		for (int x : path) { cout << x << " "; }
		cout << "\n";
	}
}