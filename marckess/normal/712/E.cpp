#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

typedef pair<double, double> dd;

const int MX = 100005;

// --- ST ---
dd st[4*MX];
int ps[MX];

void build (int i, int j, int pos) {
	if (i < j) {
		int m = (i+j)/2;
		build(i, m, pos*2);
		build(m+1, j, pos*2+1);
	} else {
		ps[i] = pos;
	}
}

dd merge (dd a, dd b) {
	if (a.fi == -1)
		return b;

	if (b.fi == -1)
		return a;

	return {
		a.fi * b.fi / (1 - (1 - b.fi) * a.se),
		b.se + (1 - b.se) * a.se * b.fi / (1 - a.se * (1 - b.fi))
	};
}

void update (int i, double p) {
	int pos = ps[i];
	st[pos] = {p, p};
	pos /= 2;

	while (pos) {
		st[pos] = merge(st[pos*2], st[pos*2+1]);
		pos /= 2;
	}
}

dd query (int i, int j, int pos, int a, int b) {
	if (b < i || j < a)
		return {-1, -1};

	if (a <= i && j <= b)
		return st[pos];

	int m = (i+j)/2;
	return merge( query(i, m, pos*2, a, b), query(m+1, j, pos*2+1, a, b) );
}
// --- -- ---

int n, q, op, l, r;
double a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(6);
	
	cin >> n >> q;

	build(1, n, 1);
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		update(i, a / b);
	}

	while (q--) {
		cin >> op;

		if (op == 1) {
			cin >> l >> a >> b;
			update(l, a / b);
		} else {
			cin >> l >> r;
			cout << query(1, n, 1, l, r).fi << endl;
		}
	}

	return 0;
}