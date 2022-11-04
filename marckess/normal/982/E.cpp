#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll n, m, x, y, vx, vy;
bool ix = 0, iy = 0;

ll extEuc (ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = extEuc (b, a % b, x, y);

	ll _x = y, _y = x - (a / b) * y;
	x = _x;
	y = _y;
	return d;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> x >> y >> vx >> vy;

	if (vx == 0 && (!x || x == n)) {
		if (vy > 0) cout << x << " " << m << endl;
		else cout << x << " " << 0 << endl;
		return 0;
	}

	if (vy == 0 && (!y || y == m)) {
		if (vx > 0) cout << n << " " << y << endl;
		else cout << 0 << " " << y << endl;
		return 0;
	}

	if (!vx || !vy) {
		cout << -1 << endl;
		return 0;
	}

	if (vx < 0) {
		x = n - x;
		ix = 1;
	}

	if (vy < 0) {
		y = m - y;
		iy = 1;
	}

	ll c = x - y, a, b, _m = m, _n = n;
	ll d = extEuc(n, -m, a, b);

	if (c % d != 0) {
		cout << -1 << endl;
		return 0;
	}

	a *= c / d;
	b *= c / d;

	ll ini = min(a / (m / d), b / (n / d)) - 1, k1 = 3e18, k2 = 3e18, rx, ry;

	for (int i = 0; i < 3; i++, ini++)
		if (a + (-m / d) * ini > 0 && b - (n / d) * ini > 0)
			k1 = min(a + (-m / d) * ini, k1), k2 = min(b - (n / d) * ini, k2);

	if ((k1 & 1) ^ ix) rx = _n;
	else rx = 0;

	if ((k2 & 1) ^ iy) ry = _m;
	else ry = 0;

	cout << rx << " " << ry << endl;

	return 0;
}