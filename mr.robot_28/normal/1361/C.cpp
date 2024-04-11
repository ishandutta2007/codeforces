#include<bits/stdc++.h>
using namespace std;
vector <vector <pair <int, int> > > g;
vector <int> iter;
vector <bool> used;
vector <int> path;
vector <int> used1;
int n;
void dfs1(int v)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(!used[to])
		{
			dfs1(to);
		}
	}
}
void dfs(int v)
{
	while(iter[v] < g[v].size())
	{
		while(iter[v] < g[v].size() && used1[g[v][iter[v]].second])
		{
			used1[g[v][iter[v]].second]--;
			iter[v]++;
		}
		if(iter[v] == g[v].size()){
			break;
		}
		used1[g[v][iter[v]].second]++;
		used1[(g[v][iter[v]].second + n) % (2 * n)]++;
		int k = iter[v];
		dfs(g[v][iter[v]].first);
		path.push_back(g[v][k].first);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	iter.resize((1 << 20));
	used.resize((1 << 20));
	g.resize((1 << 20));
	used1.resize(2 * n);
	vector <pair <int, int> > a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	int ans = 0;
	for(int i = 20; i >= 0; i--)
	{
		for(int j = 0; j < n; j++)
		{
			int from = (a[j].first & ((1 << (i)) - 1));
			int to = (a[j].second & ((1 << i) - 1));
			g[from].push_back({to, j + 1});
			g[to].push_back({from, -(j + 1)});
		}
		dfs1(a[0].first & ((1 << i) - 1));
		bool flag = true;
		for(int j = 0; j < n; j++)
		{
			int from = a[j].first & ((1 << (i)) - 1);
			int to = a[j].second & ((1 << i) - 1);
			if(!used[to] || !used[from]){
				flag = false;
			}
		}
		for(int j = 0; j < (1 << 20); j++)
		{
			if((g[j].size()) % 2 == 1)
			{
				flag = false;
				break;
			}
		}
		for(int j = 0; j < (1 << 20); j++)
		{
			used[j] = false;
			g[j].clear();
		}
		if(flag)
		{
			ans = i;
			break;
		}
	}
	set <pair <pair <int, int> , int> > st;
	set <pair <pair <int, int>, int > > newst;
	for(int i = 0; i < n; i++)
	{
		int from = a[i].first & ((1 << ans) - 1);
		int to = a[i].second & ((1 << ans) - 1);
		newst.insert({{from, to}, i});
		newst.insert({{to, from}, i + n});
		g[from].push_back({to, i});
		g[to].push_back({from, i + n});
	}
	dfs(a[0].first & ((1 << ans) - 1));
	cout << ans << "\n";
	path.push_back(path[0]);
	for(int i = 0; i < path.size() - 1; i++)
	{
		set <pair <pair <int, int>, int> > :: iterator it = newst.lower_bound({{path[i], path[i + 1]}, 0});
		int ind = it -> second;
		if(ind >= n)
		{
			ind -=n;
			cout << ind* 2 + 2 << " " << ind * 2 + 1 << " ";
		}
		else
		{
			cout << ind * 2 + 1 << " " << ind * 2 + 2 << " " ;
		}
		pair <pair <int, int>, int> v1 = *it;
		pair <pair <int, int>, int> v2 = make_pair(make_pair(v1.first.second, v1.first.first), (v1.second + n) % (2 * n));
		newst.erase(v1);
		newst.erase(v2);
	}
    return 0;
}