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
typedef vector<ii> vii;

const int MX = 300005;
int n, k, s[MX], p[MX], f[MX], rk[MX], x[MX], y[MX], res, acu, cn[MX][2];
vi adj[MX], pos[MX];
bitset<MX> ex;

ii parent (int u) {
	int col = 0;
	while (u != p[u]) {
		col ^= f[u];
		u = p[u];
	}
	return {u, col};
}

void join (int a, int b, bool op) {
	if (!p[a]) p[a] = a, cn[a][0] = 1;
	if (!p[b]) p[b] = b, cn[b][0] = 1;

	ii x = parent(a);
	ii y = parent(b);
	if (x.fi == y.fi) return;

	if (rk[x.fi] < rk[y.fi]) swap(x, y);
	if (rk[x.fi] == rk[y.fi]) rk[x.fi]++;

	acu -= min(cn[x.fi][0], cn[x.fi][1]);
	acu -= min(cn[y.fi][0], cn[y.fi][1]);

	if (op == (x.se != y.se)) {
		cn[x.fi][0] += cn[y.fi][0];
		cn[x.fi][1] += cn[y.fi][1];
	} else {
		cn[x.fi][0] += cn[y.fi][1];
		cn[x.fi][1] += cn[y.fi][0];
		f[y.fi] = 1;	
	}

	p[y.fi] = x.fi;
	acu += min(cn[x.fi][0], cn[x.fi][1]);
}

int act;
void dfs (int u, int x) {
	ex[u] = 0;

	if (!s[x]) {
		res++;
		for (int y : pos[u])
			s[y] ^= 1;
	}

	for (int y : pos[u])
		if (y <= act)
			for (int v : adj[y])
				if (ex[v] && p[v])
					dfs(v, y);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s[i] = c - '0';
	}

	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		pos[i].resize(c);
		for (int j = 0; j < c; j++) {
			cin >> pos[i][j];
			adj[pos[i][j]].pb(i);
		}
	}

	ex.set();

	for (int i = 1; i <= n; i++) {
		act = i;

		if (adj[i].size() == 2 && ex[adj[i][0]] && ex[adj[i][1]]) {
			join(adj[i][0], adj[i][1], 1 - s[i]);
		} else {
			int ind = -1;
			if (adj[i].size() >= 1 && ex[adj[i][0]]) ind = adj[i][0];
			if (adj[i].size() == 2 && ex[adj[i][1]]) ind = adj[i][1];

			if (ind != -1) {
				if (p[ind]) {
					ii x = parent(ind);
					acu -= min(cn[x.fi][0], cn[x.fi][1]);
				}
				dfs(ind, i);
			}
		}

		cout << res + acu << endl;
	}

	return 0;
}