#include <bits/stdc++.h>
 
//#define endl '\n'
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

const int MX = 200005;
int n, lvl[MX], sz[MX], p[MX], head[MX], dis;
vi adj[MX];

void dfs (int u, int lev) {
	lvl[u] = lev;
	sz[u] = 1;

	if (lev == dis)
		adj[u].clear();

	for (int v : adj[u]) {
		if (v != p[u]) {
			p[v] = u;
			dfs(v, lev + 1);
			sz[u] += sz[v];
		}
	}
}

void obtHLD (int u, int ch) {
	head[u] = ch;

	int mx = 0, ind = -1;
	for (int v : adj[u])
		if (v != p[u] && sz[v] > mx) {
			mx = sz[v];
			ind = v;
		}

	if (mx)
		obtHLD(ind, ch);

	for (int v : adj[u])
		if (v != p[u] && v != ind)
			obtHLD(v, v);
}

void go (int u) {
	while (1) {
		int f = 1;

		while (f) {
			f = 0;
			for (int v : adj[u])
				if (v != p[u] && head[v] == head[u]) {
					u = v;
					f = 1;
					break;
				}
		}

		int d;
		cout << "d " << u << endl;
		cin >> d;
		if (d == -1) exit(0);

		if (d == 0) {
			cout << "! " << u << endl;
			exit(0);
		}

		while (abs(lvl[u] - dis) != d) {
			u = p[u];
			d--;
		}

		cout << "s " << u << endl;
		cin >> u;
		if (u == -1)
			exit(0);
	}
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	cout << "d " << 1 << endl;
	cin >> dis;
	if (dis == -1) exit(0);

	dfs(1, 0);
	obtHLD(1, 1);
	go(1);

	return 0;
}