#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef long double f80;

constexpr int const maxn = 150001;
int s[maxn], t[maxn], ban[maxn];
i64 a[maxn], cal[maxn], ans;
vector<int> adj[maxn], con;
vector<i64> dp[maxn];

struct line {
	static constexpr i64 const query_b = -1LL;
	i64 k, b;
	mutable function<line const*()> next;
	line(i64 _k = 0, i64 _b = query_b): k(_k), b(_b), next() { }
	i64 at(i64 x) const { return k * x + b; }
};

bool operator==(line const& lhs, line const& rhs) { return lhs.k == rhs.k && lhs.b == rhs.b; }

bool operator<(line const& lhs, line const& rhs) {
	if (rhs.b != line::query_b) return lhs.k < rhs.k;
	line const* ptr = lhs.next();
	return ptr != nullptr && f80(lhs.b - ptr->b) < f80(ptr->k - lhs.k) * rhs.k;
}

struct dynamic_hull : public multiset<line> {
	bool check(iterator iter) {
		iterator nxt = next(iter);
		if (iter == begin()) return nxt == end() || *iter == *nxt;
		iterator pre = prev(iter);
		return nxt == end() ? iter->k != pre->k || iter->b > pre->b : f80(pre->b - iter->b) * (nxt->k - iter->k) < f80(iter-> b - nxt->b) * (iter->k - pre->k);
	}
	void add(i64 k, i64 b) {
		iterator iter = emplace(k, b);
		iter->next = [=] () -> line const* { return next(iter) == end() ? nullptr : &*next(iter); };
		if (!check(iter)) { erase(iter); return; }
		while (next(iter) != end() && !check(next(iter))) erase(next(iter));
		while (iter != begin() && !check(prev(iter))) erase(prev(iter));
	}
	i64 at(i64 x) { return lower_bound(line(x))->at(x); }
};

void dfs(int u) {
	con.push_back(u);
	s[u] = 1;
	t[u] = 0;
	ban[u] = 1;
	for (int v : adj[u]) if (!ban[v]) {
		dfs(v);
		s[u] += s[v];
		t[u] = max(t[u], s[v]);
	}
	ban[u] = 0;
}

dynamic_hull hull;

void search(int u, int d, i64 x, i64 y) {
	++d;
	y += a[u];
	x += y;
	hull.add(d, x);
	ban[u] = 1;
	for (int v : adj[u]) if (!ban[v]) search(v, d, x, y);
	ban[u] = 0;
}

void update(int u, int d, i64 x, i64 y) {
	x += ++d * a[u];
	y += a[u];
	ans = max(ans, x + hull.at(y));
	ban[u] = 1;
	for (int v : adj[u]) if (!ban[v]) update(v, d, x, y);
	ban[u] = 0;
}

void solve(int o) {
	con.resize(0);
	dfs(o);
	o = *min_element(con.begin(), con.end(), [&] (int x, int y) -> bool { return max(s[o] - s[x], t[x]) < max(s[o] - s[y], t[y]); });
	ban[o] = 1;
	for (int _ = 0; _ != 2; ++_) {
		reverse(adj[o].begin(), adj[o].end());
		hull.clear();
		hull.add(1, a[o]);
		for (int u : adj[o]) if (!ban[u]) {
			update(u, 0, 0, 0);
			search(u, 1, a[o], a[o]);
		}
	}
	ans = max(ans, hull.at(0));
	for (int u : adj[o]) if (!ban[u]) solve(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i != n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) cin >> a[i];
	solve(1);
	cout << ans << endl;
}