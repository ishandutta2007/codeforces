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

const int MX = 300005;
int n, q, u, v, w, x, f = 0, sz[MX], par[MX];
ll tot = 0, mn = -1;
bitset<MX> cam;
vii adj[MX];

queue<int> st;
bool dfs (int u, int p) {
	if (u == n) {
		st.push(n);
		cam[n] = 1;

		for (ii &v : adj[u])
			if (v.fi != p) {
				dfs(v.fi, u);
				sz[u] += sz[v.fi];
			}

		if (sz[u] >= 2) f = 1;

		return 1;
	}

	bool g = 0;

	for (ii &v : adj[u])
		if (v.fi != p) {
			if (dfs(v.fi, u)) {
				st.push(u);
				cam[u] = 1;
				par[v.fi] = v.se;
				tot += v.se;
				g = 1;
 			} else {
 				sz[u] += sz[v.fi];
 			}
		}

	sz[u] += 1 - g;
	if (sz[u] >= 2) f = 1;

	return cam[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	dfs(1, 1);

	ll a = -1, b = -1, acu = 0;

	while (st.size()) {
		int z = -1;
		u = st.front();
		st.pop();

		for (ii v : adj[u])
			if (!cam[v.fi])
				z = v.se;

		if (z == -1) {
			if (b != -1) mn = max(mn, tot - acu + b);
		} else {
			if (a != -1) mn = max(mn, tot - acu + a + z);
		}

		if (z == -1) {
			b = max(b, a);
			a = max(a, acu);
		} else {
			a = b = max(b, acu + z);
		}
		acu += par[u];
	}

	while (q--) {
		cin >> x;

		if (f || mn == -1) cout << tot << endl;
		else cout << min(tot, mn + x) << endl; 
	}

	return 0;
}