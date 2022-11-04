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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, a[MX], lz[4 * MX], f[4 * MX][10], to[10];
ll st[4 * MX][10], res[10], aux[10];

void merge (ll a[], ll b[], ll c[]) {
	forn (i, 10)
		a[i] = b[i] + c[i];
}

void merge (int a[], int b[]) {
	forn (i, 10)
		a[i] = b[a[i]];	
}

void build (int i, int j, int pos) {
	iota(f[pos], f[pos] + 10, 0);

	if (i == j) {
		for (int k = 1, x = a[i]; x; k *= 10, x /= 10)
			st[pos][x % 10] += k;
		return;
	}

	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
	merge(st[pos], st[pos * 2], st[pos * 2 + 1]);

}

void push (int i, int j, int pos) {
	if (i < j) {
		merge(f[pos * 2], f[pos]);
		merge(f[pos * 2 + 1], f[pos]);
	
		lz[pos * 2] = lz[pos * 2 + 1] = 1;
	}

	forn (i, 10) aux[i] = st[pos][i];
	forn (i, 10) st[pos][i] = 0;
	forn (i, 10) st[pos][f[pos][i]] += aux[i];
	
	lz[pos] = 0;
	iota(f[pos], f[pos] + 10, 0);
}

void update (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);

	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		forn (i, 10) f[pos][i] = to[i];
		lz[pos] = 1;
		push(i, j, pos);
		return;
	}

	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b);
	update(m + 1, j, pos * 2 + 1, a, b);

	merge(st[pos], st[pos * 2], st[pos * 2 + 1]);
}

void query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);

	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		forn (i, 10) res[i] += st[pos][i];
		return;
	}

	int m = (i + j) / 2;
	query(i, m, pos * 2, a, b);
	query(m + 1, j, pos * 2 + 1, a, b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, n, 1);

	while (q--) {
		int op, l, r, x, y;

		cin >> op >> l >> r;

		if (op == 1) {
			cin >> x >> y;

			iota(to, to + 10, 0);
			to[x] = y;

			update(1, n, 1, l, r);
		} else {
			memset(res, 0, sizeof(res));
			query(1, n, 1, l, r);

			ll r = 0;
			forn (i, 10) r += i * res[i];
			cout << r << endl;
		}
	}

	return 0;
}