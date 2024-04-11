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
typedef double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, col[MX], adj[MX];
int cic[MX], f[MX], to[MX], dis[MX], vis[MX];
vi /*pos[MX],*/ isb[MX];

#define num(i,j) ((i) * m + (j))

void clear () {
	forn (i, n * m) {
		//pos[i].clear();
		isb[i].clear();
		vis[i] = 0;

		cic[i] = -1;
		f[i] = -1;
		to[i] = -1;
		dis[i] = -1;
	}
}

void dfs (int u) {
	if (vis[u]) return;
	vis[u] = 1;

	int v = adj[u];

	if (vis[v] == 1) {
		int x = v;

		while (1) {
			f[x] = isb[u].size();
			cic[x] = u;
			//pos[u].pb(x);
			isb[u].pb(col[x]);

			if (x == u) break;
			x = adj[x];
		}

	} else {
		dfs(v);
	
		if (f[u] == -1) {
			if (f[v] != -1) {
				to[u] = f[v];
				dis[u] = 1;
				cic[u] = cic[v];
			} else {
				to[u] = to[v];
				dis[u] = dis[v] + 1;
				cic[u] = cic[v];
			}

			isb[cic[u]][MOD(to[u] - dis[u], (int)isb[cic[u]].size())] |= col[u];
		}
	}

	vis[u] = 2;
}

void solve () {
	cin >> n >> m;

	clear();

	forn (i, n) forn (j, m) {
		char c;
		cin >> c;
		col[num(i, j)] = 1 - int(c - '0');
	}

	forn (i, n) forn (j, m) {
		char c;
		cin >> c;

		if (c == 'U') adj[num(i, j)] = num(i - 1, j);
		else if (c == 'R') adj[num(i, j)] = num(i, j + 1);
		else if (c == 'D') adj[num(i, j)] = num(i + 1, j);
		else adj[num(i, j)] = num(i, j - 1);
	}

	forn (i, n * m)
		dfs(i);

	int x = 0, y = 0;

	forn (i, n * m) {
		x += isb[i].size();
		for (int k : isb[i])
			y += k;
	}

	cout << x << " " << y << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}