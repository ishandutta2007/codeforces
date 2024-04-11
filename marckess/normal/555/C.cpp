#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;

struct ST {
	int st[4*MX];

	void push (int i, int j, int pos) {
		if (i < j) {
			st[pos*2] = max(st[pos], st[pos*2]);
			st[pos*2+1] = max(st[pos], st[pos*2+1]);
			st[pos] = 0;
		}
	}

	void update (int i, int j, int pos, int a, int b, int k) {
		if (st[pos]) push(i, j, pos);

		if (j < a || b < i) return;

		if (a <= i && j <= b) {
			st[pos] = max(st[pos], k);
			return;
		}

		int m = (i+j)/2;
		update(i, m, pos*2, a, b, k);
		update(m+1, j, pos*2+1, a, b, k);
	}

	int query (int i, int j, int pos, int a) {
		if (st[pos]) push(i, j, pos);
		if (j < a || a < i) return 0;
		if (i == j) return st[pos];

		int m = (i+j)/2;
		return max( query(i, m, pos*2, a), query(m+1, j, pos*2+1, a) );
	}

}fx, fy;

int n, q, x[MX], y[MX], a[MX], b[MX], ex[MX], ey[MX];
char d[MX];
vi cx(1), cy(1);

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> x[i] >> y[i] >> d[i];
		cx.push_back(x[i]);
		cy.push_back(y[i]);
	}

	sort(ALL(cx)), sort(ALL(cy));
	cx.erase(unique(ALL(cx)), cx.end());
	cy.erase(unique(ALL(cy)), cy.end());

	for (int i = 0; i < q; i++) {
		a[i] = lower_bound(ALL(cx), x[i]) - cx.begin();
		b[i] = lower_bound(ALL(cy), y[i]) - cy.begin();
	}

	for (int i = 0; i < q; i++) {
		if (d[i] == 'L') {
			if (ex[a[i]]) { cout << 0 << endl; continue; }
			ex[a[i]] = 1;

			int d = fy.query(1, q, 1, b[i]);
			cout << x[i] - cx[d] << endl;
			fx.update(1, q, 1, d, a[i], b[i]);
		} else {
			if (ey[b[i]]) { cout << 0 << endl; continue; }
			ey[b[i]] = 1;

			int d = fx.query(1, q, 1, a[i]);
			cout << y[i]- cy[d] << endl;
			fy.update(1, q, 1, d, b[i], a[i]);
		}
	}

	return 0;
}