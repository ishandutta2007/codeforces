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

const int MX = 100005, LMX = 18, DMX = 13;

struct DSU {
	vi p;
	int cn;

	DSU () { init(); }
	DSU (int n) { init(n); }

	void init () { p.clear(); cn = 0; }
	void init (int n) { p.resize(n); iota(ALL(p), 0); cn = n; }
	void insert () { p.push_back(p.size()); cn++; }
	int parent (int a) { return a == p[a] ? a : p[a] = parent(p[a]); }

	bool joint (int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b) return 0;
		p[a] = b;
		cn--;
		return 1;
	}
};

int n, k, m, u, v, q, l, r;
vi adj[MX];

DSU stl[LMX][MX], str[LMX][MX];

void dsucpy (DSU &a, DSU &b) {
	int sz = min(k, (int)b.p.size());
	a.init(sz);
	for (int i = 1; i < sz; i++)
		for (int j = 0; j < i; j++)
			if (b.parent(i) == b.parent(j))
				a.joint(i, j);
	a.cn = b.cn;
}

void build () {
	DSU acu;

	for (int j = 0;; j++) {
		int sz = 1 << j;
		if (sz > n) break;

		int mk = sz - 1, ini = 0;
		acu.init();
		for (int u = 0; u < n; u++) {
			acu.insert();
			for (int v : adj[u])
				if (ini <= v && v < u)
					acu.joint(u-ini, v-ini);

			dsucpy(stl[j][u], acu);
			if ((u & mk) == mk) {
				acu.init();
				ini = u+1;
			}
		}

		acu.init();
		ini = n-1;
		for (int u = n-1; u >= 0; u--) {
			acu.insert();
			for (int v : adj[u])
				if (u < v && v <= ini)
					acu.joint(ini-u, ini-v);

			dsucpy(str[j][u], acu);
			if ((u & mk) == 0) {
				acu.init();
				ini = u-1;
			}
		}
	}
}

int query (int l, int r) {
	if (l == r) return 1;

	int j = 31 - __builtin_clz(l^r), m = r;
	DSU ds(2*k);

	while (m - (m & -m) > l)
		m -= m & -m;

	const DSU &a = str[j][l], &b = stl[j][r];
	ds.cn = a.cn + b.cn;

	//cout << l << "," << m-1 << " " << m << "," << r << " " << a.cn << " " << b.cn << endl;

	for (int i = 0; i < a.p.size(); i++) ds.p[i] = a.p[i];
	for (int i = 0; i < b.p.size(); i++) ds.p[i+k] = b.p[i]+k;

	for (int u = m; u < m+b.p.size() && u < m+k; u++)
		for (int v : adj[u])
			if (l <= v && v < m)
				ds.joint(u-m+k, m-1-v);

	return ds.cn;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> m;
	while (m--) {
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}

	build();

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << query(l-1, r-1) << endl;
	}

	return 0;
}