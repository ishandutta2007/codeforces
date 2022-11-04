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
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;
#define s sum[x][y] = sum[y][x] =
int n, m, acu[MX], cn, vis[MX], sz, sum[400][400], b1[MX], b2[MX];
vii adj[MX];
vi base[MX], base2[MX];
bitset<MX> c1, valid, valid2;
int mem[MX][400], hsh[(1 << 25) + 5];
vector<vi> v;

bool add (vi &base, int x) {
	forn(i, 5)
		if (x & (1 << i))
			x ^= base[i];

	if (!x) return 0;

	forn(i, 5)
		if (!base[i] && (x & (1 << i))) {
			base[i] = x;

			forn(j, i)
				if (base[j] & (1 << i))
					base[j] ^= x;

			break;
		}

	return 1;
}

void dfs (int u, int p, int w) {
	acu[u] = w;
	vis[u] = 1;

	for (ii &v : adj[u]) {
		if (v.fi == p) continue;

		if (vis[v.fi] == 1) {
			if (v.fi == 1) c1[cn] = 1;
			else valid2[cn] = valid2[cn] & add(base2[cn], w ^ v.se ^ acu[v.fi]);
			valid[cn] = valid[cn] & add(base[cn], w ^ v.se ^ acu[v.fi]);
		} else if (!vis[v.fi]) {
			dfs(v.fi, u, w ^ v.se);
		}
	}

	vis[u] = 2;
}

int get (vi b) {
	int pos = 0;
	for (int y : b)
		pos = 32 * pos + y;
	if (hsh[pos] == -1) {
		v.pb(b);
		hsh[pos] = sz++;
	}
	return hsh[pos];
}

int dp (int i, int h) {
	if (h == -1) return 0;
	if (i == cn) return 1;
	
	if (mem[i][h] != -1) return mem[i][h];
	ll res = dp(i + 1, h);
	
	if (valid[i])
		res += dp(i + 1, sum[h][b1[i]]);

	if (c1[i] && valid2[i])
		res += 2 * dp(i + 1, sum[h][b2[i]]);

	return mem[i][h] = res % mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(hsh, -1, sizeof(hsh));
	memset(mem, -1, sizeof(mem));
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}

	get({0, 0, 0, 0, 0});
	valid.set(), valid2.set();
	vis[1] = 1;

	for (ii &v : adj[1])
		if (!vis[v.fi]) {
			base[cn] = base2[cn] = vi(5);
			dfs(v.fi, 1, v.se);

			if (valid[cn])
				b1[cn] = get(base[cn]);

			if (c1[cn] && valid2[cn])
				b2[cn] = get(base2[cn]);

			cn++;
		}

	for (int i = 0; i < v.size(); i++) {
		int x = get(v[i]);

		for (int j = 0; j < v.size(); j++) {
			int y = get(v[j]);

			vi aux = v[i];
			int f = 1;
			for (int k : v[j])
				if (k)
					f &= add(aux, k);

			if (f) s get(aux);
			else s -1;
		}
	}

	cout << dp(0, 0) << endl;

	return 0;
}