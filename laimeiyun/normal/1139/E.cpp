#include <bits/stdc++.h>

using namespace std;

#define N 5555

int n, m, d;
int p[N], c[N], l[N], q[N], answer[N];
bool leave[N], vis[N];
vector<int> adj[N];

void init()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++)
		cin >> c[i];

	for (int i = 1; i <= m; i++)
		l[i] = -1;

	cin >> d;
	for (int i = 1; i <= d; i++)
	{
		cin >> q[i];
		leave[q[i]] = 1;
	}
}

bool dfs(int u)
{
	if (vis[u])
		return 0;
	vis[u] = 1;
	for (auto v : adj[u])
	{
		if (l[v] == -1 || dfs(l[v]))
		{
			l[v] = u;
			return 1;
		}
	}
	return 0;
}

void solve()
{

	for (int i = 1; i <= n; i++)
	{
		if (!leave[i])
			adj[p[i]].push_back(c[i]);
	}

	int mex = -1;
	for (int i = d; i >= 1; i--)
	{

		while (true)
		{
			memset(vis, 0, sizeof vis);
			if (!dfs(mex + 1))
				break;
			mex += 1;
		}
		answer[i] = mex + 1;

		adj[p[q[i]]].push_back(c[q[i]]);
	}

	for (int i = 1; i <= d; i++)
		cout << answer[i] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();

	return 0;
}