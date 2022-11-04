#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;
int n, p[MX], q[MX], f[MX], par[MX];

struct ST {
	int p, q;
	ST () : p(0), q(0) {}

	ST operator + (ST b) {
		ST n;
		int d = min(p, b.q);
		n.p = p + b.p - d;
		n.q = q + b.q - d;
		return n;
	}

}st[4 * MX];

void build (int i, int j, int pos) {
	if (i == j) {
		par[i] = pos;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos * 2);
	build(m + 1, j, pos * 2 + 1);
}

void update (int x, int k) {
	int pos = par[x];
	if (k == 1) st[pos].p++;
	else st[pos].q++;

	if (st[pos].p && st[pos].q) st[pos].p = st[pos].q = 0;
	pos /= 2;

	while (pos) {
		st[pos] = st[pos * 2] + st[pos * 2 + 1];
		pos /= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	cin >> n;
	forn (i, n) {
		cin >> p[i + 1];
		f[p[i + 1]] = i + 1;
	}
	forn (i, n) cin >> q[i + 1];

	build(1, n, 1);
	update(f[n], 1);

	for (int i = 1, res = n; i <= n; i++) {
		cout << res << " ";

		update(q[i], -1);
		while (!st[1].p && res) {
			res--;
			update(f[res], 1);
		}
	}
	cout << endl;

	return 0;
}