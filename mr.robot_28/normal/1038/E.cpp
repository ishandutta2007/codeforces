#include <bits/stdc++.h>
using namespace std;
vector <vector <pair <int, int > > > g(4);
vector <int> tin(4), fup(4);
int timer = 0;
vector <bool> used;
void dfs(int v, int p = -1)
{
	timer++;
	tin[v] = timer;
	fup[v] = tin[v];
	for(int i = 0;  i< g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(g[v][i].second == p)
		{
			continue;
		}
		if(tin[to])
		{
			fup[v] = min(fup[v], tin[to]);
			continue;
		}
		dfs(to, g[v][i].second);
		if(fup[to] >= tin[v])
		{
			used[g[v][i].second] = true;
		}
		fup[v] = min(fup[v], fup[to]);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <int, int> > col(n);
	vector <int> val(n);
	vector <int> cnt(4);
	int ans = 1e9;
	int sum = 0;
	vector <int> colored(4);
	used.resize(n);
	for(int i = 0; i < 4; i++)
	{
		colored[i] = i;
	}
	vector <vector <int> > coun(4, vector <int> (4));
	for(int i = 0; i < n; i++)
	{
		cin >> col[i].first >> val[i] >> col[i].second;
		col[i].first--;
		col[i].second--;
		coun[col[i].first][col[i].second]++;
		coun[col[i].second][col[i].first]++;
		g[col[i].first].push_back({col[i].second, i});
		g[col[i].second].push_back({col[i].first, i});
		int c = colored[col[i].second];
		for(int j = 0; j < 4; j++)
		{
			if(colored[j] == c)
			{
				colored[j] = colored[col[i].first];
			}
		}
		sum += val[i];
		cnt[col[i].first]++;
		cnt[col[i].second]++;
	}
	int cnt1 = 0;
	for(int j = 0; j < 4; j++)
	{
		if(colored[j] == colored[0])
		{
			cnt1++;
		}
	}
	if(cnt1 == 4)
	{
		dfs(0);
		int p = 0;
		for(int i = 0; i < n; i++)
		{
			if(col[i].first == col[i].second)
			{
				continue;
			}
			if(coun[col[i].first][col[i].second] > 1){
				used[i] = false;
			}
			if(cnt[col[i].first] == 1 || cnt[col[i].second] == 1 || !used[i])
			{
				ans = min(ans, val[i]);
			}
		}
		for(int i = 0; i < 4; i++)
		{
			p += cnt[i] % 2;
		}
		if(p <= 2)
		{
			cout << sum;
		}	
		else
		{
			cout << sum - ans;
		}
	}
	else
	{
		vector <int> maxsum(4);
		for(int i =  0; i < n; i++)
		{
			maxsum[colored[col[i].first]] += val[i];
		}
		ans = 0;
		for(int i = 0; i < 4; i++)
		{
			ans = max(ans, maxsum[i]);
		}
		cout << ans;
	}
	return 0;
}