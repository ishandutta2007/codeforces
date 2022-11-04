#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 300005;

int q, x[MX], y[MX], p[2*MX], rk[2*MX];
ll res = 0, fi[2*MX], se[2*MX];
map<ii, vi> mp;
vii st[4*MX];
vi _x[4*MX], _y[4*MX], aux[4*MX];

int parent (int a) {
	while (a != p[a]) a = p[a];
	return a;
}

void joint (int &x, int &y, int &t) {
	if (x == y) return void (t = -1);
	if (rk[x] < rk[y]) swap(x, y);

	res -= fi[x] * se[x] + fi[y] * se[y];
	fi[x] += fi[y], se[x] += se[y];
	res += fi[x] * se[x];

	p[y] = x;
	if (rk[x] == rk[y]) rk[x] += t = 1;
}

void undo (int x, int y, int t) {
	if (t == -1) return;

	res -= fi[x] * se[x];
	fi[x] -= fi[y], se[x] -= se[y];
	res += fi[x] * se[x] + fi[y] * se[y];

	p[y] = y;
	rk[x] -= t;
}

void update (int i, int j, int pos, int l, int r, int x, int y) {
	if (r < i || j < l) return;
	if (l <= i && j <= r) return void(st[pos].emplace_back(x, y));
	int m = (i+j)/2;
	update(i, m, pos*2, l, r, x, y);
	update(m+1, j, pos*2+1, l, r, x, y);
}

void dfs (int i, int j, int pos) {
	aux[pos] = vi(st[pos].size());
	_x[pos] = vi(st[pos].size());
	_y[pos] = vi(st[pos].size());

	for (int i = 0; i < st[pos].size(); i++) {
		_x[pos][i] = parent(st[pos][i].fi);
		_y[pos][i] = parent(st[pos][i].se);
		joint(_x[pos][i], _y[pos][i], aux[pos][i]);
	}

	if (i == j) {
		cout << res << " ";
	} else {
		int m = (i + j) / 2;
		dfs(i, m, pos*2);
		dfs(m+1, j, pos*2+1);
	}

	for (int i = (int) st[pos].size() - 1; i + 1; i--)
		undo(_x[pos][i], _y[pos][i], aux[pos][i]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
		mp[{x[i], y[i]}].pb(i);
	}

	for (int i = 0; i < 2 * MX; i++) {
		p[i] = i;
		if (i < MX) fi[i] = 1;
		else se[i] = 1;
	}

	for (map<ii, vi>::iterator it = mp.begin(); it != mp.end(); it++) {
		vi &v = it->se;
		if (v.size() & 1) v.pb(q + 1);
		for (int j = 0; j < v.size(); j += 2)
			update(1, q, 1, v[j], v[j+1]-1, it->fi.fi, it->fi.se + MX);
	}

	dfs(1, q, 1);
	cout << endl;

	return 0;
}