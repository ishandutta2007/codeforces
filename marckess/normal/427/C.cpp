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

int n, m, u, v, c[100005];
ll mn = 0, res = 1;
vvi adj;

vi num, low, s, vis;
int nc = 0;

void tarjanSCC (int u) {
	low[u] = num[u] = ++nc;
	s.push_back(u);

	vis[u] = 1;

	for (int v : adj[u]) {
		if (num[v] == -1)
			tarjanSCC(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u]) {
		int pm = 2e9, pr = 0;
		while (1) {
			int v = s.back();
			s.pop_back();
			vis[v] = 0;

			if (c[v] < pm) {
				pm = c[v];
				pr = 1;
			} else if (c[v] == pm) {
				pr++;
			}

			if (u == v)
				break;
		}

		mn += pm;
		res *= pr;
		res %= int(1e9+7);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	adj = vvi(n+1);
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	cin >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	num = low = vi(n+1, -1), vis = vi(n+1);

	for (int i = 1; i <= n; i++)
		if (num[i] == -1)
			tarjanSCC(i);

	cout << mn << " " << res << endl;

	return 0;
}