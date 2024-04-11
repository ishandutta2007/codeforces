#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll E = (ll)1e9 + 7;
const int N = 200100;

vector<int> g[N];
int c[N], f[N], ans;

void dfs(int v, int e = 0)
{
	if (e != c[v])
		ans++;
	f[v] = c[v];
	for (int u : g[v])
		if (!f[u])
			dfs(u, c[v]);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}