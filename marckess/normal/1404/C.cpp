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

int ft[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

ii st[4 * MX];
int lz[4 * MX];

void build (int i, int j, int pos) {
	st[pos] = {MX, i};
	if (i < j) {
		int m = (i + j) / 2;
		build(i, m, pos * 2);
		build(m + 1, j, pos * 2 + 1);
	}
}

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos * 2] += lz[pos];
		lz[pos * 2 + 1] += lz[pos];
	}

	st[pos].fi += lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int x) {
	push(i, j, pos);

	if (j < x) return;
	if (x <= i) {
		lz[pos] = -1;
		push(i, j, pos);
		return;
	}

	int m = (i + j) / 2;
	update(i, m, pos * 2, x);
	update(m + 1, j, pos * 2 + 1, x);

	st[pos] = min(st[pos * 2], st[pos * 2 + 1]);
}

void assign (int i, int j, int pos, int x, int k) {
	push(i, j, pos);

	if (j < x || x < i) return;

	if (i == j) {
		st[pos].fi = k;
		return;
	}

	int m = (i + j) / 2;
	assign(i, m, pos * 2, x, k);
	assign(m + 1, j, pos * 2 + 1, x, k);

	st[pos] = min(st[pos * 2], st[pos * 2 + 1]);
}

int n, q, a[MX], x[MX], y[MX], res[MX], cn;
vi pos[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	forn (i, n) cin >> a[i + 1];

	forn (i, q) {
		cin >> x[i] >> y[i];
		pos[x[i] + 1].pb(i);
	}

	build(1, n, 1);

	for (int i = n; i; i--) {
		int val = i - a[i];
		if (val < 0) val = MX;
		assign(1, n, 1, i, val);

		while (st[1].fi <= 0) {
			int x = st[1].se;
			update(x, 1);
			update(1, n, 1, x);
			assign(1, n, 1, x, MX);
		}

		for (int j : pos[i])
			res[j] = query(n - y[j]);
	}

	forn (i, q) cout << res[i] << endl;

	return 0;
}