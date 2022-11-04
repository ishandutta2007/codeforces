#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, m, a, b, q, mx[300005];
ll acu[300005];
vvi adj;

int maxi, mini, p[300005];
void ciclo (int u, int v) {
	if (v == u)
		return;

	maxi = max(u, maxi);
	mini = min(u, mini);
	ciclo(p[u], v);
}

vi vis;
void dfs (int u) {
	vis[u] = 1;

	for (int v : adj[u]) {
		if (vis[v]) {
			if (vis[v] == 1 && v != p[u]) {
				maxi = mini = v;
				ciclo(u, v);
				mx[mini] = min(mx[mini], maxi - 1);
			}
		} else {
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
		adj[b].push_back(a);
	}

	vis = vi(n+1);
	fill(mx, mx+n+1, n);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			p[i] = i;
			dfs(i);
		}
	}
	for (int i = n - 1; i; i--)
		mx[i] = min(mx[i], mx[i+1]);

	acu[0] = 0;
	for (int i = 1; i <= n; i++)
		acu[i] = acu[i-1] + mx[i] - i + 1; 

	cin >> q;
	while (q--) {
		cin >> a >> b;

		ll x = lower_bound(mx+1, mx+n+1, b) - mx;

		if (x < a) {
			x = b - a + 1;
			cout << x * (x + 1) / 2 << endl;
		} else {
			ll d = b - x + 1;
			cout << d * (d + 1) / 2 + acu[x-1] - acu[a-1] << endl;
		}
	}

	return 0;
}