#include<bits/stdc++.h>
 
using namespace std;

signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > g(n);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector <bool> used(n);
	for(int i = 0; i < n; i++)
	{
		if(used[i])
		{
			continue;
		}
		vector <int> mass;
		queue <int> q;
		q.push(i);
		used[i] = 1;
		while(q.size() != 0)
		{
			int v = q.front();
			q.pop();
			mass.push_back(v);
			for(int j = 0; j < g[v].size(); j++)
			{
				int to = g[v][j];
				if(!used[to])
				{
					used[to] = 1;
					q.push(to);
				}
			}
		}
		for(int j = 0; j < mass.size(); j++)
		{
			if(g[mass[j]].size() != mass.size() - 1)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}