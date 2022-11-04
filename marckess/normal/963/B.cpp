#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, p;
vi adj[200005];
queue<int> q;
vi vis(2e5+5);

void dfs (int u, int p) {
	vis[u] = 1;

	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u);
			vis[u] ^= vis[v];
		}
	}
}

void obtRes (int u, int p) {
	for (int v : adj[u])
		if (v != p && !vis[v])
			obtRes(v, u);

	cout << u << endl;

	for (int v : adj[u])
		if (v != p && vis[v])
			obtRes(v, u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p;

		if (p) {
			adj[i].push_back(p);
			adj[p].push_back(i);
		}
	} 

	dfs(1, -1);

	if (!vis[1]) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		obtRes(1, -1);
	}

	return 0;
}