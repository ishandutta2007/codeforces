#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;

struct FT {
	ll ft[MX];

	FT () {
		memset(ft, 0, sizeof(ft));
	}

	void update (int i, ll k) {
		while (i < MX) {
			ft[i] += k;
			i += i & -i;
		}
	}

	ll query (int i) {
		ll sum = 0;
		while (i) {
			sum += ft[i];
			i -= i & -i;
		}
		return sum;
	} 
}ft;

int n, x, y, m, v[MX], d[MX], k[MX], cn = 1, lvl[MX], inv[MX];
int ini[MX], fin[MX];
ll res[MX];
vi adj[MX], pos[MX];

void dfs (int u, int p) {
	inv[cn] = u;
	ini[u] = cn++;
	for (int v : adj[u]) {
		if (v == p) continue;
		lvl[v] = lvl[u] + 1;
		dfs(v, u);
	}
	fin[u] = cn;
}

void add (int a, int b, int k) {
	ft.update(a, k);
	if (b+2 < MX)
		ft.update(b+1, -k);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	lvl[1] = 1;
	dfs(1, 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> v[i] >> d[i] >> k[i];
		pos[ini[v[i]]].pb(i);
		pos[fin[v[i]]].pb(i);
	}

	for (int i = 1; i <= n; i++) {
		int u = inv[i];
		
		for (int j : pos[i]) {
			if (u == v[j])
				add(lvl[v[j]], lvl[v[j]] + d[j], k[j]);
			else
				add(lvl[v[j]], lvl[v[j]] + d[j], -k[j]);
		}
		res[u] = ft.query(lvl[u]);
	}

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}