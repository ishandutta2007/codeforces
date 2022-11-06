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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, u, v, a[MX], sz[MX], acu[(1<<20)+5];
ll res[MX];
char c;
vi adj[MX];
bitset<MX> bs;

void dfs0 (int u, int p) {
	sz[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			dfs0(v, u);
			sz[u] += sz[v];
		}
}

void dfs (int u, int p, int k, int x) {
	x ^= a[u];
	acu[x] += k;

	for (int v : adj[u])
		if (bs[v] && v != p)
			dfs(v, u, k, x);
}

ll sum (int u, int p, int x) {
	x ^= a[u];

	ll ans = acu[x];
	if (!x) ans++;

	for (int i = 0; i < 20; i++) {
		ans += acu[x^(1<<i)];
		if (!(x^(1<<i))) ans++;
	}

	for (int v : adj[u])
		if (bs[v] && v != p)
			ans += sum(v, u, x);

	res[u] += ans;
	return ans;
}

void centroid (int u) {
	int tam = 1;

	for (int v : adj[u])
		if (bs[v])
			tam += sz[v];

	while (1) {
		int ind = -1;

		for (int v : adj[u])
			if (bs[v] && 2 * sz[v] > tam)
				ind = v;

		if (ind == -1) break;
		sz[u] = tam - sz[ind];
		u = ind;
	}

	bs[u] = 0;

	for (int v : adj[u])
		if (bs[v])
			dfs(v, u, 1, 0);

	ll ans = 0;
	for (int v : adj[u])
		if (bs[v]) {
			dfs(v, u, -1, 0);
			ans += sum(v, u, a[u]);
			dfs(v, u, 1, 0);
		}

	ans += acu[a[u]];
	for (int i = 0; i < 20; i++)
		ans += acu[a[u]^(1<<i)];
	res[u] += ans / 2 + 1;

	for (int v : adj[u])
		if (bs[v])
			dfs(v, u, -1, 0);

	for (int v : adj[u])
		if (bs[v])
			centroid(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	scanf("%d", &n);
	forn(i, n-1) {
		scanf("%d%d ", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%c", &c);
		a[i] = 1 << (c - 'a');
	}

	dfs0(1, 1);
	bs.set();
	centroid(1);

	for (int i = 1; i <= n; i++)
		printf("%lld ", res[i]);
	printf("\n");

	return 0;
}