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

const int MX = 500005;
int n, m, vis[MX], lvl[MX], p[MX], dis[MX], in[MX];
vi gra[MX], adj[MX];

void clear () {
	for (int i = 1; i <= n; i++) {
		gra[i].clear();
		adj[i].clear();

		vis[i] = 0;
		in[i] = 0;
	}
}

void pre (int u) {
	vis[u] = 1;

	for (int v : gra[u])
		if (!vis[v]) {
			adj[u].pb(v);
			adj[v].pb(u);
			lvl[v] = lvl[u] + 1;
			pre(v);
		}
}

ii bfs (int s) {
	for (int i = 1; i <= n; i++)
		p[i] = dis[i] = -1;

	queue<int> q;
	q.push(s);
	dis[s] = 1;

	int mx = 1, ind = s;

	while (q.size()) {
		int u = q.front();
		q.pop();

		mx = dis[u];
		ind = u;

		for (int v : adj[u])
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				p[v] = u;
				q.push(v);
			} 
	}

	return {mx, ind};
}

void solve () {
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		gra[u].pb(v);
		gra[v].pb(u);
	}

	lvl[1] = 1;
	pre(1);

	ii x = bfs(bfs(1).se);

	if (x.fi * 2 >= n) {
		cout << "PATH" << endl;
		cout << (n + 1) / 2 << endl;

		int u = x.se;
		forn (i, (n + 1) / 2) {
			cout << u << " ";
			u = p[u];
		}
		cout << endl;

		clear();
		return;
	}


	cout << "PAIRING" << endl;
	
	vii v;

	for (int i = 1; i <= n; i++) {
		if (in[lvl[i]]) {
			v.emplace_back(i, in[lvl[i]]);
			in[lvl[i]] = 0;
		}
		else in[lvl[i]] = i;
	}

	cout << v.size() << endl;
	for (ii &p : v) cout << p.fi << " " << p.se << endl;

	clear();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}