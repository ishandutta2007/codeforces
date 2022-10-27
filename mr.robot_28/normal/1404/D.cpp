#include<bits/stdc++.h>
using namespace std;
vector <int> p;
vector <vector <int> > g;
vector <int> mass2, mass1;
vector <bool> used;
long long sum = 0;
void dfs(int x)
{
	sum += x;
	mass1.push_back(x);
	used[x] = 1;
	for(int i = 0; i < g[x].size(); i++)
	{
		int to = g[x][i];
		if(!used[to])
		{
			mass2.push_back(to);
				used[to] = 1;
			int to1 = -1;
			for(int j = 0; j < g[to].size(); j++)
			{
				if(!used[g[to][j]])
				{
					to1 = g[to][j];
				}
			}
			if(to1 != -1)
			{
				dfs(to1);
			}
		}
	}
}
signed main()
{
	int n;
	cin >> n;
	p.resize(n * 2 + 1);
	g.resize(2 * n + 1);
	used.resize(2 * n + 1);
	if(n % 2 == 1)
	{
		cout << "Second";
		cout << endl;
		fflush(stdout);
		for(int i = 1; i <= n * 2; i++)
		{
			int x;
			cin >> x;
			if(p[x])
			{
				g[p[x]].push_back(i);
				g[i].push_back(p[x]);
			}
			else
			{
				p[x] = i;
			}
		}
		for(int i = 1; i <= n;i++)
		{
			g[i + n].push_back(i);
			g[i].push_back(i + n);
		}
		for(int i = 1; i <= n; i++)
		{
			if(!used[i])
			{
				dfs(i);
			}
		}
		if(sum % (2 * n) != 0)
		{
			swap(mass1, mass2);
		}
		for(int i = 0; i < mass1.size(); i++)
		{
			cout << mass1[i] << " ";
		}
		cout << endl;
		fflush(stdout);
	}
	else
	{
		cout << "First";
		cout << endl;
		fflush(stdout);
		for(int i = 0; i < 2 * n; i++)
		{
			cout << (i % n) + 1 << " ";
		}
		int res;
		cin >> res;
	}
	return 0;
}