#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
const ll inf = 1e18;

bool Q = 0;
struct Line {
	mutable ll m, b, x;

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

ll n, dp[MX], sz[MX], res;
vi adj[MX];
Hull h;

void dfs (int u, int p = -1) {
	sz[u] = 1;

	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}

	h.clear();

	for (int v : adj[u])
		if (v != p) {
			res = max(res, h.query(sz[v]) + dp[v] - sz[v] * sz[v]);
			h.add(n - sz[v], sz[v] * (n - sz[v]) + dp[v]);
		}

	for (int v : adj[u])
		if (v != p)
			dp[u] = max(dp[u], sz[v] * (sz[u] - sz[v]) + dp[v]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	if (n == 2) {
		cout << 2 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
		if (adj[i].size() != 1) {
			dfs(i);
			break;
		}

	cout << 1ll * n * (n - 1) / 2 + res << endl;

	return 0;
}