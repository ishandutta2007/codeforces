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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int mod = 1e9+7;
int n;
ll a[105], b[105], c[105], k;
vvi cam;

void iden (vvi &v) {
	for (int i = 0; i < 20; i++)
		v[i][i] = 1;
}

void cpy (vvi &a, vvi &b) {
	for (int i = 0; i < 20; i++)
		a[i] = b[i];
}

vvi mul (vvi &a, vvi &b) {
	vvi res(20, vi(20));

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < 20; k++)
				res[i][j] += a[i][k] * b[k][j] % mod;
			res[i][j] %= mod;
		}

	return res;
}

vvi pot (vvi &base, ll p) {
	vvi res(20, vi(20)); iden(res);
	vvi b(20, vi(20)); cpy(b, base);

	while (p) {
		if (p & 1) res = mul(res, b);
		b = mul(b, b);
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];

	cam.resize(20);
	for (int i = 0; i < 20; i++)
		cam[i].resize(20);

	for (int i = 0; i < 20; i++)
		cam[i][i] = 1;

	for (int i = 0; i < n; i++) {
		vvi adj(20, vi(20));

		for (int j = 0; j <= c[i]; j++) {
			if (j) adj[j][j-1] = 1;
			adj[j][j] = 1;
			if (j < c[i]) adj[j][j+1] = 1;
		}

		adj = pot(adj, min(b[i], k) - a[i]);
		cam = mul(cam, adj);
	}

	cout << cam[0][0] << endl;

	return 0;
}