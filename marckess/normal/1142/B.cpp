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

const int MX = 200005;
int n, m, q, l, r, a[MX], in[MX], p, to[MX], s = 1, ans[MX];

struct PST {
	PST *izq, *der;
	int x;

	PST () : izq(0), der(0), x(-1) {}
	PST (PST *izq, PST *der) : izq(izq), der(der), x(-1) {}
	PST (int x) : izq(0), der(0), x(x) {}

	void build (int i, int j) {
		if (i == j) return;
		int m = (i + j)/2;
		(izq = new PST)->build(i, m);
		(der = new PST)->build(m+1, j);
	}

	PST* update (int i, int j, int x, int k) {
		if (x < i || j < x) return this;
		if (i == j) return new PST(k);
		int m = (i + j)/2;
		return new PST(izq->update(i, m, x, k), der->update(m + 1, j, x, k));
	}

	int query (int i, int j, int x) {
		if (i == j) return this->x;
		int m = (i + j) / 2;
		if (x <= m) return izq->query(i, m, x);
		return der->query(m+1, j, x);
	}
}*st[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		cin >> p;
		in[p] = i - 1;
	}

	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		a[i] = in[a[i]];
	}

	(st[0] = new PST)->build(1, n);
	ans[m+1] = -1;
	for (int i = m; i; i--) {
		int x = (a[i] + 1) % n, y = (a[i] - 1 + n) % n;

		st[s] = st[to[x]]->update(1, n, a[i] + 1, i);
		ans[i] = st[s]->query(1, n, y + 1);

		to[a[i]] = s++;
		if (ans[i] == -1 || (ans[i+1] != -1 && ans[i+1] < ans[i])) ans[i] = ans[i+1];
	}

	while (q--) {
		cin >> l >> r;
		if (ans[l] != -1 && ans[l] <= r) cout << 1;
		else cout << 0;
	}
	cout << endl;

	return 0;
}