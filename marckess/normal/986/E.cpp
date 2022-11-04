#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, LG = 18;
const int MA = 10000005, mod = 1000000007;
int lp[MA], cn[MA], ini[MA], m;
int n, a[MX], q, p[MX][LG], lvl[MX], x[MX];
ll res[MX];
vi adj[MX], pos[MX];

void pre () {
	for (ll i = 2; i < MA; i++)
		if (!lp[i]) {
			lp[i] = i;

			for (ll j = i * i; j < MA; j += i)
				lp[j] = i;

			ini[i] = m++;
			for (ll j = i * i; j < MA; j *= i)
				m++;
		}
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);

	forn (j, LG)
		if (lvl[u] - lvl[v] & (1 << j))
			u = p[u][j];

	if (u == v) return u;

	for (int j = LG - 1; j >= 0; j--)
		if (p[u][j] != p[v][j]) {
			u = p[u][j];
			v = p[v][j];
		} 

	return p[u][0];
}

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[u][0]) {
			lvl[v] = lvl[u] + 1;
			p[v][0] = u;
			dfs(v);
		}
}

void go (int u) {
	#define divi(ini,op) for (int y = ini; y > 1;) { \
		int p = lp[y], pw = 0; \
		while (y % p == 0) y /= p, pw++; \
		forn (j, pw) op; \
	} \

	divi(a[u], cn[ini[p] + j]++)

	for (int j : pos[u]) {
		ll c = 1;

		divi(x[abs(j)], (c *= pot(p, cn[ini[p] + j])) %= mod)

		if (j < 0) (res[-j] *= pot(c, 2 * mod - 4)) %= mod;
		else (res[j] *= c) %= mod;
	}

	for (int v : adj[u])
		if (v != p[u][0])
			go(v);

	divi(a[u], cn[ini[p] + j]--)
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pre();

	cin >> n;
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	p[1][0] = 1;
	dfs(1);

	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];

	cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, v, lca;

		cin >> u >> v >> x[i];
		lca = LCA(u, v);

		pos[u].pb(i);
		pos[v].pb(i);
		pos[lca].pb(-i);

		res[i] = __gcd(a[lca], x[i]);
	}

	go(1);

	for (int i = 1; i <= q; i++) cout << res[i] << endl;

	return 0;
}