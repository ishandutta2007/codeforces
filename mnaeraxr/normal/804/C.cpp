#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 300000 + 10;

int color[ maxn ];
vector<int> value[ maxn ];
vector<int> adj[ maxn ];
int answer = 1;

void dfs(int s, int p){	
	vector<bool> used( value[s].size() + 1 );
	for (auto u : value[s]){
		if (color[u] && color[u] <= (int)value[s].size())
			used[ color[u] ] = true;
	}

	int par = 1;

	for (auto u : value[s]){
		if (!color[u]){
			while (used[par]) par++;
			color[u] = par;
			used[par] = true;
		}
	}

	for (auto x : adj[s]) if (x != p){
		dfs(x, s);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i){
		int t; cin >> t;
		value[i] = vi(t);
		answer = max(answer, t);
		for (int j = 0; j < t; ++j)
			cin >> value[i][j];
	}
	for (int i = 0; i + 1 < n; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);

	cout << answer << endl;

	for (int i = 1; i <= m; ++i)
		cout << max(color[i], 1) << " ";
	cout << endl;

	return 0;
}