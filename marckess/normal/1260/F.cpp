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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;
int n;
ll l[MX], r[MX], sz[MX], inv[MX], lvl[MX], pi = 1, res;
vi adj[MX];

struct BIT {
	ll ft1[MX], ft2[MX];

	BIT () {
		memset(ft1, 0, sizeof(ft1));
		memset(ft2, 0, sizeof(ft2));
	}

	void update (ll ft[], int i, int k) {
		while (i < MX) {
			(ft[i] += k) %= mod;
			i += i & -i;
		}
	}

	ll query (ll ft[], int i) {
		ll s = 0;
		while (i) {
			(s += ft[i]) %= mod;
			i -= i & -i;
		}
		return s;
	}

	void update (int a, int b, ll k) {
		update(ft1, a, k);
		update(ft1, b + 1, -k);
		update(ft2, a, k * (a - 1) % mod);
		update(ft2, b + 1, -k * b % mod);
	}

	ll query (int a) {
		return (query(ft1, a) * a - query(ft2, a)) % mod;
	}

	ll query (int a, int b) {
		return query(b) - query(a - 1);
	}
}A, B;

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void da (int u, int p) {
	sz[u] = 1;

	for (int v : adj[u])
		if (v != p) {
			lvl[v] = lvl[u] + 1;
			da(v, u);
			sz[u] += sz[v];
		}
}

void dc (int u, int p, int lca) {
	(res += (lvl[u] - 2 * lvl[lca]) * inv[u] % mod * A.query(l[u], r[u])) %= mod;
	(res += inv[u] * B.query(l[u], r[u])) %= mod;

	for (int v : adj[u])
		if (v != p)
			dc(v, u, lca);
}

void dd (int u, int p, int f) {
	A.update(l[u], r[u], f * inv[u]);
	B.update(l[u], r[u], f * lvl[u] * inv[u] % mod);

	for (int v : adj[u])
		if (v != p)
			dd(v, u, f);
}

void db (int u, int p, int f) {
	if (adj[u].empty()) return;

	int mx = -1;

	for (int v : adj[u])
		if (v != p)
			if (mx == -1 || sz[v] > sz[mx])
				mx = v;

	for (int v : adj[u])
		if (v != p && v != mx)
			db(v, u, 0);

	db(mx, u, 1);

	(res += -lvl[u] * inv[u] % mod * A.query(l[u], r[u])) %= mod;
	(res += inv[u] * B.query(l[u], r[u])) %= mod;
	
	A.update(l[u], r[u], inv[u]);
	B.update(l[u], r[u], lvl[u] * inv[u] % mod);

	for (int v : adj[u])
		if (v != p && v != mx) {
			dc(v, u, u);
			dd(v, u, 1);
		}

	if (!f) {
		for (int v : adj[u])
			if (v != p)
				dd(v, u, -1);

		A.update(l[u], r[u], -inv[u]);
		B.update(l[u], r[u], -lvl[u] * inv[u] % mod);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		(pi *= r[i] - l[i] + 1) %= mod;
		inv[i] = pot(r[i] - l[i] + 1, mod - 2);
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	da(1, 1);
	db(1, 1, 0);

	cout << MOD(pi * res, mod) << endl;

	return 0;
}