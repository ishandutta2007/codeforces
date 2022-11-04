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
int n, a, b, da, db, dis[MX];
vi adj[MX];

void clear () {
	for (int i = 1; i <= n; i++)
		adj[i].clear();
}

ii bfs (int s) {
	for (int i = 1; i <= n; i++)
		dis[i] = -1;

	queue<int> q;
	q.push(s);
	dis[s] = 0;

	int ult = s;
	while (q.size()) {
		int u = q.front();
		q.pop();

		ult = u;

		for (int v : adj[u])
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}

	return {ult, dis[ult]};
}

void solve () {
	cin >> n >> a >> b >> da >> db;
	clear();
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ii p = bfs(a);
	int d = dis[b];
	p = bfs(p.fi);

	db = min(db, p.se);

	if (d > da && db > 2 * da) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}