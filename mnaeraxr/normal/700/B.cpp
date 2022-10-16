#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

vi adj[maxn];

int children[maxn];
int64 sumup[maxn];
int deg[maxn];

int height[maxn];
bool dead[maxn];
bool univ[maxn];

void dfs(int s, int f = -1){
	if (univ[s]) ++children[s];

	for (auto u : adj[s]) if (u != f){
		height[u] = height[s] + 1;
		dfs(u, s);
		children[s] += children[u];
		sumup[s] += children[u] + sumup[u];
	}
}

void kill(int u){
	dead[u] = true;
	for (auto v : adj[u]) if (!dead[v])
		kill(v);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	k *= 2;

	for (int i = 0; i < k; ++i){
		int v; cin >> v;
		univ[v] = true;
	}

	for (int i = 1; i < n; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

		deg[u]++; deg[v]++;
	}

	dfs(1);

	int64 ans = 0;
	int tot = k;
	int c = 1;

	while (c != -1){
		int m = -1;
		for (auto u : adj[c]) if (!dead[u]){
			if (children[u] * 2 > tot){
				m = u;
				break;
			}
		}

		if (m == -1){
			ans += sumup[c];
		}
		else{
			int need = tot - children[m];
			ans += sumup[c] - sumup[m] - children[m] + need;

			dead[c] = true;

			for (auto u : adj[c]) if (u != m && !dead[u])
				kill(u);
		}

		c = m;
	}

	cout << ans << endl;

	return 0;
}