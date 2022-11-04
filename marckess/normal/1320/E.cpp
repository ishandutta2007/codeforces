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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 200005, LG = 20;
int n, q, f[MX], p[LG][MX], lvl[MX], cn = 1, from[MX], inv[MX];
int k, m, vid[MX], vs[MX], ic[MX], ini[MX], fin[MX];
priority_queue<ii, vii, greater<ii>> pq;
ll dis[MX], sz;
vi gra[MX];
vii adj[MX];

void dfs (int u) {
	for (int v : gra[u])
		if (!f[v]) {
			f[v] = ++cn;

			p[0][f[v]] = f[u];
			lvl[f[v]] = lvl[f[u]] + 1;
			
			dfs(v);
		}
}

int LCA (int a, int b) {
	if (lvl[a] < lvl[b]) swap(a, b);

	for (int j = 0; j < LG; j++)
		if (lvl[a] - lvl[b] & (1 << j))
			a = p[j][a];

	if (a == b) return a;

	for (int j = LG - 1; j + 1; j--)
		if (p[j][a] != p[j][b]) {
			a = p[j][a];
			b = p[j][b];
		}

	return p[0][a];
}

int kth_anc (int u, int k) {
	for (int j = 0; j < LG; j++)
		if (k & (1 << j))
			u = p[j][u];
	return u;
}

void add (int u, int v, int w) {
	adj[u].emplace_back(v, w);
	adj[v].emplace_back(u, w);
}

void build (vi &st) {
	stack<int> anc;

	for (int u : st) {
		adj[u].clear();
		from[u] = -1;

		while (anc.size()) {
			int v = anc.top();
			if (lvl[v] < lvl[u] && kth_anc(u, lvl[u] - lvl[v]) == v)
				break;
			anc.pop();
		}

		if (anc.size())
			add(u, anc.top(), lvl[u] - lvl[anc.top()]);
		anc.push(u);
	}
}

void bfs () {
	sz = 0;

	forn (i, k) {
		int u = f[vid[i]];

		if (i) ini[i] = ini[i - 1] + vs[i - 1];
		fin[i] = ini[i] + vs[i] - 1;
		sz += vs[i];

		from[u] = i;
		dis[u] = ini[i] - 1;
		pq.emplace(dis[u], u);
	}

	while (pq.size()) {
		ll w = pq.top().fi;
		int u = pq.top().se;
		int i = from[u];
		pq.pop();

		if (w > dis[u]) continue;

		for (ii &v : adj[u]) {
			ll d = w;
			ll r = v.se;

			if (r > fin[i] - d % sz) {
				r -= fin[i] - d % sz;
				d = sz * (max(d / sz, 0ll) + 1);

				ll q = r / (fin[i] - ini[i] + 1);
				r %= fin[i] - ini[i] + 1;
				d += q * sz;

				if (r) d += ini[i] + r - 1;
				else d += fin[i] - sz;
			} else {
				d += r;
			}

			if (from[v.fi] == -1 || (f[vid[from[v.fi]]] != v.fi && dis[v.fi] > d)) {
				dis[v.fi] = d;
				from[v.fi] = i;
				pq.emplace(d, v.fi);
			}
		}
	}
}

void solve () {
	vi in, st;

	cin >> k >> m;
	forn (i, k) {
		cin >> vid[i] >> vs[i];

		in.pb(f[vid[i]]);
		st.pb(f[vid[i]]);
	}

	forn (i, m) {
		cin >> ic[i];

		in.pb(f[ic[i]]);
		st.pb(f[ic[i]]);
	}

	sort(all(in));
	in.erase(unique(all(in)), in.end());
	
	forn (i, int(in.size()) - 1)
		st.pb(LCA(in[i], in[i + 1]));

	sort(all(st));
	st.erase(unique(all(st)), st.end());

	build(st);
	bfs();

	forn (i, m)
		cout << from[f[ic[i]]] + 1 << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		gra[a].pb(b);
		gra[b].pb(a);
	}

	f[1] = 1;
	p[0][1] = 1;
	dfs(1);

	for (int i = 1; i <= n; i++)
		inv[f[i]] = i;

	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j - 1][p[j - 1][i]];

	cin >> q;
	while (q--)
		solve();

	return 0;
}