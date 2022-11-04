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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 998244353;
ll n, m, l, r;
ll par, imp;

ll pot (ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

vector<vi> mul (vector<vi> a, vector<vi> b) {
	vector<vi> res(a.size(), vi(b[0].size()));

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			for (int k = 0; k < b.size(); k++)
				(res[i][j] += a[i][k] * b[k][j]) %= mod;

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> l >> r;

	if ((n * m) & 1) {
		cout << pot(r - l + 1, n * m) << endl;
		return 0;
	}

	par = r / 2 - (l - 1) / 2;
	imp = (r - l + 1) - par;

	vector<vi> v = {{par, imp}, {imp, par}};
	vector<vi> res = {{1, 0}, {0, 1}};

	ll p = m * n;
	
	while (p) {
		if (p & 1) res = mul(res, v);
		v = mul(v, v);
		p /= 2;
	}

	cout << res[0][0] << endl;

	return 0;
}