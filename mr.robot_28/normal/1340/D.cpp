#include<bits/stdc++.h>
using namespace std;
vector <pair <int, int> > ans;
vector <vector <int> > g;
int maxcount = 0;
void dfs(int v, int &time, int predtime = -1, int p = -1)
{
	ans.push_back({v, time});
	int cnt = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != p)
		{
			cnt++;
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		if(time == maxcount)
		{
			time = predtime - 1 - cnt;
			ans.push_back({v, time});
		}
		time++;
		dfs(to, time, time, v);
		ans.push_back({v, time});
		cnt--;
	}
	if(p != -1)
	{
		if(time >= predtime)
		{
			time = predtime - 1;
			ans.push_back({v, time});
		}
	}
	time++;
}
signed main() 
{	
	int n;
	cin >> n;
	g.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
		maxcount = max(maxcount, int(g[a].size()));
		maxcount = max(maxcount, int(g[b].size()));
	}
	int time = 0;
	dfs(0, time);
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first + 1 << " " << ans[i].second << "\n";
	}
    return 0;
}