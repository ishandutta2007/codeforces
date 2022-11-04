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

ll n, l, r, k, x, res = -1;

ll ceil (ll a, ll b) {
	if (a < 0 != b < 0) return a / b;
	return (a + b - 1) / b;
}

void gcd (ll a, ll b, ll &x, ll &y, ll &d) {
	if (b == 0) {
		x = 1, y = 0, d = a;
		return;
	}
	gcd(b, a%b, x, y, d);

	ll tx = y;
	y = x - (a / b) * y;
	x = tx;
}

void solve1 () {
	if (k - x >= 0 && k - x <= x)
		res = max(res, k + n - 2 * x + int(k - x < x));
	
	for (ll q = 1; k - x - q * n >= 0; q++) {
		ll y = k - x - q * n;
		ll a0, b0, d;
		gcd(q + 1, q, a0, b0, d);

		ll t = ceil(x + b0 * y - n, q + 1);
		ll a = y * a0 + q * t;
		ll b = y * b0 - (q + 1) * t;

		if (0 <= a && a <= x && 0 <= b && b <= n - x)
			res = max(res, a + b);

		y++;
		t = ceil(x + b0 * y - n, q + 1);
		if (y * a0 + q * t == 0) t++;

		a = y * a0 + q * t;
		b = y * b0 - (q + 1) * t;

		if (0 < a && a <= x && 0 <= b && b <= n - x)
			res = max(res, a + b);
	}
}

void solve2 () {
	for (ll a = 0; a <= x; a++)
		for (ll b = 0; b <= n - x; b++) {
			if (k % (n + a + b) == 0 && n + a + b == x + a)
				res = max(res, a + b);

			if (k % (n + a + b) == a + x)
				res = max(res, a + b);

			if (a) {
				if ((k + 1) % (n + a + b) == 0 && n + a + b == x + a)
				res = max(res, a + b);

				if ((k + 1) % (n + a + b) == a + x)
					res = max(res, a + b);
			}
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> l >> r >> k;

	if (l > r) r += n;
	x = (r - l + 1);

	if ((x + 1) > 1e7 / (n - x + 1)) solve1();
	else solve2();

	cout << res << endl;

	return 0;
}