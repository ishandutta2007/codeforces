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

const int MX = 100005;
int n, m, l, x, vis[MX];
vi s[MX], adj[MX], res;

void no() {
	cout << "No" << endl;
	exit(0);
}

void obtRes (int i, int j, int k) {
	int ant = i;
	
	while (i < j) {
		if (k >= s[i].size()) {
			if (k < s[ant].size())
				obtRes(ant, i, k+1);
			ant = ++i;
		} else {
			i++;
			if (i < j && k < s[i].size() && s[i-1][k] != s[i][k]) {
				obtRes(ant, i, k+1);
				adj[s[i-1][k]].pb(s[i][k]);
				ant = i;
			}
			if (i == j)
				obtRes(ant, i, k+1);
		}
	}
}

void cyc (int u) {
	vis[u] = 1;
	
	
	for (int v : adj[u]) {
		if (vis[v] == 1) no();
		if (!vis[v]) cyc(v);
	}
	
	vis[u] = 2;
}

void dfs (int u) {
	vis[u] = 1;
	
	for (int v : adj[u]) {
		if (!vis[v]) dfs(v);
		if (vis[v] == 1) {
			if (v < u) vis[u] = 2;
		} else {
			if (v < u) no();
			else vis[u] = 2;
		}
	}
	
	if (vis[u] == 2) res.pb(u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> l;
		s[i].resize(l);
		for (int j = 0; j < l; j++)
			cin >> s[i][j];
		s[i].pb(0);
	}
	
	obtRes(0, n, 0);
	
	for (int i = 1; i <= m; i++)
		if (!vis[i])
			cyc(i);
	
	memset(vis, 0, sizeof(vis));
	
	vis[0] = 2;
	for (int i = 1; i <= m; i++)
		if(!vis[i])
			dfs(i);
	
	cout << "Yes\n" << res.size() << endl;
	for (int x : res) cout << x << " ";
	cout << endl;
	
	return 0;
}