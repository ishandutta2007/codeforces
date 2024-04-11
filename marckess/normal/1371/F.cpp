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

const int MX = 500005;

struct Node {
	int mx;
	int pa, pb;
	int sa, sb;
	int len;
}st1[4 * MX], st2[4 * MX];

int lz[4 * MX];

Node operator + (const Node &a, const Node &b) {
	Node r = {0, 0, 0, 0, 0, a.len + b.len};
	int cen = 0;

	if (!a.sb && !b.pa) cen = a.sa + b.pb;
	else if (!a.sb) cen = a.sa + b.pa + b.pb;
	else if (!b.pa) cen = a.sa + a.sb + b.pb;

	r.mx = max({a.mx, b.mx, cen});

	r.pa = a.pa;
	r.pb = a.pb;

	if (a.pa + a.pb == a.len) {
		if (!b.pa) r.pb += b.pb;
		else if (!a.pb) {
			r.pa += b.pa;
			r.pb += b.pb;
		} 
	}

	r.sa = b.sa;
	r.sb = b.sb;

	if (b.sa + b.sb == b.len) {
		if (!a.sb) r.sa += a.sa;
		else if (!b.sa) {
			r.sa += a.sa;
			r.sb += a.sb;
		}
	}

	return r;
}

void build (int i, int j, int pos, char a[]) {
	if (i == j) {
		if (a[i] == '>') {
			st1[pos] = {1, 1, 0, 1, 0, 1};
			st2[pos] = {1, 0, 1, 0, 1, 1};
		} else {
			st1[pos] = {1, 0, 1, 0, 1, 1};
			st2[pos] = {1, 1, 0, 1, 0, 1};
		}

		return;
	}

	int m = (i + j) / 2;
	build(i, m, pos * 2, a);
	build(m + 1, j, pos * 2 + 1, a);

	st1[pos] = st1[pos * 2] + st1[pos * 2 + 1];
	st2[pos] = st2[pos * 2] + st2[pos * 2 + 1];
}

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos * 2] ^= lz[pos];
		lz[pos * 2 + 1] ^= lz[pos];
	}

	swap(st1[pos], st2[pos]);
	lz[pos] = 0;
}

Node update (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);

	if (b < i || j < a) return {0, 0, 0, 0, 0, 0};

	if (a <= i && j <= b) {
		lz[pos] = 1;
		push(i, j, pos);
		return st1[pos];
	}

	int m = (i + j) / 2;
	Node r = update(i, m, pos * 2, a, b) + update(m + 1, j, pos * 2 + 1, a, b);

	st1[pos] = st1[pos * 2] + st1[pos * 2 + 1];
	st2[pos] = st2[pos * 2] + st2[pos * 2 + 1];

	return r;
}

int n, q;
char a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, n, 1, a);

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << update(1, n, 1, l, r).mx << endl;
	}

	return 0;
}