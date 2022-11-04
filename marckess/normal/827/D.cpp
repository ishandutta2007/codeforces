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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, inf = 2e9;

typedef function<int(int,int)> fun;

struct ST {
	int st[4*MX], lz[4*MX], n;
	fun op;

	ST (fun op, int x) : op(op), n(x) { fill(st, st+4*MX, x); fill(lz, lz+4*MX, x); }

	void push (int i, int j, int pos) {
		st[pos] = op(st[pos], lz[pos]);
		if (i < j) {
			lz[pos*2] = op(lz[pos*2], lz[pos]);
			lz[pos*2+1] = op(lz[pos*2+1], lz[pos]);
		}
		lz[pos] = n;
	}

	void update (int i, int j, int pos, int a, int b, int k) {
		if (lz[pos] != n) push(i, j, pos);
		if (b < i || j < a) return;
		if (a <= i && j <= b) { lz[pos] = k; push(i, j, pos); return; }
		int m = (i+j)/2;
		update(i, m, pos*2, a, b, k);
		update(m+1, j, pos*2+1, a, b, k);
		st[pos] = op(st[pos*2], st[pos*2+1]);
	}

	int query (int i, int j, int pos, int a, int b) {
		if (lz[pos] != n) push(i, j, pos);
		if (b < i || j < a) return n;
		if (a <= i && j <= b) return st[pos];
		int m = (i+j)/2;
		return op (
			query(i, m, pos*2, a, b),
			query(m+1, j, pos*2+1, a, b)); 
	}
};

ST mn([](int a, int b){return a<b?a:b;}, inf);
ST mx([](int a, int b){return a>b?a:b;}, 0);

struct DSU {
	int p[MX];
	DSU () { iota(p, p+MX, 0); }
	int parent (int a) { return p[a] == a ? a : p[a] = parent(p[a]); }
	bool joint (int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b) return 0;
		return p[a] = b;
	}
};

int n, m, u[MX], v[MX], c[MX], q[MX], res[MX];
int p[MX], lvl[MX], sz[MX], ch[MX], pos[MX], cn = 0;
bitset<MX> bs;
vii adj[MX];

void kruskal () {
	DSU ds;

	iota(q, q+m, 0);
	sort(q, q+m, [&] (int i, int j) {
		return c[i] < c[j];
	});

	for (int i = 0; i < m; i++)
		if (ds.joint(u[q[i]], v[q[i]])) {
			bs[q[i]] = 1;
			adj[u[q[i]]].emplace_back(v[q[i]], c[q[i]]);
			adj[v[q[i]]].emplace_back(u[q[i]], c[q[i]]);
		}
}

void dfs (int u) {
	sz[u] = 1;

	for (ii &v : adj[u])
		if (v.fi != p[u]) {
			p[v.fi] = u;
			lvl[v.fi] = lvl[u]+1;
			dfs(v.fi);
			sz[u] += sz[v.fi];
		}
}

void dec (int u, int c, int w) {
	ch[u] = c;
	pos[u] = ++cn;
	mx.update(1, n, 1, pos[u], pos[u], w);

	int mx = 0, ind = -1, we;
	for (ii &v : adj[u])
		if (v.fi != p[u] && sz[v.fi] > mx) {
			mx = sz[v.fi];
			ind = v.fi;
			we = v.se;
		}

	if (mx) dec(ind, c, we);
	
	for (ii &v : adj[u]) 
		if (v.fi != p[u] && v.fi != ind) 
			dec(v.fi, v.fi, v.se);
}

int query (int a, int b, int w) {
	int res = 0;

	while (ch[a] != ch[b]) {
		if (lvl[ch[a]] < lvl[ch[b]]) swap(a, b);

		res = max(res, mx.query(1, n, 1, pos[ch[a]], pos[a]));
		mn.update(1, n, 1, pos[ch[a]], pos[a], w);
		a = p[ch[a]];
	}

	if (lvl[a] > lvl[b]) swap(a, b);
	if (a == b) return res;

	mn.update(1, n, 1, pos[a]+1, pos[b], w);
	return max(res, mx.query(1, n, 1, pos[a]+1, pos[b]));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> u[i] >> v[i] >> c[i];
	kruskal();

	dfs(1);
	dec(1, 1, 0);

	for (int i = 0; i < m; i++)
		if (!bs[i])
			res[i] = query(u[i], v[i], c[i]);

	for (int i = 0; i < m; i++)
		if (bs[i]) {
			if (lvl[u[i]] > lvl[v[i]]) swap(u[i], v[i]);
			res[i] = mn.query(1, n, 1, pos[v[i]], pos[v[i]]);
		}

	for (int i = 0; i < m; i++)
		if (res[i] == inf) cout << -1 << " ";
		else cout << res[i]-1 << " ";
	cout << endl;

	return 0;
}