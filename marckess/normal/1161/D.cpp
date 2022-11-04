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

const int MX = 2005, mod = 998244353;
int n, vis[MX], res = 0, f, k, p[MX], c[MX];
string s;
vi adj[MX];

void init () { iota(p, p+MX, 0); }
int parent (int a) { return p[a] == a ? a : p[a] = parent(p[a]); }
void join (int a, int b) { p[parent(a)] = parent(b); }
void add (int a, int b) { a = parent(a), b = parent(b); adj[a].pb(b), adj[b].pb(a); }

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p >>= 1; 
	}
	return res;
}

void dfs (int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (!vis[v]) {
			c[v] = 1 - c[u];
			dfs(v);
		} else if (c[u] == c[v]) {
			f = 0;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();
	reverse(all(s));

	for (int i = 1; i < n; i++) {
		init();

		join(n - 1, n + i + 1);
		join(n + i - 1, n + i + 1);
		for (int j = 0; j < n; j++)
			join(j, n - j - 1);
		for (int j = 0; j < i; j++) {
			if (s[j] == '0') join(j, n + j);
			join(n + j, n + i - j - 1);
		}

		add(n + i, n + i + 1);
		for (int j = 0; j < n; j++) {
			if (s[j] == '0')
				if (j >= i) add(j, n + i + 1);
			if (s[j] == '1') {
				if (j >= i) add(j, n + i);
				else add(j, n + j);
			}
		}

		k = 0;
		f = 1;
		memset(vis, 0, sizeof(vis));
		for (int j = 0; j <= n + i + 1; j++)
			if (!vis[parent(j)]) {
				k++;
				dfs(parent(j));
			}

		(res += f * pot(2, k - 1)) %= mod;

		for (int j = 0; j <= n + i + 1; j++)
			adj[j].clear();
	}

	cout << res << endl;

	return 0;
}