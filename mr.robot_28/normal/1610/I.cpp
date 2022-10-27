#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define sz(a) (int)a.size()

const int N = 3e5 + 100;
vector <int> g[N];
int dead[N];
int dp[N];
int pred[N];
int n;

void dfs(int v, int p = -1) {
	for (auto to : g[v]) {
		if (to == p) {
			continue;
		}
		pred[to] = v;
		dfs(to, v);
		dp[v] ^= (dp[to] + 1);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		v--;
		u--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	int ans = dp[0];
	cout << 1 + (ans == 0);
	dead[0] = 1;
	for (int i = 1; i < n; i++) {
		vector <int> vec;
		int v = i;
		while (!dead[v]) {
			vec.push_back(v);
			dead[v] = 1;
			v = pred[v];
		}
		reverse(vec.begin(), vec.end());
		for (auto v : vec) {
			ans ^= dp[v] + 1;
			ans ^= dp[v];
			ans ^= 1;
		}
		cout<< 1 + (ans == 0);
	}
	cout << "\n";
	return 0;
}