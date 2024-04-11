#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define first fi
#define second se
#define SET(p,n) memset(p, n, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MN = 200005;

int p[MN], fin[MN], ini[MN], n, a[MN], num = 1;
vvi adj;

int dfs (int u) {
	int c = 1;

	ini[u] = num++;
	for (int v : adj[u]) {
		if (v == p[u])
			continue;
		c += dfs(v);
	}
	fin[u] = num-1;
}

int st[4*MN], q, v;
vector<bool> lz(4*MN);

void constr (int i, int j, int pos) {
	if (i == j) {
		st[pos] = a[i];
		return;
	}

	int m = (i+j)/2;
	constr(i, m, pos*2);
	constr(m+1, j, pos*2+1);

	st[pos] = st[pos*2] + st[pos*2+1];
}

void act (int i, int j, int pos) {
	lz[pos] = 0;
	st[pos] = j - i + 1 - st[pos];

	if (i != j) {
		lz[pos*2] = !lz[pos*2];
		lz[pos*2+1] = !lz[pos*2+1];
	}
}

void update (int i, int j, int a, int b, int pos) {
	if (lz[pos])
		act(i, j, pos);

	if (a > j || b < i)
		return;

	if (a <= i && j <= b) {
		act(i, j, pos);
		return;
	}

	int m = (i+j)/2;
	update(i, m, a, b, pos*2);
	update(m+1, j, a, b, pos*2+1);

	st[pos] = st[pos*2+1] + st[pos*2];
}

int query (int i, int j, int a, int b, int pos) {
	if (lz[pos])
		act(i, j, pos);

	if (a > j || b < i)
		return 0;

	if (a <= i && j <= b)
		return st[pos];

	int m = (i+j)/2;
	return query(i, m, a, b, pos*2) + query(m+1, j, a, b, pos*2+1);
}

string op;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	adj = vvi(n+2);

	for (int i = 2; i <= n; i++) {
		cin >> p[i];

		adj[p[i]].push_back(i);
		adj[i].push_back(p[i]);
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
		cin >> a[ini[i]];
	constr(1, n, 1);

	cin >> q;
	while (q--) {
		cin >> op >> v;

		if (op == "pow")
			update(1, n, ini[v], fin[v], 1);
		else
			cout << query(1, n, ini[v], fin[v], 1) << endl;
	}

	return 0;
}