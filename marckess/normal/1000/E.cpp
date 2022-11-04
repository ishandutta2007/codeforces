#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 300005;

// --- DSU ---
int p[MX], rk[MX];

void init () {
	for (int i = 0; i < MX; i++) {
		p[i] = i;
		rk[i] = 0;
	}
}

int parent (int a) {
	return p[a] == a ? a : p[a] = parent(p[a]);
}

bool joint (int a, int b) {
	a = parent(a), b = parent(b);

	if (a == b)
		return 0;

	if (rk[a] > rk[b]) {
		p[b] = a;
	} else {
		p[a] = b;
		if (rk[a] == rk[b])
			rk[b]++;
	}

	return 1;
}
// --- --- ---

int n, m, x, y;
vi adj[MX];

int low[MX], num[MX], par[MX], cn = 0;
void dfs (int u) {
	low[u] = num[u] = ++cn;

	for (int v : adj[u]) {
		if (!num[v]) {
			par[v] = u;
			dfs(v);

			if (low[v] <= num[u])
				joint(u, v);

			low[u] = min(low[u], low[v]);
		} else if (v != par[u]) {
			low[u] = min(low[u], num[v]);
		}
	}
}

int dist[MX];
vi arb[MX];
int bfs (int u) {
	fill(dist, dist+MX, -1);
	queue<int> q;
	q.push(u);
	dist[u] = 0;

	while (q.size()) {
		int u = q.front(); q.pop();

		for (int v : arb[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (dist[u] < dist[i])
			u = i;

	return u;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();

	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1);

	for (int u = 1; u <= n; u++)
		for (int v : adj[u])
			if (parent(u) != parent(v)) {
				arb[parent(u)].push_back(parent(v));
				arb[parent(v)].push_back(parent(u));
			}

	bfs(bfs(parent(1)));

	cout << *max_element(dist+1, dist+n+1) << endl;

	return 0;
}