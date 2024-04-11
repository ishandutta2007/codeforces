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

typedef complex<ld> cd;

const ld pi = acos(ld(-1));
const int MX = 300005;
int n, q, lz[4 * MX];
cd st[4 * MX], mul[4 * MX];

void build (int i, int j, int pos) {
	mul[pos] = 1;

	if (i == j) {
		st[pos] = 1;
		return;
	}

	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);

	st[pos] = st[pos * 2] + st[pos * 2 + 1];
}

void push (int i, int j, int pos) {
	if (i < j) {
		mul[pos * 2] *= mul[pos];
		mul[pos * 2 + 1] *= mul[pos];
		lz[pos * 2] = lz[pos * 2 + 1] = 1;
	}

	st[pos] *= mul[pos];
	lz[pos] = 0;
	mul[pos] = 1;
}

void update (int i, int j, int pos, int a, int b, cd k) {
	if (lz[pos]) push(i, j, pos);

	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		mul[pos] = k;
		lz[pos] = 1;
		push(i, j, pos);
		return;
	}

	int m = (i + j) / 2;
	update(i, m, pos * 2, a, b, k);
	update(m + 1, j, pos * 2 + 1, a, b, k);

	st[pos] = st[pos * 2] + st[pos * 2 + 1];
}

cd query (int i, int j, int pos, int x) {
	if (lz[pos]) push(i, j, pos);

	if (i == j) return st[pos];

	int m = (i + j) / 2;
	if (x <= m) return query(i, m, pos * 2, x);
	return query(m + 1, j, pos * 2 + 1, x);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(6);

	cin >> n >> q;
	build(1, n, 1);

	while (q--) {
		int x, y, z;
		cin >> x >> y >> z;

		if (x == 1) {
			cd k = query(1, n, 1, y);
			k = (z + abs(k)) / abs(k);
			update(1, n, 1, y, y, k);
		} else {
			cd k = polar(ld(1), -pi * z / 180);
			update(1, n, 1, y, n, k);
		}

		cout << st[1].real() << " " << st[1].imag() << endl;
	}

	return 0;
}