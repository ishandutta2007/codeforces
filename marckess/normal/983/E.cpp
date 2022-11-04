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

const int MX = 200005, LMX = 19;

struct PST {
	PST *izq, *der;
	int x;

	PST () : izq(0), der(0), x(0) {}
	PST (int x) : izq(0), der(0), x(x) {}
	PST (PST *_izq, PST *_der) {
		izq = _izq, der = _der;
		x = izq->x + der->x;
	}

	void build (int i, int j) {
		if (i == j) return;
		int m = (i+j)/2;
		(izq = new PST)->build(i, m);
		(der = new PST)->build(m+1, j);
	}

	PST *update (int i, int j, int p) {
		if (p < i || j < p) return this;
		if (i == j) return new PST(x + 1);
		int m = (i+j)/2;
		return new PST(izq->update(i, m, p), der->update(m+1, j, p));
	}

	int query (int i, int j, int a, int b) {
		if (b < i || j < a) return 0;
		if (a <= i && j <= b) return x;
		int m = (i+j)/2;
		return izq->query(i, m, a, b) + der->query(m+1, j, a, b);
	}
};

int n, p[MX][LMX], an[MX][LMX], m, a, b, q, lvl[MX];
int cn = 0, ini[MX], fin[MX];
vi adj[MX], pos[MX];
PST *st[MX];

int LCA (int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);

	for (int j = 0; j < LMX; j++)
		if (lvl[a] - lvl[b] & (1 << j))
			a = p[a][j];

	if (a == b) return a;

	for (int j = LMX - 1; j >= 0; j--)
		if (p[a][j] != p[b][j])
			a = p[a][j], b = p[b][j];

	return p[a][0];
}

void dfs (int u) {
	ini[u] = ++cn;
	for (int v : adj[u]) dfs(v);
	fin[u] = cn;
}

ii query (int a, int b) {
	int d = 0;
	for (int j = LMX - 1; j >= 0; j--)
		if (an[a][j] != -1 && lvl[an[a][j]] > lvl[b]) {
			a = an[a][j];
			d |= (1 << j);
		}

	if (an[a][0] == -1 || lvl[an[a][0]] > lvl[b]) return {-1, -1};
	return {d + 1, a};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i][0];
		lvl[i] = lvl[p[i][0]] + 1;
		adj[p[i][0]].pb(i);
	}

	p[1][0] = 1;
	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j-1]][j-1];

	dfs(1);

	cin >> m;
	memset(an, -1, sizeof(an));
	while (m--) {
		cin >> a >> b;
		if (ini[a] > ini[b]) swap(a, b);
		
		pos[ini[a]].pb(ini[b]);

		int c = LCA(a, b);
		if (an[a][0] == -1 || lvl[an[a][0]] > lvl[c]) an[a][0] = c;
		if (an[b][0] == -1 || lvl[an[b][0]] > lvl[c]) an[b][0] = c;
	}

	for (int u = n; u > 0; u--)
		for (int v : adj[u])
			if (an[v][0] != -1 && an[v][0] != v)
				if (an[u][0] == -1 || lvl[an[u][0]] > lvl[an[v][0]])
					an[u][0] = an[v][0];

	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			if (an[i][j-1] != -1)
				an[i][j] = an[an[i][j-1]][j-1];

	(st[0] = new PST)->build(1, n);
	for (int i = 1; i <= n; i++) {
		st[i] = st[i-1];
		for (int j : pos[i])
			st[i] = st[i]->update(1, n, j);
	}

	cin >> q;
	while (q--) {
		cin >> a >> b;
		if (ini[a] > ini[b]) swap(a, b);

		int c = LCA(a, b);
		int x, y, ra, rb;

		tie(ra, x) = query(a, c);
		tie(rb, y) = query(b, c);

		if (x == -1 || y == -1) cout << -1 << endl;
		else if (a == c || b == c) cout << ra + rb - 1 << endl; 
		else {
			int d = st[fin[x]]->query(1, n, ini[y], fin[y]) - st[ini[x]-1]->query(1, n, ini[y], fin[y]);
			cout << ra + rb - bool(d) << endl;
		}
	}

	return 0;
}