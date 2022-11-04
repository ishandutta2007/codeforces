#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100000, mod = 777777777;

#define iden {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}

void mul (vvi &a, vvi &b, vvi &c) {
	c.assign(3, vi(3));
	FOR(i,3) FOR(j,3) {
		FOR(k,3) c[i][j] += a[i][k] * b[k][j];
		c[i][j] %= mod;
	}
}

int n, q, x, y, a[MX];
vvi adj(3, vi(3)), mat[MX];

ll st[4*MX];
int in[4*MX], dn[4*MX], p[MX];

void build (int i, int j, int pos) {
	st[pos] = 1;

	if (i == j) {
		p[i] = pos;
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
}

void update (int x, int k) {
	int pos = p[x];
	st[pos] = 1;
	a[x] = k;

	if (k) in[pos] = dn[pos] = x;
	else in[pos] = dn[pos] = 0;

	pos /= 2;
	while (pos) {
		st[pos] = st[pos*2] * st[pos*2+1] % mod;

		if (in[pos*2] && in[pos*2+1]) {
			vvi &t = mat[in[pos*2+1] - dn[pos*2]];
			st[pos] *= t[a[dn[pos*2]]-1][a[in[pos*2+1]]-1];
			st[pos] %= mod;

			in[pos] = in[pos*2], dn[pos] = dn[pos*2+1];
		} else if (in[pos*2]) {
			in[pos] = in[pos*2], dn[pos] = dn[pos*2];
		} else if (in[pos*2+1]) {
			in[pos] = in[pos*2+1], dn[pos] = dn[pos*2+1];
		} else {
			in[pos] = dn[pos] = 0;
		}

		pos /= 2;
	}

	if (!in[1]) {
		vvi &t = mat[n-1];
		st[1] = 0;
		FOR(i,3) FOR(j,3) st[1] += t[i][j];
		st[1] %= mod;
	} else {
		ll g = 0, h = 0;

		vvi &t = mat[in[1]-1];
		FOR(i,3) g += t[i][a[in[1]]-1];
		g %= mod;

		vvi &s = mat[n-dn[1]];
		FOR(i,3) h += s[a[dn[1]]-1][i];
		h %= mod;

		st[1] *= g * h % mod;
		st[1] %= mod;
	}
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d %d", &n, &q);
	FOR(i,3) FOR(j,3) scanf("%d", &adj[i][j]);

	mat[0] = iden;
	for (int i = 1; i <= n; i++)
		mul(mat[i-1], adj, mat[i]);

	build(1, n, 1);

	while (q--) {
		scanf("%d %d", &x, &y);
		update(x, y);
		printf("%d\n", (int)st[1]);
	}

	return 0;
}