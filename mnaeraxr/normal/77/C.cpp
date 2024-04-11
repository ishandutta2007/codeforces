#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int total[maxn];
vi adj[maxn];

int64 dfs(int s, int f){
	int64 ans = 0;
	vector<int64> child;

	for (auto u : adj[s]) if (u != f){
		total[u]--;
		child.push_back(dfs(u, s) + 1);
	}

	sort(child.begin(), child.end());

	for (int i = child.size() - 1; i >= 0 && total[s]; --i){
		ans += child[i] + 1;
		total[s]--;
	}

	for (auto u : adj[s]) if (u != f){
		int64 v = min(total[u], total[s]);
		total[s] -= v;
		ans += 2 * v;
		if (!total[s]) break;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i){
		cin >> total[i];
	}

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int s; cin >> s;
	cout << dfs(s, -1) << endl;

	return 0;
}