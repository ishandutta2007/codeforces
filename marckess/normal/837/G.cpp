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

const int MX = 200005, mod = 1e9;

ii operator + (ii a, ii b) {
	return {a.fi+b.fi, a.se+b.se};
}

struct ST {
	ii st;
	ST *izq, *der;

	ST () {}
	ST (ST *_izq, ST *_der) {
		izq = _izq, der = _der;
		st = izq->st + der->st;
	}
	ST (int a, int b) : izq(0), der(0) { st = {a, b}; }

	void build (int i, int j) {
		if (i == j) return;
		int m = (i+j)/2;
		(izq = new ST)->build(i, m);
		(der = new ST)->build(m+1, j);
	}

	ST *update (int i, int j, int x, int a, int b) {
		if (x < i || j < x) return this;
		if (i == j) return new ST(a, b);
		int m = (i+j)/2;
		return new ST(
			izq->update(i, m, x, a, b),
			der->update(m+1, j, x, a, b) );
	}

	ii query (int i, int j, int l, int r) {
		if (r < i || j < l) return {0, 0};
		if (l <= i && j <= r) return st;
		int m = (i+j)/2;
		return
			izq->query(i, m, l, r) +
			der->query(m+1, j, l, r);
	}
};

typedef tuple<int, int, int> iii;
int n, m, l, r, x;
ll last = 0;
vector<iii> pos[MX];
ST *st[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, a, b, y2;
		cin >> x1 >> x2 >> y1 >> a >> b >> y2;

		pos[0].emplace_back(0, y1, i);
		pos[x1+1].emplace_back(a, b, i);
		pos[x2+1].emplace_back(0, y2, i);
	}

	st[0] = new ST;
	st[0]->build(1, n);
	for (int i = 0; i < MX; i++) {
		if (i) st[i] = st[i-1];
		for (auto &z : pos[i]) {
			int a, b, x;
			tie(a, b, x) = z;
			st[i] = st[i]->update(1, n, x, a, b);
		}
	}

	cin >> m;
	while (m--) {
		cin >> l >> r >> x;
		x = (x + last) % mod;
		ii res = st[min(x, MX-1)]->query(1, n, l, r);
		last = res.fi * x + res.se;
		cout << last << endl;
		last %= mod;
	}

	return 0;
}