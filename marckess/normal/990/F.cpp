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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, s[MX], m, x[MX], y[MX], res[MX];
vii adj[MX];
bitset<MX> bs;

int add (int u, int v, int w, int i) {
	if (u == x[i] && v == y[i]) res[i] = w;
	else res[i] = -w;
}

int dfs (int u) {
	bs[u] = 1;

	for (ii &v : adj[u])
		if (!bs[v.fi]) {
			int w = dfs(v.fi);
			add(u, v.fi, w, v.se);
			s[u] += w;
		}

	return s[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		adj[x[i]].emplace_back(y[i], i);
		adj[y[i]].emplace_back(x[i], i);
	}

	if (dfs(1)) cout << "Impossible" << endl;
	else {
		cout << "Possible" << endl;
		for (int i = 0; i < m; i++)
			cout << res[i] << endl;
	}

	return 0;
}