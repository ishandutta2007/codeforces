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

const int MX = 44;
int n, m, c, no, bi = 1;
ll adj[MX], vis, col, dp[1 << 21], r;

void dfs (int u, int d) {
	vis |= 1ll << u;
	col |= ll(d) << u;

	for (int v = 0; v < n; v++)
		if (adj[u] & (1ll << v)) {
			if (!(vis & (1ll << v)))
				dfs(v, 1 - d);
			if (bool(col & (1ll << v)) == bool(d))
				bi = 0;
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x] |= 1ll << y;
		adj[y] |= 1ll << x;
	}

	for (int i = 0; i < n; i++)
		if (!(vis & (1ll << i))) {
			if (!adj[i]) no++;
			else dfs(i, 0);
			c++;
		}

	for (int i = 0; i < (1 << min(n, 20)); i++) {
		ll mk = 0;
		for (int j = 0; j < min(n, 20); j++)
			if (i & (1ll << j))
				mk |= adj[j];

		if (mk & i) continue;
		dp[i]++;
		r++;
	}

	if (n > 20) {
		r = 0;

		for (int j = 0; j < 20; j++)
			for (int i = 0; i < (1 << 20); i++)
				if (~i & (1 << j))
					dp[i | (1 << j)] += dp[i];

		for (int i = 0; i < (1 << n - 20); i++) {
			ll mk = 0;
			for (int j = 20; j < n; j++)
				if (i & (1ll << j - 20))
					mk |= adj[j];

			if ((mk >> 20) & i) continue;
			mk &= (1 << 20) - 1;
			mk ^= (1 << 20) - 1;
			r += dp[mk];
		}
	}

	cout << (1ll << n)
		  - 2 * r
		  - (1ll << c)
		  + 2 * (1ll << no)
		  + (bi ? (1ll << c) : 0)
		  - (no < n ? 0 : (1ll << n)) << endl;

	return 0;
}