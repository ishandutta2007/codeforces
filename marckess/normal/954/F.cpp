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

const int MX = 10005, mod = 1e9+7;
int n;
ll a, l, r, _m;
vii c;

#define _1 {1,1,0}
#define _2 {1,1,1}
#define _3 {0,1,1}
#define iden {{1,0,0},{0,1,0},{0,0,1}}

void tran (vvi &a) {
	for (int i = 0; i < 3; i++)
		for (int j = i; j < 3; j++)
			swap(a[i][j], a[j][i]);
}

void mul (vvi &a, vvi &b) {
	vvi res(a.size(), vi(b[0].size()));

	for (int i = 0; i < a.size(); i++)
	for (int j = 0; j < b[0].size(); j++)
	for (int k = 0; k < b.size(); k++) {
		res[i][j] += ll(a[i][k]) * b[k][j] % mod;
		res[i][j] %= mod;
	}

	swap(a, res);
}

void pot (vvi &base, ll p) {
	vvi res = iden;
	vvi b = base;

	while (p) {
		if (p & 1) mul(res, b);
		mul(b, b);
		p /= 2;
	}

	swap(res, base);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> _m;
	while (n--) {
		cin >> a >> l >> r;
		c.emplace_back(l, a);
		c.emplace_back(r, -a);
	}

	n = c.size();
	vi b(3);
	vvi res = {{0},{1},{0}};

	ll ant = 1, act;
	sort(all(c));

	for (int i = 0; i < n;) {
		act = c[i].fi;

		vvi m(3, vi(3));
		if (!b[0] && !b[0]) m[0][0] = 1;
		if (!b[0] && !b[1]) m[0][1] = 1;

		if (!b[1] && !b[0]) m[1][0] = 1;
		if (!b[1] && !b[1]) m[1][1] = 1;
		if (!b[1] && !b[2]) m[1][2] = 1;

		if (!b[2] && !b[1]) m[2][1] = 1;
		if (!b[2] && !b[2]) m[2][2] = 1;


		pot(m, act - ant);
		tran(m);
		mul(m, res);
		swap(res, m);

		while (i < n && act == c[i].fi) {
			int x = c[i].se;
			if (x < 0) b[-x-1]--;
			else b[x-1]++;
			i++;
		}

		ant = act;
	}

	if (ant < _m) {
		vvi m(3);
		m[0] = _1;
		m[1] = _2;
		m[2] = _3;

		pot(m, _m - ant);
		tran(m);
		mul(m, res);
		swap(res, m);
	}

	cout << res[1][0] << endl;

	return 0;
}