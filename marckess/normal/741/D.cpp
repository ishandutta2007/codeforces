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

const int MX = 5e5+5, MA = 1 << ('v'-'a'+1), inf = 1e9;
int n, p, a[MX], sz[MX], lvl[MX], acu[MA], res[MX];
char c;
vii adj[MX];

void maxi (int u, int s) {
	res[s] = max(res[s], lvl[u] + acu[a[u]] - 2 * lvl[s]);

	for (int i = 0; i < 'v'-'a'+1; i++)
		res[s] = max(res[s], lvl[u] + acu[a[u]^(1<<i)] - 2 * lvl[s]);
}

void da (int u) {
	sz[u] = 1;

	for (ii &v : adj[u]) {
		a[v.fi] = a[u] ^ v.se;
		lvl[v.fi] = lvl[u] + 1;

		da(v.fi);
		sz[u] += sz[v.fi];
	}
}

void dc (int u, int s) {
	maxi(u, s);

	for (ii &v : adj[u])
		dc(v.fi, s);
}

void dd (int u, int f) {
	if (f) acu[a[u]] = max(acu[a[u]], lvl[u]);
	else acu[a[u]] = -inf;

	for (ii &v : adj[u])
		dd(v.fi, f);
}

void db (int u, int f) {
	int mx = -1;

	for (ii &v : adj[u])
		if (mx == -1 || sz[v.fi] > sz[mx])
			mx = v.fi;

	for (ii &v : adj[u])
		if (v.fi != mx) {
			db(v.fi, 0);
			res[u] = max(res[u], res[v.fi]);
		}

	if (mx != -1) {
		db(mx, 1);
		res[u] = max(res[u], res[mx]);
	}

	for (ii &v : adj[u])
		if (v.fi != mx) {
			dc(v.fi, u);
			dd(v.fi, 1);
		}

	maxi(u, u);
	acu[a[u]] = max(acu[a[u]], lvl[u]);

	if (!f)
		dd(u, 0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(acu, acu+MA, -inf);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p >> c;
		adj[p].emplace_back(i, 1<<(c-'a'));
	}

	da(1);
	db(1, 0);

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}