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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

#define SET(p,n) memset(p, n, sizeof (p))

const int INF = INT_MAX;
const int MN = 205, ME = MN*MN+MN;

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

ll dinic () {
	ll f = 0;
	int au;

	while (bfs()) {
		for (int i = 0; i <= nno; i++)
			pro[i] = fin[i];

		while (au = dfs(src, INF))
			f += au;
	}

	return f;
}

int n, m, a[55], b[55], c[55], d[55];
vi sx, sy;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn(i, m){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		sx.pb(--a[i]), sx.pb(c[i]);
		sy.pb(--b[i]), sy.pb(d[i]);
	}

	sort(all(sx));
	sx.erase(unique(all(sx)), sx.end());
	sort(all(sy));
	sy.erase(unique(all(sy)), sy.end());

	init(0, 4 * m + 1, 4 * m + 1);
	for (int i = 0; i + 1 < sx.size(); i++)
		add(0, i + 1, sx[i+1] - sx[i]);
	for (int j = 0; j + 1 < sy.size(); j++)
		add(sx.size() + j, 4 * m + 1, sy[j+1] - sy[j]);

	for (int i = 0; i + 1 < sx.size(); i++)
		for (int j = 0; j + 1 < sy.size(); j++)
			for (int k = 0; k < m; k++)
				if (a[k] <= sx[i] && sx[i+1] <= c[k])
					if (b[k] <= sy[j] && sy[j+1] <= d[k]) {
						add(i + 1, sx.size() + j, INF);
						break;
					}

	cout << dinic() << endl;

	return 0;
}