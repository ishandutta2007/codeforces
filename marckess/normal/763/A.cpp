#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, u[MX], v[MX], c[MX];
vi adj[MX];

int dfs (int u, int p) {
	int k = c[u];
	for (int v : adj[u])
		if (v != p)
			if (k != dfs(v, u))
				k = -1;
	return k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u[i] >> v[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}

	for (int i = 1; i <= n; i++)
		cin >> c[i];

	int a = -1, b = -1;

	for (int i = 1; i < n; i++)
		if (c[u[i]] != c[v[i]])
			a = u[i], b = v[i];

	if (a == -1) {
		cout << "YES\n1" << endl;
		return 0;
	}

	bool f = 1;
	for (int v : adj[a])
		if (dfs(v, a) == -1)
			f = 0;

	if (f) {
		cout << "YES" << endl << a << endl;
		return 0;
	}

	f = 1;
	for (int v : adj[b])
		if (dfs(v, b) == -1)
			f = 0;

	if (f) {
		cout << "YES" << endl << b << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}