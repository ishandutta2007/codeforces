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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, c[MX], a[MX], d[MX], vis[MX];
ll res = 0;

int mn (int u) {
	if (vis[u] == 2) return 1e9;
	vis[u] = 2;
	c[u] = min(c[u], mn(a[u]));
	return c[u];
}

int dfs (int u) {
	if (vis[u] == 2) return 0;
	if (vis[u] == 1) {
		vis[u] = 2;
		c[u] = min(c[u], mn(a[u]));
		return c[u];
	}

	vis[u] = 1;
	c[u] = dfs(a[u]);
	vis[u] = 2;
	return c[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; a[i]--, i++) cin >> a[i];

	for (int i = 0; i < n; i++)
		if (!vis[i]) res += dfs(i);
	cout << res << endl;

	return 0;
}