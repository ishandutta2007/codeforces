#include <bits/stdc++.h>
 
using namespace std;
vector <vector <int> > g;
vector <int> used;
vector <int> cycle;
vector <int> pred;
bool flag;
void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(used[to] == 1)
		{
			if(!flag)
			{
				int k = v;
				while(k != to)
				{
					cycle.push_back(k + 1);
					k = pred[k];
				}
				cycle.push_back(to + 1);
				flag = true;
			}
		}
		else if(used[to] == 0)
		{
			pred[to] = v;
			dfs(to);
		}
	}
	used[v] = 2;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		flag = false;
		int n;
		cin >> n;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			A[i] = i - A[i];
		}
		pred.resize(n);
		used.resize(n);
		g.resize(n);
		for(int i = 0; i < n; i++)
		{
			g[A[i]].push_back(i);
		}
		for(int i = 0; i < n; i++)
		{
			if(used[i] == 0)
			{
				dfs(i);
			}
		}
		cout << cycle.size() << "\n";
		for(int i = 0; i < cycle.size(); i++)
		{
			cout << cycle[i] << " ";
		}
		cout << "\n";
		cycle.clear();
		g.clear();
		used.clear();
		pred.clear();
	}
    return 0;
}