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

int n, m, c[1005], a, b, q[1005];
vvi adj;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	adj = vvi(n+1);
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	iota(q, q+n+1, 0);
	sort(q+1, q+n+1, [&] (int a, int b) {
		return c[a] > c[b];
	});

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int u = q[i];

		for (int x : adj[u])
			res += c[x];
		c[u] = 0;
	}

	cout << res << endl;

	return 0;
}