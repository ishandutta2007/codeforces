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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, m, n1, n2, n3, mem[MX][MX], vis[MX], c[MX], x, y, op[MX], from[MX];
vi adj[MX], a, b;

bool dfs (int u, int s) {
	vis[u] = 1;
	if (c[u]) y++;
	else x++;
	from[u] = s;

	for (int v : adj[u]) {
		if (vis[v]) {
			if (c[u] == c[v]) return 0;
			continue;
		}
		c[v] = 1 - c[u];
		if (!dfs(v, s)) return 0;
	}

	return 1;
}

int dp (int i, int j) {
	if (j < 0) return 0;
	if (i == a.size()) return j == 0;

	int &res = mem[i][j];
	if (res != -1) return res;

	return res = dp(i + 1, j - a[i]) | dp(i + 1, j - b[i]);
}

void rec (int i, int j) {
	if (i == a.size()) return;

	if (dp(i + 1, j - a[i])) return rec(i + 1, j - a[i]);

	op[i] = 1;
	rec(i + 1, j - b[i]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem, -1, sizeof(mem));

	cin >> n >> m >> n1 >> n2 >> n3;
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) 
		if (!vis[i]) {
			x = y = 0;
			if (!dfs(i, a.size())) {
				cout << "NO" << endl;
				return 0;
			}
			a.pb(x);
			b.pb(y);
		}

	if (!dp(0, n2)) {
		cout << "NO" << endl;
		return 0;
	}

	rec(0, n2);

	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		if (c[i] == op[from[i]]) cout << 2;
		else {
			if (n1) {
				cout << 1;
				n1--;
			} else {
				cout << 3;
				n3--;
			}
		}
	}
	assert(!n1 && !n3);
	cout << endl;

	return 0;
}