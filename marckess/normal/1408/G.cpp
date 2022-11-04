#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 1505, mod = 998244353;
int n, mem[MX][MX], cn, inv[MX];
int p[MX], sz[MX], ed[MX], rk[MX];
ii in[MX * MX];
vi pos[MX], tree[MX];

int parent (int a) {
	while (a != p[a]) a = p[a];
	return a;
}

bool valid (int a) {
	a = parent(a);
	return ed[a] == sz[a] * (sz[a] - 1) / 2;
}

void join (int a, int b) {
	a = parent(a), b = parent(b);

	if (a == b) {
		ed[a]++;

		if (valid(a))
			pos[a].pb(sz[a]);
		
		return;
	}

	if (rk[a] < rk[b]) swap(a, b);
	if (rk[a] == rk[b]) rk[a]++;

	sz[a] += sz[b];
	ed[a] += ed[b] + 1;

	p[b] = a;
	tree[a].pb(b);

	if (valid(a))
		pos[a].pb(sz[a]);
}

void dfs (int u) {
	inv[++cn] = u;

	for (int v : tree[u])
		dfs(v);
}

int dp (int i, int j) {
	if (i > n) return j == 0;
	if (j < 0) return 0;

	int &res = mem[i][j];
	if (res != -1) return res;

	res = dp(i + 1, j - 1);

	for (int k : pos[inv[i]]) {
		res += dp(i + k, j - 1);
		if (res >= mod) res -= mod;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	memset(mem, -1, sizeof(mem));

	cin >> n;

	forn (i, n) forn (j, n) {
		int a;
		cin >> a;

		in[a] = {i, j};

		p[i] = i;
		sz[i] = 1;
 	}

 	for (int i = 1; i <= n * (n - 1) / 2; i++)
 		join(in[i].fi, in[i].se);

 	cn = 0;
 	dfs(parent(1));

 	for (int i = 1; i <= n; i++)
 		cout << dp(1, i) << " ";
 	cout << endl;

	return 0;
}