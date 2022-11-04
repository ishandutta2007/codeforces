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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 200005;
int n, m, a, b, c, da[MX], db[MX], dc[MX];
ll res;
ll sum[MX], p[MX];
vi adj[MX];

void reset () {
	res = 1e18;

	for (int i = 1; i <= n; i++) {
		da[i] = db[i] = dc[i] = -1;
		adj[i].clear();
	}
}

void bfs (int s, int dis[]) {
	dis[s] = 0;
	queue<int> q;
	q.push(s);

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;;
				q.push(v);
			}
	}
}

void solve () {
	cin >> n >> m >> a >> b >> c;
	reset();

	for (int i = 1; i <= m; i++)
		cin >> p[i];
	sort(p + 1, p + m + 1);

	for (int i = 1; i <= m; i++)
		sum[i] = sum[i - 1] + p[i];

	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bfs(a, da);
	bfs(b, db);
	bfs(c, dc);

	for (int k = 1; k <= n; k++) {
		ll tot = da[k] + db[k] + dc[k];

		if (tot > m) continue;

		ll p = sum[tot];
		p += sum[db[k]];

		res = min(res, p);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}