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

#define SET(p,n) memset(p, n, sizeof (p))

const int MX = 405;

const int INF = INT_MAX;
const int MN = MX * MX, ME = 10 * MN;

int src, snk, nno, ned;
int q[MN], fin[MN], pro[MN], dist[MN];
int flow[2 * ME], cap[2 * ME];
int sig[2 * ME], to[2 * ME];

inline void init (int _src, int _snk, int _n) {
	src = _src, snk = _snk, nno = _n, ned = 0;
	SET(fin, -1);
}

inline void add (int u, int v, int c) {
	to[ned] = v, cap[ned] = c, flow[ned] = 0, sig[ned] = fin[u], fin[u] = ned++;
	to[ned] = u, cap[ned] = 0, flow[ned] = 0, sig[ned] = fin[v], fin[v] = ned++;
}

inline void reset (int _src, int _snk) {
	src = _src, snk = _snk;
	for (int i = 0; i < ned; i++)
		flow[i] = 0;
}

bool bfs () {
	int st, en, u, v;
	SET(dist, -1);

	dist[src] = st = en = 0;
	q[en++] = src;

	while (st < en) {
		u = q[st++];

		for (int e = fin[u]; e >= 0; e = sig[e]) {
			v = to[e];

			if (flow[e] < cap[e] && dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}

	return dist[snk] != -1;
}

int dfs (int u, int mn) {
	if (u == snk)
		return mn;

	int au, v;
	for (int &e = pro[u]; e >= 0; e = sig[e]) {
		v = to[e];

		if (flow[e] < cap[e] && dist[v] == dist[u]+1)
			if (au = dfs(v, min(mn, cap[e] - flow[e]))) {
				flow[e] += au;
				flow[e^1] -= au;
				return au;
		}
	}

	return 0;
}

int dinic () {
	int f = 0, au;

	while (bfs()) {
		for (int i = 0; i <= nno; i++)
			pro[i] = fin[i];

		while (au = dfs(src, INF))
			f += au;
	}

	return f;
}

int n, m, off, sz, col[MX * MX];
int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};
char a[MX][MX];
vi adj[MX * MX];
map<pair<ii, ii>, int> mp;

int f (ii a, ii b) {
	if (a > b) swap(a, b);

	auto p = make_pair(a, b);
	if (mp.count(p)) return mp[p];
	return mp[p] = sz++;
}

bool valid (int i, int j) {
	return 0 <= i && i < n
		&& 0 <= j && j < m
		&& a[i][j] == '#';
}

void add (int u, int v) {
	adj[u].pb(v);
	adj[v].pb(u);
}

void dfs (int u) {
	if (col[u]) add(sz, u, 1);
	else add(u, sz + 1, 1);

	for (int v : adj[u]) {
		if (col[u]) add(u, v, 1);

		if (col[v] == -1) {
			col[v] = 1 - col[u];
			dfs(v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) cin >> a[i];

	forn (i, n) forn (j, m)
		if (valid(i, j)) {
			vi a;
			vii b;
			off++;

			forn (l, 4) {
				int x = i + mx[l];
				int y = j + my[l];

				if (valid(x, y)) {
					a.pb(l);
					b.emplace_back(x, y);
					f(ii(i, j), b.back());
				}
			}

			forn (k, a.size())
				if ((a[k] + 1) % 4 == a[(k + 1) % a.size()])
					add(f(ii(i, j), b[k]), f(ii(i, j), b[(k + 1) % b.size()]));
		}

	init(sz, sz + 1, sz + 1);

	memset(col, -1, sizeof(col));
	forn (i, sz) if (col[i] == -1) {
		col[i] = 1;
		dfs(i);
	}

	cout << off - (sz - dinic()) << endl;

	return 0;
}