#include <bits/stdc++.h>

#define endl '\n'
#define forn(i,n) for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MX = 100005;
int n, a[MX];
vi adj[MX];

void dfs (int u, int p, int s) {
	a[u] = s * (int)adj[u].size();

	for (int v : adj[u])
		if (v != p)
			dfs(v, u, -s);
}

void main_ () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 1, 1);

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main () {

	int t;
	cin >> t;
	while (t--)
		main_();
	
    return 0;
}