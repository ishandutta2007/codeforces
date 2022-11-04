#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mod = 998244353;
int n, m, to[99][26], fin[99], sz = 1;
string s[10];
vvi t, res, c;

void insert (string &s) {
	int u = 0;
	
	for (int c : s) {
		c -= 'a';
		
		if (!to[u][c])
			to[u][c] = sz++;
		
		u = to[u][c];
	}
	
	fin[u] = 1;
}

void dfs (int u, int v, int o, int lvl) {
	if (lvl && fin[u] && fin[v]) t[(lvl - 1) * n + 0][o]++;	
	if (lvl && fin[u]) t[(lvl - 1) * n + v][o]++;
	if (lvl && fin[v]) t[(lvl - 1) * n + u][o]++;
		
	forn (c, 26)
		if (to[u][c] && to[v][c])
			dfs(to[u][c], to[v][c], o, lvl + 1);
}

void clear (vvi &v) {
	forn (i, v.size())
		forn (j, v[i].size())
			v[i][j] = 0;
}

void copy (vvi &a, vvi &c) {
	forn (i, a.size())
		forn (j, a[i].size())
			a[i][j] = c[i][j];
}

void mul (vvi &c, vvi &a, vvi &b) {
	clear(c);
	forn (i, a.size())
		forn (j, b[i].size())
			forn (k, b.size())
				(c[i][j] += a[i][k] * b[k][j]) %= mod;
}

void iden (vvi &v) {
	clear(v);
	forn (i, v.size())
		v[i][i] = 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, n) {
		cin >> s[i];
		insert(s[i]);
	}
	
	n = sz;
	t = res = c = vvi(5 * n, vi(5 * n));
	
	forn (i, 4)
		forn (j, n)
			t[i * n + j][(i + 1) * n + j]++;
	
	forn (i, n)
		dfs(0, i, i, 0);
	
	iden(res);
	while (m) {
		if (m & 1) {
			mul(c, t, res);
			copy(res, c);
		}
		
		mul(c, t, t);
		copy(t, c);
		
		m /= 2;
	}
	
	cout << res[0][0] << endl;
	
	return 0;
}