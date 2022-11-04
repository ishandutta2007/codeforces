#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, m, a, b, p[505];
vvi adj;

vi vis, bs;
bool dfs2 (int u) {
	bs[u] = 1;

	for (int v : adj[u]) {
		if (u == a && v == b)
			continue;
		if (bs[v] == 1)
			return 0;
		if (!bs[v])
			if (!dfs2(v))
				return 0;
	}

	bs[u] = 2;
	return 1;
}

void dfs (int u) {
	vis[u] = 1;

	for (int v : adj[u]) {
		if (vis[v] == 1) {
			p[v] = u;
			b = v;

			while (p[b] != -1) {
				bool res = 1;
				a = p[b];
				bs = vi(n+1);
				
				for (int i = 1; i <= n; i++)
					res &= bs[i] || dfs2(i);
				b = a;

				if (res) {
					cout << "YES" << endl;
					exit(0);
				}

				if (a == v)
					break;
			}

			cout << "NO" << endl;
			exit(0);
		} else if (!vis[v]) {
			p[v] = u;
			dfs(v);
		}
	}

	vis[u] = 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	adj = vvi(n+1);

	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	fill(p+1, p+n+1, -1);
	vis = vi(n+1);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	cout << "YES" << endl;

	return 0;
}