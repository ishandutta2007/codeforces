#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ady;
vector<bool> mk;

void dfs(int a){
	mk[a] = true;
	for (auto v : ady[a])
		if (!mk[v]) dfs(v);
}

int main()
{
	int n, m;
	cin >> n >> m;

	ady = vector<vector<int>>(n + 1);
	mk = vector<bool>(n + 1);

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		ady[u].push_back(v);
		ady[v].push_back(u);
	}

	int cnx = n;

	for (int i = 1; i <= n; ++i){
		if (!mk[i]) {
                      dfs(i);
                      --cnx;
                  }
	}

	cout << (1LL << cnx) << endl;
}