#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;

int t, n;
vector<int> adj[MX];

int dp[MX][2];
int root;

void dfs(int u, int p) {
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);

	// base case
	if (adj[u].size() == 1) {
		dp[u][1] = 0;
		dp[u][0] = 1;
		return;
	}

	dp[u][0] = 0;
	dp[u][1] = 0;
	// default case
	for (int i=0; i<2; i++) {
		int tot0=0, tot1=0, totb=0;
		for (int v : adj[u]) {
			if (v == p) continue;
			if (!dp[v][0] && !dp[v][1]) return;
			if ( dp[v][0] &&  dp[v][1]) totb++;
			if (!dp[v][0] &&  dp[v][1]) tot1++;
			if ( dp[v][0] && !dp[v][1]) tot0++;
		}
		if (i == 0) tot0++;
		else        tot1++;
		int cur = 0;
		while(tot0 + tot1 + totb) {
			if (cur) {
				if (tot1) tot1--;
				else if (totb) totb--;
				else break;
			} else {
				if (tot0) tot0--;
				else if (totb) totb--;
				else break;
			}
			cur ^= 1;
		}
		dp[u][i] = (tot0 + tot1 + totb == 0);
	}
}

vector<pair<int,int>> ans;
void findSequence(int u, int p, int i) {
	if (adj[u].size() == 1) {
		ans.push_back({u,p});
		return;
	}
	vector<int> tot0, tot1, totb;
	for (int v : adj[u]) {
		if (v == p) continue;
		assert(dp[v][0] || dp[v][1]);
		if ( dp[v][0] &&  dp[v][1]) totb.push_back(v);
		if (!dp[v][0] &&  dp[v][1]) tot1.push_back(v);
		if ( dp[v][0] && !dp[v][1]) tot0.push_back(v);
	}
	if (i == 0) tot0.push_back(u);
	else        tot1.push_back(u);
	int cur = 0;
	auto createEdge = [=](int v, int j) {
		if (v == u) ans.push_back({u,p});
		else findSequence(v, u, j);
	};
	while(tot0.size() + tot1.size() + totb.size()) {
		if (cur) {
			if (tot1.size()) {
				createEdge(tot1.back(), cur);
				tot1.pop_back();
			} else {
				createEdge(totb.back(), cur);
				totb.pop_back();
			}
		} else {
			if (tot0.size()) {
				createEdge(tot0.back(), cur);
				tot0.pop_back();
			} else {
				createEdge(totb.back(), cur);
				totb.pop_back();
			}
		}
		cur ^= 1;
	}
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i=1; i<=n; i++)
			adj[i].clear();
		for (int i=0; i<n-1; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i=1; i<=n; i++)
			if (adj[i].size() == 1)
				root = i;
		dfs(adj[root][0], root);
		if (dp[adj[root][0]][0]) {
			cout << "YES" << endl;
			findSequence(adj[root][0], root, 0);
			reverse(ans.begin(), ans.end());
			for (auto p : ans)
				cout << p.first << " " << p.second << endl;
			ans.clear();
		} else cout << "NO" << endl;
	}
}