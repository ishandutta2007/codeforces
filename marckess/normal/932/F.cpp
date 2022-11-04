#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
const ll inf = 1e18;

bool Q = 0;
struct Line {
	mutable ll m, b, x;

	bool operator < (const Line ot) const {
		return Q ? x < ot.x : m > ot.m;
	}
};

ll ceil (ll a, ll b) {
	if (a < 0 != b < 0) return a / b;
	return (abs(a) + abs(b) - 1) / abs(b);
}

ll intersection (const Line &p, const Line &q) {
	return ceil(q.b - p.b, p.m - q.m);
}

struct Hull : multiset<Line> {
	bool valid (iterator it) {
		if (it == begin()) {
			auto sig = it;
			sig++;
			if (sig != end()) sig->x = intersection(*it, *sig);
			return it->x = -inf;
		}

		auto ant = it, sig = it;
		ant--, sig++;

		if (sig == end()) {
			it->x = intersection(*it, *ant);
			return 1;
		}

		ll x = intersection(*it, *ant);
		ll y = intersection(*it, *sig);

		if (x > y) return 0;
		it->x = x;
		sig->x = y;
		return 1;
	}

	void add (ll m, ll b) {
		auto it = lower_bound({m, b, -inf});

		if (it != end() && it->m == m) {
			if (it->b < b) return;
			it->b = b;
		} else {
			it = insert({m, b, -inf});
		}

		if (!valid(it)) {
			erase(it);
			return;
		}

		if (it != begin()) {
			auto ant = it;
			ant--;
			while (!valid(ant)) {
				erase(ant);
				if (it == begin()) {it->x = -inf; break;}
				ant = it;
				ant--;
			}
		}

		auto sig = it;
		sig++;
		while (sig != end() && !valid(sig)) {
			erase(sig);
			sig = it;
			sig++;
		}
	}

	ll query (ll x) {
		if (empty()) return 0;

		Q = 1;
		auto it = upper_bound({0, 0, x});
		it--;
		Q = 0;
		return x * it->m + it->b;
	}
};

int n, u, v;
ll a[MX], b[MX], res[MX];
vi adj[MX];
Hull h[MX];

void dfs (int u, int p) {
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			if (h[u].size() < h[v].size()) swap(h[u], h[v]);
			for (auto it : h[v]) h[u].add(it.m, it.b);
		}

	res[u] = h[u].query(a[u]);
	h[u].add(b[u], res[u]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FORR(i,1,n) cin >> a[i];
	FORR(i,1,n) cin >> b[i];
	FOR(i,n-1) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 1);

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}