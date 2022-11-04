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

const int MX = 103, mod = 1000000007;
int n, k, a[MX], y;

vvi iden (int n) {
	vvi a(n, vi(n));
	for (int i = 0; i < n; i++)
		a[i][i] = 1;
	return a;
}

void mul (vvi &a, vvi &b, vvi &c) {
	vvi res(a.size(), vi(b[0].size()));
	for (int i = 0; i < res.size(); i++)
		for (int j = 0; j < res[0].size(); j++)
			for (int k = 0; k < b.size(); k++) {
				res[i][j] += ll(a[i][k]) * b[k][j] % mod;
				if (res[i][j] >= mod) res[i][j] -= mod;
			}
	swap(res, c);
}

vvi pot (vvi b, int p) {
	vvi res = iden(b.size());
	while (p) {
		if (p & 1) mul(res, b, res);
		mul(b, b, b);
		p /= 2;
	}
	return res;
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

void impr (vvi &a) {
	for (vi &x : a) {
		for (int y : x)
			cout << y << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!a[i]) y++;
	}

	if (!y || y == n) {
		cout << 1 << endl;
		return 0;
	}

	vvi b(y+1, vi(y+1));

	for (int i = 0; i <= y; i++) {
		b[i][i] = n * (n - 1) / 2;
		if (i) {
			b[i][i-1] = i * (n - y - (y - i));
			//b[i][i-1] = max(b[i][i-1], 0);
			b[i][i] -= b[i][i-1];
		}
		if (i < y) {
			b[i][i+1] = (y - i) * (y - i);
			//b[i][i+1] = max(b[i][i+1], 0);
			b[i][i] -= b[i][i+1];
		}
	}

	vvi res = pot(b, k);
	//impr(res);

	int x = 0;
	for (int i = 0; i < y; i++)
		x += 1 - a[i];
	cout << res[x][y] * pot(pot(n * (n - 1) / 2, k), mod - 2) % mod << endl;
	
	return 0;
}