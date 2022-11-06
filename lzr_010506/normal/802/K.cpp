#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int inf = 1e15;

int a[100010];

vector <pair <int, int> > e[100010];
int k, vis[100010], tot;

pair <int, int> dfs(int u, int f)
{
	vector <pair <int, int> > v;
	for (int i = 0; i < e[u].size(); i ++)
	{
		pair<int, int> now = e[u][i];
		if (now.X == f) continue;
		pair<int, int> p = dfs(now.X, u);
		int w = p.X + now.Y, z = p.Y + now.Y;
		v.emplace_back(make_pair(w, z));
	}
	sort(v.rbegin(), v.rend());
	pair <int, int> ans;
	for (int i = 0; i < k - 1 && i < v.size(); i ++)
		ans.X += v[i].X;
	for (int i = 0; i < v.size(); i ++)
		if (i < k - 1)
		{
			int w = ans.X + v[i].Y - v[i].X;
			if (k - 1 < v.size()) w += v[k - 1].X;
			ans.Y = max(ans.Y, w);
		}
		else ans.Y = max(ans.Y, ans.X + v[i].Y);
	return ans;
}

int main()
{
	int n;
	scanf("%d %d", &n, &k);
	for (int i = 1; i < n; i ++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}
	cout << dfs(0, -1).Y << endl;
	return 0;

}