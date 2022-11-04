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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

int n, q, a[MX], t, l, r, k, lz[4*MX];
vi st[4*MX], res;

void merge (vi &a, vi &b, vi &c) {
	c.clear();

	for (int y : a) {
		for (int x : c)
			if (x & -x & y)
				y ^= x;
		if (y) c.pb(y);
	}

	for (int y : b) {
		for (int x : c)
			if (x & -x & y)
				y ^= x;
		if (y) c.pb(y);
	}

	sort(all(c));
}

void push (int i, int j, int pos) {
	for (int &x : st[pos])
		if (x & 1)
			x ^= lz[pos];
	vi aux = st[pos];
	merge(aux, aux, st[pos]);

	if (i < j) {
		lz[pos*2] ^= lz[pos];
		lz[pos*2+1] ^= lz[pos];
	}

	lz[pos] = 0;
}

void build (int i, int j, int pos) {
	if (i == j) {
		st[pos].pb(1);
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
	merge(st[pos*2], st[pos*2+1], st[pos]);
}

void update (int i, int j, int pos, int a, int b, int k) {
	if (lz[pos]) push(i, j, pos);

	if (b < i || j < a) return;
	if (a <= i && j <= b) {
		lz[pos] ^= k;
		push(i, j, pos);
		return;
	}

	int m = (i+j)/2;
	update(i, m, pos*2, a, b, k);
	update(m+1, j, pos*2+1, a, b, k);
	merge(st[pos*2], st[pos*2+1], st[pos]);
}

void query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);

	if (b < i || j < a) return;
	if (a <= i && j <= b) {
		vi aux = res;
		merge(aux, st[pos], res);
		return;
	}

	int m = (i+j)/2;
	query(i, m, pos*2, a, b);
	query(m+1, j, pos*2+1, a, b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	build(1, n, 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, n, 1, i, i, 2 * a[i]);
	}

	while (q--) {
		cin >> t;

		if (t == 1) {
			cin >> l >> r >> k;
			update(1, n, 1, l, r, 2 * k);
		} else {
			cin >> l >> r;

			res.clear();
			query(1, n, 1, l, r);

			vi aux = res;
			for (int &x : aux)
				x /= 2;
			merge(aux, aux, res);

			cout << (1ll << res.size()) << endl;
		}
	}

	return 0;
}