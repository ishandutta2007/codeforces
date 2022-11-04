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

const int MX = 500005, m = 500000;

struct PST {
	PST *izq, *der;
	int x;

	PST () : izq(0), der(0), x(0) {}
	PST (PST *izq, PST *der) : izq(izq), der(der), x(min(izq->x, der->x)) {}
	PST (int x) : izq(0), der(0), x(x) {}

	void build (int i, int j) {
		if (i == j)
			return;

		int m = (i+j)/2;
		(izq = new PST)->build(i, m);
		(der = new PST)->build(m+1, j);
	}

	PST *update (int i, int j, int a, int k) {
		if (a < i || j < a)
			return this;

		if (i == j)
			return new PST(k);

		int m = (i+j)/2;
		return new PST( izq->update(i, m, a, k), der->update(m+1, j, a, k) );
	}

	int query (int i, int j, int a, int b) {
		if (b < i || j < a)
			return MX;

		if (a <= i && j <= b)
			return x;

		int m = (i+j)/2;
		return min( izq->query(i, m, a, b), der->query(m+1, j, a, b) );
	}
};

PST *st[MX];
int n, a[MX], q, l, r, ant[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < MX; i++)
		ant[i] = -i;

	st[0] = new PST;
	st[0]->build(1, m);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		st[i] = st[i-1];
		st[i] = st[i]->update(1, m, i, ant[a[i]]);
		if (ant[a[i]] > 0)
			st[i] = st[i]->update(1, m, ant[a[i]], MX);
		ant[a[i]] = i;
	}

	cin >> q;
	while (q--) {
		cin >> l >> r;
		int d = st[r]->query(1, m, l, r);
		if (d >= l)
			cout << 0 << endl;
		else if (d < 0)
			cout << -d << endl;
		else
			cout << a[d] << endl;
	}

	return 0;
}