#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 150005;
const ll inf = 2e18;

bool Q = 0;
struct Line {
	mutable ll m, b, x;

	// Maximo: m < ot.m
	// Minimo: m > ot.m
	bool operator < (const Line ot) const {
		return Q ? x < ot.x : m < ot.m;
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
	bool valid (auto it) {
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
		it->x = x, sig->x = y;
		return 1;
	}

	void add (ll m, ll b) {
		auto it = lower_bound({m, b, -inf});

		if (it != end() && it->m == m) {
			//Maximo: it->b > b
			//Minimo: it->b < b
			if (it->b > b) return;
			it->b = b;
		} else {
			it = insert({m, b, -inf});
		}

		if (!valid(it)) {
			erase(it);
			return;
		}

		auto ant = it;
		while (ant != begin()) {
			if (valid(--ant)) break;
			erase(ant);
			if (it == begin()) { it->x = -inf; break; }
			ant = it;
		}

		auto sig = it;
		sig++;
		while (sig != end() && !valid(sig))
			erase(sig++);
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

int n, sz[MX];
ll a[MX];
vi adj[MX];
ll res;
Hull st;
bitset<MX> ex;

void pre (int u, int p = -1) {
	sz[u] = 1;

	for (int v : adj[u])
		if (v != p) {
			pre(v, u);
			sz[u] += sz[v];
		}
}

void go (int u, int lvl, ll s, ll acu, int p = -1) {
	s += a[u];
	acu += lvl * a[u];
	res = max(res, st.query(s) + acu);
	res = max(res, acu);

	for (int v : adj[u])
		if (!ex[v] && v != p)
			go(v, lvl + 1, s, acu, u);
}

void add (int u, int lvl, ll s, ll acu, int p = -1) {
	s += a[u];
	acu += s;

	res = max(res, acu);
	st.add(lvl, acu);

	for (int v : adj[u])
		if (!ex[v] && v != p)
			add(v, lvl + 1, s, acu, u);
}

void dfs (int u) {
	int tam = 1;

	for (int v : adj[u])
		if (!ex[v])
			tam += sz[v];

	while (1) {
		int ind = -1;

		for (int v : adj[u])
			if (!ex[v] && 2 * sz[v] > tam)
				ind = v;

		if (ind == -1)
			break;

		sz[u] = tam - sz[ind];
		u = ind;
	}

    ex[u] = 1;

	st.clear();
	st.add(1, a[u]);
	for (int v : adj[u])
		if (!ex[v]) {
			go(v, 1, 0, 0);
			add(v, 2, a[u], a[u]);
		}

	reverse(all(adj[u]));

	st.clear();
	st.add(1, a[u]);
	for (int v : adj[u])
		if (!ex[v]) {
			go(v, 1, 0, 0);
			add(v, 2, a[u], a[u]);
		}

	for (int v : adj[u])
		if (!ex[v])
			dfs(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		res = max(res, 1ll * a[i]);
	}

	pre(1);
	dfs(1);

	cout << res << endl;

	return 0;
}