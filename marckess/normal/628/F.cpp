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

#define SET(p,n) memset(p, n, sizeof(p))

const int inf = numeric_limits<int>::max();
const int MN = 11111, ME = 200005, MX = MN;

int src, snk, nno, ned;
int q[MN], fin[MN], pro[MN], dist[MN];
int flow[2*ME], cap[2*ME];
int sig[2*ME], to[2*ME];

inline void init (int _src, int _snk, int _n) {
	src = _src, snk = _snk, nno = _n, ned = 0;
	SET(fin, -1);
}

inline void add (int u, int v, int c) {
	to[ned] = v, cap[ned] = c, flow[ned] = 0, sig[ned] = fin[u], fin[u] = ned++;
	to[ned] = u, cap[ned] = 0, flow[ned] = 0, sig[ned] = fin[v], fin[v] = ned++;
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

		if (flow[e] < cap[e] && dist[v] == dist[u] + 1)
			if (au = dfs(v, min(mn, cap[e] - flow[e]))) {
				flow[e] += au;
				flow[e^1] -= au;
				return au;
			}
	}

	return 0;
}

int dinitz () {
	int f = 0, au;

	while (bfs()) {
		for (int i = 0; i <= nno; i++)
			pro[i] = fin[i];

		while (au = dfs(src, inf))
			f += au;
	}

	return f;
}

int n, b, Q, x, y;
map<int, int> mp;
int ini[MX], fini[MX], can[MX], m = 0, cn[MX][5];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> b >> Q;
	mp[b] = n;

	while (Q--) {
		cin >> x >> y;
		if (mp.count(x) && mp[x] != y) {
			cout << "unfair" << endl;
			return 0;
		}
		mp[x] = y;
	}

	int ant = 1, acu = 0;

	for (ii x : mp) {
		if (acu > x.se) {
			cout << "unfair" << endl;
			return 0;
		}

		ini[m] = ant;
		fini[m] = x.fi;
		can[m] = x.se - acu;

		ant = x.fi + 1;
		acu = x.se;
		m++;
	}

	for (int i = 1, j = 0; i <= b; i++) {
		cn[j][i%5]++;
		if (i == fini[j]) j++;
	}

	init(5, m+6, m+6);

	for (int i = 0; i < 5; i++)
		add(5, i, n/5);

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < 5; i++)
			add(i, j+6, cn[j][i]);
		add(j+6, m+6, can[j]);
	}

	if (dinitz() == n) cout << "fair" << endl;
	else cout << "unfair" << endl;

	return 0;
}