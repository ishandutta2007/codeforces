#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

//--------------------------------------------
struct Punto {
	int x, y;
	Punto () {}
	Punto (int x, int y) : x(x), y(y) {}

	Punto operator - (Punto ot) { return {x - ot.x, y - ot.y}; }
	int operator ^ (Punto ot) { return x * ot.y - y * ot.x; }
	bool operator == (Punto ot) { return x == ot.x && y == ot.y; }
};
typedef Punto P;

struct Line {
	Punto fi, se;
	Line () {}
	Line (Punto p, Punto q) : fi(p), se(q) {}
	void pri (vi &cx, vi &cy) {
		cout << cx[fi.x] << " " << cy[fi.y] << " " << cx[se.x] << " " << cy[se.y] << endl;
	}
};

int md (Punto o, Punto p, Punto q) {
	int c = (p - o) ^ (q - o);
	return c ? c / abs(c) : 0;
}

bool inter (Line a, Line b) {
	return md(a.fi, a.se, b.fi) * md(a.fi, a.se, b.se) == -1
		&& md(b.fi, b.se, a.fi) * md(b.fi, b.se, a.se) == -1;
}
//--------------------------------------------

//--------------------------------------------
#define SET(p,n) memset(p, n, sizeof (p))

const int INF = INT_MAX;
const int MN = 10000, ME = 2000000;

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

int dinitz () {
	int f = 0, au;

	while (bfs()) {
		for (int i = 0; i <= nno; i++)
			pro[i] = fin[i];

		while (au = dfs(src, INF))
			f += au;
	}

	return f;
}
//-------------------------------------------

const int MX = 2005;
int n, x[MX], y[MX];
vi px[MX], py[MX], cx, cy;
vector<Line> hor, ver, rh, rv;
bitset<MX> ch[MX], cv[MX];

int d[MX];
vi adj[MX];
bitset<MX> vis, hx, vx;

void obtMap (int x[], vi &c) {
	for (int i = 0; i < n; i++) c.pb(x[i]);

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	for (int i = 0; i < n; i++)
		x[i] = lower_bound(all(c), x[i]) - c.begin();
}

void solvemis () {
	int n = hor.size(), m = ver.size();

	init(0, n+m+1, n+m+1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (inter(hor[i], ver[j]))
				add(i+1, n+j+1, 1);

	for (int i = 0; i < n; i++) add(0, i+1, 1);
	for (int i = 0; i < m; i++) add(n+i+1, n+m+1, 1);

	int fl = dinitz();
	
	for (int i = 1; i <= n; i++)
		for (int e = fin[i]; e != -1; e = sig[e])
			if (to[e]) {
				if (flow[e] == cap[e]) {
					adj[to[e]].pb(i);
					d[i]++;
					d[to[e]]++;
				} else {
					adj[i].pb(to[e]);
				}
			}

	for (int i = 1; i <= n; i++)
		if (dist[i] != -1)
			hx[i-1] = 1;

	for (int i = n+1; i <= n+m; i++)
		if (dist[i] == -1)
			vx[i-n-1] = 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	obtMap(x, cx);
	obtMap(y, cy);

	for (int i = 0; i < n; i++) {
		px[x[i]].pb(y[i]),
		py[y[i]].pb(x[i]);
	}

	for (int i = 0; i < n; i++) {
		sort(all(px[i])), sort(all(py[i]));
		for (int j = 1; j < py[i].size(); j++)
			hor.emplace_back(P(py[i][j-1], i), P(py[i][j], i));	
		for (int j = 1; j < px[i].size(); j++)
			ver.emplace_back(P(i, px[i][j-1]), P(i, px[i][j]));
	}

	solvemis();

	for (int i = 0; i < hor.size(); i++)
		if (hx[i]) {
			if (rh.size() && rh.back().se == hor[i].fi)
				rh.back().se = hor[i].se;
			else
				rh.pb(hor[i]);
			ch[hor[i].fi.x][hor[i].fi.y] = 1;
			ch[hor[i].se.x][hor[i].se.y] = 1;
		}

	for (int i = 0; i < ver.size(); i++)
		if (vx[i]) {
			if (rv.size() && rv.back().se == ver[i].fi)
				rv.back().se = ver[i].se;
			else
				rv.pb(ver[i]);
			cv[ver[i].fi.x][ver[i].fi.y] = 1;
			cv[ver[i].se.x][ver[i].se.y] = 1;
		}

	for (int i = 0; i < n; i++) {
		Punto p(x[i], y[i]);
		if (!ch[x[i]][y[i]]) rh.emplace_back(p, p);
		if (!cv[x[i]][y[i]]) rv.emplace_back(p, p);
	}

	assert(rh.size() + rv.size() == 2 * n - vx.count() - hx.count());

	cout << rh.size() << endl;
	for (auto r : rh) r.pri(cx, cy);
	cout << rv.size() << endl;
	for (auto r : rv) r.pri(cx, cy);

	return 0;
}