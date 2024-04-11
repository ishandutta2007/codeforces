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

const int MX = 150005, mod = 998244353;
int n, q, sz[MX], ind[MX], head[MX], pos[MX], ft[MX], cn, p[MX];
vi adj[MX];
ll inv, off, lz[MX], s[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void update (int i, int k) {
	while (i < MX) {
		(ft[i] += k) %= mod;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		(s += ft[i]) %= mod;
		i -= i & -i;
	}
	return s;
}

int query (int a, int b) {
	if (a > b) swap(a, b);
	return query(b) - query(a - 1);
}

void dfs (int u) {
	sz[u] = 1;
    
	for (int v : adj[u]) {
		if (v != p[u]) {
			p[v] = u;
			dfs(v);
			sz[u] += sz[v];
        }
    }
}

void obtHLD (int u, int ch) {
	head[u] = ch;
	pos[u] = ++cn;

	int mx = 0;
	for (int v : adj[u]) {
		if (v != p[u] && sz[v] > mx) {
			mx = sz[v];
			ind[u] = v;
		}
	}

	if (mx)
		obtHLD(ind[u], ch);

	for (int v : adj[u]) {
		if (v != p[u] && v != ind[u]) {
			obtHLD(v, v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	obtHLD(1, 1);
	inv = pot(n, mod - 2);

	while (q--) {
		int op, v, d;
		cin >> op >> v;

		if (op == 1) {
			cin >> d;
			(s[v] += 1ll * n * d) %= mod;
			
			(off += 1ll * d * sz[v]) %= mod;
			update(pos[v], -1ll * d * sz[v] % mod);

			if (ind[v])
				update(pos[ind[v]], 1ll * d * (n - sz[ind[v]]) % mod);
			(lz[v] += d) %= mod;
		} else {
			ll res = s[v];

			while (v) {
				res += query(pos[v], pos[head[v]]);
				v = head[v];
				(res += lz[p[v]] * (n - sz[v])) %= mod;
				v = p[v];
			}

			cout << MOD((res + off) * inv, mod) << endl;
		}
	}

	return 0;
}