#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
vector <vector <int> > g;
vector <pair <int, int> > mass;
vector <map <int, int> > st;
vector <int> iter;
void dfs(int v)
{
	for(int j = 0; j < g[v].size(); j++)
	{
		dfs(g[v][j]);
	}
	if(g[v].size() == 0)
	{
		st[v][0] = 0;
		st[v][mass[v].first] = mass[v].second;
		iter[v] = v;
		return;
	}
	iter[v] = iter[g[v][0]];
	for(int i = 1; i < g[v].size(); i++)
	{
		map <int, int> :: iterator it;
		for(it = st[iter[g[v][i]]].begin(); it != st[iter[g[v][i]]].end(); it++)
		{
			st[iter[v]][it -> first] += it -> second;
		}
	}
	if(mass[v].first != 0)
	{
		st[iter[v]][mass[v].first] += mass[v].second;
		map <int, int> :: iterator it;
		it = st[iter[v]].upper_bound(mass[v].first);
		int sum = 0;
		stack <int> del;
		while(it !=  st[iter[v]].end())
		{
			sum += it -> second;
			if(sum >= mass[v].second)
			{
				st[iter[v]][it -> first] = sum - mass[v].second;
				break;
			}
			del.push(it -> first);
			it++;
		}
		while(del.size() > 0)
		{
			st[iter[v]].erase(del.top());
			del.pop();
		}
	}
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	g.resize(n);
	iter.resize(n);
	st.resize(n);
	mass.resize(n, {0, 0});
	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		g[p].push_back(i);
	}
	for(int i = 0; i < m; i++)
	{
		int u,d, w;
		cin >> u >> d >> w;
		u--;
		mass[u] = {d, w};
	}
	dfs(0);
	int ans = 0, sum = 0;
	map <int, int> :: iterator it;
	for(it = st[iter[0]].begin(); it != st[iter[0]].end(); it++)
	{
		sum += it -> second;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}