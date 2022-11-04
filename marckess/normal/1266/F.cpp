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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int n, x[MX], y[MX], res[MX], res2[MX], p[MX], w[MX];
vi adj[MX];
multiset<int> lf[MX];

int dfs (int u) {
	for (int v : adj[u])
		if (v != p[u]) {
			p[v] = u;

			int d = dfs(v) + 1;
			if (d > 0) lf[u].insert(d);

			if (x[u] < d) {
				y[u] = x[u];
				x[u] = d;
			} else if (y[u] < d) {
				y[u] = d;
			}
		}

	x[u] = max(x[u], 0);
	return x[u];
}

void dfs2 (int u) {
	if (w[u] < 0)
		w[u] = -1e9;
	else if (w[u] > 0)
		lf[u].insert(w[u]);

	for (int v : adj[u])
		if (v != p[u]) {
			if (x[v] + 1 == x[u])
				w[v] = max(w[u], y[u]) + 1;
			else
				w[v] = max(w[u], x[u]) + 1;
			dfs2(v);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(x, x + MX, -int(1e9));
	fill(y, y + MX, -int(1e9));

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	p[1] = 1;
	dfs(1);

	if (adj[1].size() == 1)
		w[1] = 0;
	else
		w[1] = -1e9;
	dfs2(1);

	res[n] = 1;
	for (int i = 1; i <= n; i++) {
		int acu = lf[i].size(), act = 0;

		while (1) {
			auto it = lf[i].upper_bound(act);
			if (it == lf[i].end())
				break;

			act = *it;
			res[2 * act] = max(res[2 * act], acu);
			res[2 * act + 1] = max(res[2 * act + 1], 1 + (acu - (int)lf[i].count(act)));
			acu -= lf[i].count(act);
		}
	}

	for (int i = 1; i <= n; i++) {
		set<ii> ev;
		map<int, int> mp;
		priority_queue<ii> pq;

		for (int x : lf[i])
			ev.emplace(x, i);
		mp[i] = lf[i].size();

		for (int v : adj[i])
			if (v != p[i]) {
				for (int x : lf[v])
					ev.emplace(x, v);
				mp[v] = int(lf[v].size()) - (w[v] > 0);
				pq.emplace((int)lf[v].size() - (w[v] > 0), v);
			}

		for (ii e : ev) {
			if (e.se == i) {
				while (pq.size() && pq.top().fi != mp[pq.top().se])
					pq.pop();

				if (pq.size()) {
					int u = pq.top().se;
					res2[2 * e.fi] = max(res2[2 * e.fi], mp[i] - 1 + mp[u]);
				}	

				mp[i] -= lf[i].count(e.fi);
			} else {
				int d = mp[e.se];

				res2[2 * e.fi] = max(res2[2 * e.fi], mp[i] - 1 + d);

				d -= lf[e.se].count(e.fi);
				if (w[e.se] == e.fi)
					d++;

				if (d)
					pq.emplace(d, e.se);
				mp[e.se] = d;
			}

			if (pq.empty()) break;
		}
	}

	for (int i = n - 1; i >= 1; i--) {
		res[i] = max(res[i], res[i+1]);
		res2[i] = max(res2[i], res2[i+2]);
	}

	res[1]++;

	for (int i = 1; i <= n; i++)
		cout << max(res[i], res2[i]) << " ";
	cout << endl;

	return 0;
}