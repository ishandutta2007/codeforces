#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 500005;
int n, q, e1, e2, dis[MX], c[MX];
vii adj[MX];

struct Tree {
	int f[MX], ini[MX], fin[MX], lvl[MX], inv[MX], sz;
	int par[4 * MX], imp[4 * MX], lz[4 * MX];
	
	Tree () {
		memset(lz, 0, sizeof(lz));
		memset(lvl, 0, sizeof(lvl));
		sz = 0;
	}
	
	void dfs (int u, int p) {
		ini[u] = ++sz;
		inv[sz] = u;
		
		for (const ii &v : adj[u])
			if (v.fi != p) {
				lvl[v.fi] = lvl[u] + 1;
				f[v.se] = v.fi;
				dfs(v.fi, u);
			}
		
		fin[u] = sz;
	}
	
	void build (int i, int j, int pos) {
		imp[pos] = 0;
		
		if (i == j) {
			par[pos] = lvl[inv[i]];
			return;
		}
		
		int m = (i + j) / 2;
		
		build(i, m, pos * 2);
		build(m + 1, j, pos * 2 + 1);
		
		par[pos] = max(par[pos * 2], par[pos * 2 + 1]);
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] ^= 1;
			lz[pos * 2 + 1] ^= 1;
		}
		lz[pos] = 0;
		swap(par[pos], imp[pos]);
	}
	
	void update (int i, int j, int pos, int a, int b) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = 1;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		
		update(i, m, pos * 2, a, b);
		update(m + 1, j, pos * 2 + 1, a, b);
		
		par[pos] = max(par[pos * 2], par[pos * 2 + 1]);
		imp[pos] = max(imp[pos * 2], imp[pos * 2 + 1]);
	}
	
	void update (int i) {
		update(1, n, 1, ini[f[i]], fin[f[i]]);
	}
}t1, t2;

int bfs (int s) {
	memset(dis, -1, sizeof(dis));
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		
		for (ii &v : adj[u])
			if (dis[v.fi] == -1) {
				q.push(v.fi);
				dis[v.fi] = dis[u] + 1;
			}
	}
	
	int ind = s;
	for (int i = 1; i <= n; i++)
		if (dis[i] > dis[ind])
			ind = i;
		
	return ind;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
	
	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b >> c[i];
		adj[a].pb(ii(b, i));
		adj[b].pb(ii(a, i));
	}
	
	e1 = bfs(1);
	e2 = bfs(e1);
	
	t1.dfs(e1, e1);
	t2.dfs(e2, e2);
	
	t1.build(1, n, 1);
	t2.build(1, n, 1);
	
	forn (i, n - 1) if (c[i]) {
		t1.update(i);
		t2.update(i);
	}
	
	cin >> q;
	while (q--) {
		int id;
		cin >> id;
		id--;
		
		t1.update(id);
		t2.update(id);
		
		cout << max(t1.par[1], t2.par[1]) << endl;
	}
	
	return 0;
}