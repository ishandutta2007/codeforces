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

const int MX = 1005, mod = 1000000007;
int n, m, x, y, mx = -1e9;
ll res;
vi s[MX], t[MX];

void add (ii &p, int x) {
	if (x > p.fi) {
		p.se = p.fi;
		p.fi = x;
	} else if (x > p.se) {
		p.se = x;
	}
}

ii dfs (int u, int p) {
	ii res(-1, -1);

	for (int v : t[u])
		if (v != p) {
			ii p = dfs(v, u);
			if (p.fi != -1) add(res, p.fi + 1);
		}

	if (res.fi == -1)
		res.fi = 0;

	return res;
}

map<vi, int> mp;
int hsh[MX];
vi ch[MX];

void obtHash (int u, int p) {
	vi res;

	for (int v : t[u])
		if (v != p) {
			obtHash(v, u);
			res.pb(hsh[v]);
		}
	
	sort(all(res));
	if (!mp.count(res)) {
		int sz = mp.size();
		mp[res] = sz;
		ch[sz] = res;
	}

	hsh[u] = mp[res];
}

map<int, int> mem;
ll cn[MX][(1 << 12) + 1];

ll dp (int u, int p, int k) {
	if (!k) return 1;

	int id = MX * MX * u + MX * p + k;
	if (mem.count(id)) return mem[id];
	int &res = mem[id];

	vi &f = ch[k];
	int n = f.size();

	forn (i, (1 << n)) cn[u][i] = 0;
	cn[u][0] = 1;

	int i = 0;
	for (int v : s[u])
		if (v != p)
			for (int mk = (1 << n) - 1; mk >= 0; mk--) 
				forn (j, n) if (!(mk & (1 << j)) && (j == 0 || f[j] != f[j - 1] || (mk & (1 << j - 1))))
					(cn[u][mk | (1 << j)] += cn[u][mk] * dp(v, u, f[j])) %= mod;

	res = cn[u][(1 << n) - 1];
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		s[a].pb(b);
		s[b].pb(a);
	}

	cin >> m;
	forn (i, m - 1) {
		int a, b;
		cin >> a >> b;
		t[a].pb(b);
		t[b].pb(a);
	}

	for (int i = 1; i <= m; i++) {
		ii p = dfs(i, -1);

		if (p.se > mx) {
			mx = p.se;
			x = i;
			y = -1;
		} else if (p.se == mx) {
			y = i;
		}
	}

	mp[{}] = 0;
	obtHash(x, y);
	if (y != -1) obtHash(y, x);

	if (y == -1) {
		for (int u = 1; u <= n; u++)
			(res += dp(u, 0, hsh[x])) %= mod;
	} else {
		for (int u = 1; u <= n; u++)
			for (int v : s[u])
				if (u < v) {
					(res += dp(u, v, hsh[x]) * dp(v, u, hsh[y])) %= mod;
					if (hsh[x] != hsh[y])
						(res += dp(u, v, hsh[y]) * dp(v, u, hsh[x])) %= mod;
				}
	}

	cout << res << endl;

	return 0;
}