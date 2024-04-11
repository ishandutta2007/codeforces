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

#define find(v,x) (lower_bound(all(v), x) - v.begin())

const int MX = 1000005, inf = 2e9;
int n, m, k, a[MX], q, op[MX], l[MX], r[MX], x[MX];
int st[4*MX], lz[4*MX];
vi c;

void push (int i, int j, int pos) {
	st[pos] = lz[pos];

	if (i < j) {
		lz[pos*2] = lz[pos];
		lz[pos*2+1] = lz[pos];
	}

	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, int x) {
	if (lz[pos]) push(i, j, pos);
	if (b < i || j < a) return;

	if (a <= i && j <= b) {
		lz[pos] = x;
		push(i, j, pos);
		return;
	}

	int m = (i+j)/2;
	update(i, m, pos*2, a, b, x);
	update(m+1, j, pos*2+1, a, b, x);

	st[pos] = min(st[pos*2], st[pos*2+1]);
}

int query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (b < i || j < a) return inf;
	if (a <= i && j <= b) return st[pos];

	int m = (i+j)/2;
	return min(query(i, m, pos*2, a, b), query(m+1, j, pos*2+1, a, b));
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	c.resize(n+1);
	iota(all(c), 0);
	c.pb(n*k);
	c.pb(n*k+1);

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> op[i] >> l[i] >> r[i];
		if (op[i] == 1) cin >> x[i];

		c.pb(l[i]);
		c.pb(r[i]);
		c.pb(r[i]+1);
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	m = c.size();

	for (int i = 1; i <= n; i++)
		update(1, m, 1, i, i, a[i]);

	for (int i = n+1; i < m-1; i++) {
		int l = c[i], r = c[i+1]-1, x;

		if (r - l + 1 >= n)
			x = query(1, m, 1, 1, n);
		else {
			l = (l-1) % n + 1;
			r = (r-1) % n + 1;

			if (l <= r)
				x = query(1, m, 1, l, r);
			else
				x = min(
					query(1, m, 1, 1, r),
					query(1, m, 1, l, n)
					);
		}
		update(1, m, 1, i, i, x);
	}

	for (int i = 0; i < q; i++) {
		l[i] = find(c, l[i]);
		r[i] = find(c, r[i]);

		if (op[i] == 1) {
			update(1, m, 1, l[i], r[i], x[i]);
		} else {
			cout << query(1, m, 1, l[i], r[i]) << endl;
		}
	}

	return 0;
}