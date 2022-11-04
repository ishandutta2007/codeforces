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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

typedef bitset<1024> big;

const int MX = 100005;
int n, mod, a[MX], u, v, ini[MX], fin[MX], cn = 0;
int q, op, x, lz[4*MX], inv[MX];
big mask[1024], bs, st[4*MX], res;
vi adj[MX];

void pre () {
	for (int i = 1; i < mod; i++) {
		mask[i] = mask[i-1];
		mask[i][mod-i] = 1;
		if (i > 1) bs[i] = 1;
	}

	for (int i = 2; i < mod; i++)
		if (bs[i])
			for (int j = i * i; j < mod; j += i)
				bs[j] = 0;
}

void shift (big &b, int k) {
	big aux = b & mask[k];
	b <<= k;
	b |= aux >> (mod-k);
}

void build (int i, int j, int pos) {
	if (i == j) {
		st[pos][a[inv[i]]] = 1;
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
	st[pos] = st[pos*2] | st[pos*2+1];
}

void push (int i, int j, int pos) {
	shift(st[pos], lz[pos]);

	if (i < j) {
		lz[pos*2] += lz[pos];
		if (lz[pos*2] >= mod) lz[pos*2] -= mod;
		lz[pos*2+1] += lz[pos];
		if (lz[pos*2+1] >= mod) lz[pos*2+1] -= mod;
	}

	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, int k) {
	if (lz[pos]) push(i, j, pos);
	if (b < i || j < a) return;
	
	if (a <= i && j <= b) {
		lz[pos] = k;
		push(i, j, pos);
		return;
	}

	int m = (i+j)/2;
	update(i, m, pos*2, a, b, k);
	update(m+1, j, pos*2+1, a, b, k);
	st[pos] = st[pos*2] | st[pos*2+1];
}

void query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (b < i || j < a) return;

	if (a <= i && j <= b) {
		res |= st[pos];
		return;
	}

	int m = (i+j)/2;
	query(i, m, pos*2, a, b);
	query(m+1, j, pos*2+1, a, b);
}

void dfs (int u, int p) {
	ini[u] = ++cn;
	inv[cn] = u;

	for (int v : adj[u])
		if (v != p)
			dfs(v, u);

	fin[u] = cn;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> mod;
	pre();

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= mod;
	}

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 1);
	build(1, n, 1);

	cin >> q;
	while (q--) {
		cin >> op;

		if (op == 1) {
			cin >> v >> x;
			update(1, n, 1, ini[v], fin[v], x%mod);
		} else {
			cin >> v;
			res.reset();
			query(1, n, 1, ini[v], fin[v]);
			cout << (res & bs).count() << endl;
		}
	}

	return 0;
}