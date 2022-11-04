#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

const int MX = 2e5+5, LMX = 20;
int n, q, parent[MX], a, b, c;
vi lev(MX, -1);
vector<vi> st (MX, vi(LMX, -1));

void obtLev (int u) {
	if (lev[u] != -1)
		return;

	if (parent[u] == u) {
		lev[u] = 0;
		return;
	}

	obtLev(parent[u]);
	lev[u] = lev[parent[u]] + 1;
}

void obtST () {
	for (int i = 1; i <= n; i++)
		st[i][0] = parent[i];

	for (int j = 1; (1 << j) < n; j++)
		for (int i = 1; i <= n; i++)
			if (st[i][j-1] != -1)
				st[i][j] = st[st[i][j-1]][j-1];
}

int lca (int u, int v) {
	if (lev[u] < lev[v])
		swap (u, v);

	int dist = lev[u] - lev[v];
	while ( dist > 0) {
		int pot = log2(dist);
		u = st[u][pot];
		dist -= (1 << pot);
	}

	if (u == v)
		return u;

	for (int j = LMX - 1; j >= 0; j--) {
		if (st[u][j] != -1 && st[u][j] != st[v][j]) {
			u = st[u][j];
			v = st[v][j];
		}
	}

	return parent[u];
}

int dist (int a, int b) {
	int ab = lca(a, b);
	return lev[a] + lev[b] - 2*lev[ab];
}

int obtRes () {
	int ab = lca(a, b);
	int ac = lca(a, c);
	int bc = lca(b, c);

	int res = 0;
	if ( ab == ac ) {
		res = max(res, dist(bc, a));
		res = max(res, dist(bc, b));
		res = max(res, dist(bc, c));
	} else if ( ab == bc ) {
		res = max(res, dist(ac, a));
		res = max(res, dist(ac, b));
		res = max(res, dist(ac, c));
	} else if ( bc == ac ) {
		res = max(res, dist(ab, a));
		res = max(res, dist(ab, b));
		res = max(res, dist(ab, c));
	}

	return res + 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		parent[i] = a;
	}
	parent[1] = 1;

	for (int i = 1; i <= n; i++)
		if (lev[i] == -1)
			obtLev(i);

	obtST();
	while (q--) {
		cin >> a >> b >> c;

		cout << obtRes() << endl;
	}

	return 0;
}