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

const int MX = 2e5+5, LMX = 19;
int n, q, p[MX], a[MX], inv[MX], lvl[MX];
vi adj[MX];

int cn = 1, ini[MX], st[2*MX][LMX];

void dfs (int u) {
	ini[u] = cn;
	st[cn][0] = u;
	cn++;

	for (int v : adj[u]) {
		dfs(v);
		st[cn][0] = u;
		cn++;
	}
}

int LCA (int i, int j) {
	i = ini[i], j = ini[j];
	if (i > j) swap(i, j);

	int k = log2(j-i+1);
	if (lvl[st[i][k]] < lvl[st[j-(1<<k)+1][k]])
		return st[i][k];
	return st[j-(1<<k)+1][k];
}

bool samePath (int x, int a, int b, int y) {
	int lca = LCA(x, y);
	
	int f = LCA(x, a);
	int g = LCA(y, a);

	if (f != lca) swap(f, g);
	if (f != lca || g != a) return 0;

	f = LCA(x, b);
	g = LCA(y, b);

	if (f != lca) swap(f, g);
	if (f != lca || g != b) return 0;

	return 1;
}

struct ST {
	int x, y;
	bool ex;
};

int stpos[MX], mx = 0;
ST mex[4*MX], res, aux;

void merge (ST &in, ST &a, ST &b) {
	if (!a.ex || !b.ex) {
		in.ex = 0;
		return;
	}

	vi v = {a.x, a.y, b.x, b.y};
	sort(all(v));

	do if (samePath(v[0], v[1], v[2], v[3])) {
		in.x = v[0], in.y = v[3], in.ex = 1;
		return;
	}
	while (next_permutation(all(v)));

	in.ex = 0;
}

void build (int i, int j, int pos) {
	if (i == j) {
		mex[pos].x = mex[pos].y = inv[i];
		mex[pos].ex = 1;
		stpos[i] = pos;
		return;
	}

	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m+1, j, pos * 2 + 1);

	merge(mex[pos], mex[pos*2], mex[pos*2+1]);
}

void update (int x, int k) {
	int pos = stpos[x];
	
	mex[pos].x = k;
	mex[pos].y = k;
	pos /= 2;

	while (pos) {
		merge(mex[pos], mex[pos*2], mex[pos*2+1]);
		pos /= 2;
	}
}

void query (int i, int j, int pos) {
	if (i == j) return;

	int m = (i+j)/2;

	if (mex[pos*2].ex) {
		if (res.ex) {
			merge(aux, res, mex[pos*2]);

			if (aux.ex) {
				mx = m;
				res = aux;
				query(m+1, j, pos*2+1);
			} else {
				query(i, m, pos*2);
			}

		} else {
			mx = m;
			res = mex[pos*2];
			query(m+1, j, pos*2+1);
		}
	} else {
		query(i, m, pos*2);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]++;
		inv[a[i]] = i;
	}

	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
		lvl[i] = lvl[p[i]] + 1;
	}

	dfs(1);
	for (int j = 1; (1 << j) <= cn; j++)
		for (int i = 1; i + (1 << j) - 1 < cn; i++)
			if (lvl[st[i][j-1]] < lvl[st[i+(1<<(j-1))][j-1]])
				st[i][j] = st[i][j-1];
			else
				st[i][j] = st[i+(1<<(j-1))][j-1];

	build(1, n, 1);

	cin >> q;
	while (q--) {
		int t, i, j;
		cin >> t;

		if (t == 1) {
			cin >> i >> j;
			swap(inv[a[i]], inv[a[j]]);
			swap(a[i], a[j]);

			update(a[i], inv[a[i]]);
			update(a[j], inv[a[j]]);
		} else {
			if (mex[1].ex) cout << n << endl;
			else {
				res.ex = 0;
				query(1, n, 1);
				cout << mx << endl;
			}
		}
	}

	return 0;
}