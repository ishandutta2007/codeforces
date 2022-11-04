#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 100005;
int n, p[MX], s[MX], a[MX];
vi adj[MX];
ll res;

void no () {
	cout << -1 << endl;
	exit(0);
}

void dfs (int u, int par) {
	if (s[u] == -1) {
		int mn = 2e9;
		for (int v : adj[u])
			if (v != par)
				mn = min(mn, s[v]);
		if (mn == 2e9) return;

		a[u] = mn - s[p[u]];
		s[u] = mn;
		if (a[u] < 0) no();
		res += a[u];

		for (int v : adj[u])
			if (v != par)
				dfs(v, u);
	} else {
		a[u] = s[u] - s[p[u]];
		if (a[u] < 0) no();
		res += a[u];

		for (int v : adj[u])
			if (v != par)
				dfs(v, u);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}

	for (int i = 1; i <= n; i++)
		cin >> s[i];

	dfs(1, 0);
	cout << res << endl;

	return 0;
}