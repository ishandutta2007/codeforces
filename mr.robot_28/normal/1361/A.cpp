#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> col(n, -1);
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
	for(int i =0; i < n; i++)
	{
		cin >> col[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < g[i].size(); j++)
		{
			if(col[i] == col[g[i][j]])
			{
				cout << -1;
				return 0;
			}
		}
	}
	vector <int> col1(n);
	vector <pair <int, int> > p;
	for(int i = 0; i < n; i++)
	{
		p.push_back({col[i], i});
	}
	sort(p.begin(), p.end());
	for(int i = 0; i < n; i++)
	{
		int v = p[i].second;
		vector <int> vec;
		bool flag = true;
		for(int j = 0; j < g[v].size(); j++)
		{
			vec.push_back(col1[g[v][j]]);
			if(col1[g[v][j]] == 1)
			{
				flag = false;
			}
		}
		if(flag)
		{
			if(col[v] != 1)
			{
				cout << -1;
				return 0;
			}
		}
		else
		{
			sort(vec.begin(), vec.end());
			int a = vec.back() + 1;
			for(int j = 0; j < vec.size() - 1; j++)
			{
				if(vec[j + 1] > vec[j] + 1)
				{
					a = vec[j] + 1;
					break;
				}
			}
			if(a != p[i].first)
			{
				cout << -1;
				return 0;
			}
		}
		col1[v] = p[i].first;
	}
	for(int i = 0; i < n; i++)
	{
		cout << p[i].second + 1 << " ";
	}
    return 0;
}