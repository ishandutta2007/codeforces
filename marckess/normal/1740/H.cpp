#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, p[MX], ch[MX], lw[MX], st_pos[MX], sz[MX], val[MX], cn;
ll tot;
vi adj[MX];
map<int, int> mp[MX];
set<int> no[MX];

struct Node {
	int x;
	int v0, v1;
	ll s0, s1;
	
	Node () : x(-1), v0(-1), v1(-1), s0(0), s1(0) {}
}st[4 * MX];

Node merge (Node a, Node b) {
	if (a.x == -1) return b;
	if (b.x == -1) return a;
	
	Node res;
	res.x = b.x;
	
	if (b.v0 == a.x) {
		res.v0 = a.v1;
		res.s0 = a.s1 + b.s0;
	} else {
		res.v0 = a.v0;
		res.s0 = a.s0 + b.s0;
	}
	
	if (b.v1 == a.x) {
		res.v1 = a.v1;
		res.s1 = a.s1 + b.s1;
	} else {
		res.v1 = a.v0;
		res.s1 = a.s0 + b.s1;
	}
	
	return res;
}

void update (int i, int j, int pos, int a, int x, int v0, int v1) {
	if (a < i || j < a) return;
	
	if (i == j) {
		st[pos].x = x;
		st[pos].v0 = st[pos].s0 = v0;
		st[pos].v1 = st[pos].s1 = v1;
		return;
	}
	
	int m = (i + j) / 2;
	update(i, m, pos * 2, a, x, v0, v1);
	update(m + 1, j, pos * 2 + 1, a, x, v0, v1);
	
	st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
}

Node query (int i, int j, int pos, int a, int b) {
	if (b < i || j < a) return Node();
	
	if (a <= i && j <= b) return st[pos];
	
	int m = (i + j) / 2;
	return merge(
		query(i, m, pos * 2, a, b),
		query(m + 1, j, pos * 2 + 1, a, b)
	);
}

void pre (int u, int p) {
	sz[u] = 1;
	
	for (int v : adj[u])
		if (v != p) {
			pre(v, u);
			sz[u] += sz[v];
		}
}

void dfs (int u, int p, int h) {
	ch[u] = h;
	st_pos[u] = ++cn;
	lw[h] = u;
	
	int to = -1;
	for (int v : adj[u])
		if (v != p)
			if (to == -1 || sz[to] < sz[v])
				to = v;
	
	if (to != -1)
		dfs(to, u, h);
	
	for (int v : adj[u])
		if (v != p)
			if (v != to)
				dfs(v, u, v);
}

ll query (int u) {
	ll res = 0;
	
	while (1) {
		Node act = query(1, n, 1, st_pos[ch[u]], st_pos[lw[ch[u]]]);
		res += act.s0;
		
		if (ch[u] == 1) break;
		
		u = p[ch[u]];
	}
	
	return res;
}

ll update (int u) {
	ll res = 0;
	
	while (1) {
		Node act = query(1, n, 1, st_pos[ch[u]], st_pos[lw[ch[u]]]);
		res += act.s0;
		
		u = ch[u];
		if (u == 1) break;
		
		if (val[u] != -1 && --mp[p[u]][val[u]] == 0)
			no[p[u]].insert(val[u]);
		val[u] = act.v0;
		if (++mp[p[u]][val[u]] > 0)
			no[p[u]].erase(val[u]);
		
		auto it = no[p[u]].begin();
		auto jt = it; jt++;
		update(1, n, 1, st_pos[p[u]], *it, *it, *jt);
		
		u = p[u];
	}
	
	return res;
}

void main_() {
	cin >> n;
	n++;
	
	forr (i, 2, n) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	
	forr (i, 1, n)
		forr (kk, 0, (int)adj[i].size() + 2)
			no[i].insert(kk);
	
	memset(val, -1, sizeof(val));
	pre(1, 1);
	dfs(1, 1, 1);
	
	update(1, n, 1, st_pos[1], 0, 0, 1);
	
	forr (i, 2, n) {
		tot -= query(i);
		update(1, n, 1, st_pos[i], 0, 0, 1);
		tot += update(i);
		
		cout << tot << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}