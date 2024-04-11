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
 
typedef __int128 ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, LG = 18;
int n, m;
ii st[MX][LG];
vi v[MX], pos[MX], in[MX];

ll ext_euc (ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}

	ll d = ext_euc(b, a % b, x, y);
	ll x1 = y;
	ll y1 = x - (a / b) * y;
	x = x1, y = y1;

	return d;
}

ii g (ll a, ll n, ll b, ll m) {
	if (n == -1 || m == -1) return {-1, -1};

	ll x0, y0;
	ll g = ext_euc(n, -m, x0, y0);
	ll l = (n / g) * m;
	if (l < 0) l = -l;

	if ((b - a) % g) return {-1, -1};

	ll x = (n % l) * (x0 % l) % l * ((b - a) / g % l) + a;
	x = MOD(x, l);

	assert(x % n == a);
	assert(x % m == b);

	return {x, l};
}

int solve (vi &x, vi &y) {
	if (x.empty()) return 0;
	int res = 1, n = x.size(), m = 0;

	forn (i, n) st[i][0] = {x[i], y[i]};

	for (int j = 1; (1 << j) <= n; j++) {
		m = j;
		
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			ii &a = st[i][j - 1], &b = st[i + (1 << j - 1)][j - 1];
			st[i][j] = g(a.fi, a.se, b.fi, b.se);
		}
	}

	forn (i, n) {
		int to = i;
		ii a(0, 1);

		for (int j = m; j >= 0; j--) {
			ii &b = st[to][j];
			ii aux = g(a.fi, a.se, b.fi, b.se);

			if (aux.fi != -1) {
				to += 1 << j;
				a = aux; 
			}
		}

		res = max(res, to - i);
	}

	for (int j = 0; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
			st[i][j] = {-1, -1};

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	forn (i, MX) forn (j, LG) st[i][j] = {-1, -1};

	cin >> n >> m;

	forn (i, n) {
		int k;
		cin >> k;

		v[i] = vi(k);

		forn (j, k) {
			cin >> v[i][j];
			pos[v[i][j]].pb(i);
			in[v[i][j]].pb(j);
		}
	}

	for (int i = 1; i <= m; i++) {
		int res = 0;
		vi x, y;

		forn (j, pos[i].size()) {
			if (j && pos[i][j] > pos[i][j - 1] + 1) {
				res = max(res, solve(x, y));
				x.clear();
				y.clear();
			}

			x.pb(in[i][j]);
			y.pb(v[pos[i][j]].size());
		}

		res = max(res, solve(x, y));

		cout << res << endl;
	}

	return 0;
}