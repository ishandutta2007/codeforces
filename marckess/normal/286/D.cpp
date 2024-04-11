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

const int MX = 1e9+1, MN = 1e5+5;

struct ST {
	ST *izq, *der;
	int cn, lz;

	ST () : izq(0), der(0), cn(0), lz(0) {}

	void push (int i, int j) {
		if (i < j) {
			if (!izq) izq = new ST;
			if (!der) der = new ST;

			int m = (i+j)/2;

			izq->cn += cn;
			der->cn += cn;

			izq->lz += lz;
			der->lz += lz + (m - i + 1) * cn;

			cn = lz = 0;
		}
	}

	void inc (int i, int j, int a, int b, int k) {
		if (cn || lz) push(i, j);

		if (b < i || j < a) return;
		if (a <= i && j <= b) {
			lz += k;
			cn++;
			return;
		}

		if (!izq) izq = new ST;
		if (!der) der = new ST;

		int m = (i+j)/2;
		izq->inc(i, m, a, b, k);
		der->inc(m+1, j, a, b, k + max(0, m-max(a,i)+1));
	}

	void sum (int i, int j, int a, int b, int k) {
		if (cn || lz) push(i, j);

		if (b < i || j < a) return;
		if (a <= i && j <= b) {
			lz += k;
			return;
		}

		if (!izq) izq = new ST;
		if (!der) der = new ST;

		int m = (i+j)/2;
		izq->sum(i, m, a, b, k);
		der->sum(m+1, j, a, b, k);
	}

	int query (int i, int j, int p) {
		if (cn || lz) push(i, j);

		if (p < i || j < p) return 0;
		if (i == j) return lz;

		int m = (i+j)/2;
		if (p <= m && izq) return izq->query(i, m, p);
		if (p > m && der) return der->query(m+1, j, p);
	}
};

int n, m, l[MN], r[MN], t[MN], q;
ST *st = new ST;
vii a;
priority_queue<ii, vii, greater<ii>> pq;

void insert (int l, int r, int t) {
	int b = t-l, a = b-(r-l)+1;
	int off = a < 0 ? -a+1 : 1;

	if (b >= 0)
		st->inc(1, MX, max(a+1, 1), min(b+1, MX), off);
	if ((b+2)<=MX)
		st->sum(1, MX, max(1, b+2), MX, r-l);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i] >> t[i];
		a.emplace_back(l[i], i);
		a.emplace_back(r[i], -1);
	}

	sort(all(a));

	int ant = -1;
	for (ii &x : a) {
		while (pq.size() && pq.top().se < x.fi)
			pq.pop();

		if (ant != -1 && ant != x.fi)
			if (pq.size())
				insert(ant, x.fi, pq.top().fi);

		if (x.se != -1)
			pq.emplace(t[x.se], r[x.se]);
		ant = x.fi;
	}

	while (n--) {
		cin >> q;
		cout << st->query(1, MX, q+1) << endl;
	}

	return 0;
}