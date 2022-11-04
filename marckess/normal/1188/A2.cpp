#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005;
int n, u, v, val, ra[6*MX], rb[6*MX], rx[6*MX], r;
vii adj[MX];

int dfs (int u, int p) {
	for (ii &v : adj[u])
		if (v.fi != p)
			return dfs(v.fi, u);
	return u;
} 

bool dfs(int u, int p, int t) {
	if (u == t) return 1;
	for (ii &v : adj[u])
		if (v.fi != p && dfs(v.fi, u, t))
			return 1;
	return 0;
}

void insert (int u, int v, int w) {
	ra[r] = u, rb[r] = v, rx[r] = w;
	r++;
}

void path (int u, int v, int w) {
	if (u == v) return;
	if (adj[v].size() == 1) {
		insert(u, v, w);
		return;
	}

	int l1 = -1, l2 = -1, l3 = -1;
	for (ii &e : adj[v]) {
		if (l1 == -1) l1 = e.fi;
		else if (l2 == -1) l2 = e.fi;
		else if (l3 == -1) l3 = e.fi;
		else break;
	}
	if (dfs(l1, v, u)) swap(l1, l3);
	if (dfs(l2, v, u)) swap(l2, l3);
	l1 = dfs(l1, v);
	l2 = dfs(l2, v);

	insert(u, l1, w / 2);
	insert(u, l2, w / 2);
	insert(l1, l2, -w / 2);
}

void solve (int u, int v, int w) {
	int l = dfs(u, v);
	path(l, v, w);
	path(l, u, -w);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> val;
		adj[u].pb(v, val);
		adj[v].pb(u, val);
	}

	if (n == 2) {
		cout << "YES" << endl << 1 << endl;
		cout << 1 << " " << 2 << " " << adj[1].begin()->se << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 2) {
			cout << "NO" << endl;
			return 0;
		}

	for (int u = 1; u <= n; u++)
		for (ii v : adj[u])
			if (v.fi < u)
				solve(u, v.fi, v.se);

	cout << "YES" << endl;
	cout << r << endl;
	for (int i = 0; i < r; i++)
		cout << ra[i] << " " << rb[i] << " " << rx[i] << endl;

	return 0;
}