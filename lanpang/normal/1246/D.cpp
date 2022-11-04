#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> G[N];

int p[N], d[N], son[N], go[N];

int n;

void dfs(int u)
{
	d[u] = 0, go[u] = u;
	for (auto v : G[u])
	{
		dfs(v);
		d[u] = max(d[u], d[v] + 1);
		if (d[v] > d[son[u]])
		{
			son[u] = v;
			go[u] = go[v];
		}
	}
}

vector<int> res, id;

void dfs2(int u)
{
	id.push_back(u);
	if (G[u].size() == 0)
		return;
	sort(G[u].begin(), G[u].end(), [](int i, int j) -> bool {
		return d[i] > d[j];
	});
	int sz = G[u].size();
	int last = G[u][0];
	for (int i = 1; i < sz; i++)
	{
		int v = G[u][i];
		for (int j = 1; j <= d[v] + 1; j++)
			res.push_back(last);
		last = v;
	}
	reverse(G[u].begin(), G[u].end());
	for (auto v : G[u])
	{
		dfs2(v);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cin >> p[i]; ++p[i];
		G[p[i]].push_back(i);
	}
	dfs(1);
	dfs2(1);
	for (auto x : id)
		cout << x - 1 << " ";
	cout << endl;
	cout << res.size() << endl;
	reverse(res.begin(), res.end());
	for (auto x : res)
		cout << x - 1 << " ";
	cout << endl;
	return 0;	
}