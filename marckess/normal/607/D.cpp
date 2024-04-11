#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200'005, mod = 1'000'000'007;

struct ST {
	ll st[4*MX], lz[4*MX];

	void init (int i, int j, int pos, int k) {
		st[pos] = k;
		lz[pos] = 1;

		if (i < j) {
			int m = (i+j)/2;
			init(i, m, pos*2, k);
			init(m+1, j, pos*2+1, k);
		}
	}

	void upLazy (int i, int j, int pos) {
		st[pos] *= lz[pos];
		st[pos] %= mod;

		if (i < j) {
			lz[pos*2] *= lz[pos];
			lz[pos*2] %= mod; 
			lz[pos*2+1] *= lz[pos];
			lz[pos*2+1] %= mod;
		}

		lz[pos] = 1;
	}

	void update (int i, int j, int pos, int a, int b, ll k) {
		if (lz[pos] > 1)
			upLazy(i, j, pos);

		if (b < i || j < a)
			return;

		if (a <= i && j <= b) {
			lz[pos] = k;
			upLazy(i, j, pos);
			return;
		}

		int m = (i+j)/2;
		update(i, m, pos*2, a, b, k);
		update(m+1, j, pos*2+1, a, b, k);

		st[pos] = (st[pos*2] + st[pos*2+1]) % mod;
	}

	void update (int i, int j, int pos, int x, ll k) {
		if (lz[pos] > 1)
			upLazy(i, j, pos);

		if (x < i || j < x)
			return;

		if (i == j) {
			st[pos] = k;
			return;
		}

		int m = (i+j)/2;
		update(i, m, pos*2, x, k);
		update(m+1, j, pos*2+1, x, k);

		st[pos] = (st[pos*2] + st[pos*2+1]) % mod;
	}

	ll query (int i, int j, int pos, int a, int b) {
		if (lz[pos] > 1)
			upLazy(i, j, pos);

		if (b < i || j < a)
			return 0;

		if (a <= i && j <= b)
			return st[pos];

		int m = (i+j)/2;
		return (query(i, m, pos*2, a, b) + query(m+1, j, pos*2+1, a, b)) % mod;
	}

}st, cont;

int q, v[MX], sz[MX], p[MX], u[MX], op[MX], ini[MX], fin[MX], par[MX], n = 1, cn = 1;
vi adj[MX];

ll pot (ll b, int p, int mod) {
	ll res = 1;
	b %= mod;

	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2; 
	}

	return res;
}

void dfs (int u) {
	ini[u] = cn++;

	for (int v : adj[u])
		dfs(v);

	fin[u] = cn - 1;
}

void insert (int p, int u) {
	ll d = ll(sz[p] + 1) * pot(sz[p], mod-2, mod) % mod;
	cont.update(1, n, 1, ini[p], fin[p], d);
	st.update(1, n, 1, ini[p], fin[p], d);

	d = cont.query(1, n, 1, ini[u], ini[u]);
	st.update(1, n, 1, ini[u], d * v[u] % mod);

	sz[p]++, sz[u]++;
}

ll obtRes (int u) {
	ll d = 1;

	if (u > 1) {
		d = cont.query(1, n, 1, ini[par[u]], ini[par[u]]);
		d = pot(d, mod-2, mod);
	}

	return d * st.query(1, n, 1, ini[u], fin[u]) % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> v[1] >> q;
	for (int i = 0; i < q; i++) {
		cin >> op[i];

		if (op[i] == 1) {
			n++;
			cin >> p[i] >> v[n];
			adj[p[i]].push_back(n);
			par[n] = p[i];
			u[i] = n;
		} else {
			cin >> u[i];
		}
	}

	st.init(1, n, 1, 0);
	st.update(1, n, 1, 1, v[1]);
	cont.init(1, n, 1, 1);

	dfs(1);
	sz[1] = 1;

	for (int i = 0; i < q; i++)
		if (op[i] == 1) 
			insert(p[i], u[i]);
		else
			cout << obtRes(u[i]) << endl;

	return 0;
}