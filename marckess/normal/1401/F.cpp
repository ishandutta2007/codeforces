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

const int MX = (1 << 18) + 5;
int n, q, a[MX], mk;
ll st[4 * MX];

void update (int pos, int d, int x, int k) {
	if (!d) {
		st[pos] = k;
		return;
	}

	x ^= bool(mk & (1 << d)) * (1 << d - 1);

	if (x & (1 << d - 1)) update(pos * 2 + 1, d - 1, x, k);
	else update(pos * 2, d - 1, x, k);

	st[pos] = st[pos * 2] + st[pos * 2 + 1];
}

ll query (int pos, int d, int x) {
	if (x < 0) return 0;
	if (!d) return st[pos];

	int f = bool(x & (1 << d - 1));

	x ^= bool(mk & (1 << d)) * (1 << d - 1);

	if (x & (1 << d - 1)) return query(pos * 2 + 1, d - 1, x) + f * st[pos * 2];
	return query(pos * 2, d - 1, x) + f * st[pos * 2 + 1];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	forn (i, (1 << n)) {
		cin >> a[i];
		update(1, n, i, a[i]);
	}

	while (q--) {
		int op, x, y;
		cin >> op >> x;

		if (op == 1) {
			cin >> y;
			x--;
			update(1, n, x, y);
		} else if (op == 2) {
			mk ^= (1 << x + 1) - 1;
		} else if (op == 3) {
			mk ^= 1 << x + 1;
		} else {
			cin >> y;
			x--, y--;
			cout << query(1, n, y) - query(1, n, x - 1) << endl;
		}
	}
	
	return 0;
}