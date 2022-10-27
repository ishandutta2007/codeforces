#include<bits/stdc++.h>
using namespace std;

signed main() {	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int m, k;
	cin >> m >> k;
	vector <int> index;
	vector <vector <int> > g;
	vector <pair <int, int> > mass(m);
	vector <int> uniq;
	for(int i = 0; i < m; i++)
	{
		cin >> mass[i].first >> mass[i].second;
		uniq.push_back(mass[i].first);
		uniq.push_back(mass[i].second);
	}
	sort(uniq.begin(), uniq.end());
	int n = unique(uniq.begin(), uniq.end()) - uniq.begin();
	g.resize(n);
	vector <vector <int> > ans(n);
	for(int i = 0; i < m; i++)
	{
		mass[i].first = lower_bound(uniq.begin(), uniq.begin() + n, mass[i].first) - uniq.begin();
		mass[i].second = lower_bound(uniq.begin(), uniq.begin() + n, mass[i].second) - uniq.begin();
		g[mass[i].first].push_back(mass[i].second);
		g[mass[i].second].push_back(mass[i].first);
	}
	vector <bool> used(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < g[i].size(); j++)
		{
			used[g[i][j]] = 1;
		}
		vector <int> vec;
		for(int j = 0; j < n; j++)
		{
			if(j == i || used[j])
			{
				continue;
			}
			int cnt = 0;
			for(int w = 0; w < g[j].size(); w++)
			{
				if(used[g[j][w]])
				{
					cnt++;
				}
			}
			if(cnt * 100 >= k * (g[i].size()))
			{
				vec.push_back(j);
			}
		}
		cout << uniq[i] << ": " << vec.size() << " ";
		for(int j = 0; j < vec.size(); j++)
		{
			cout << uniq[vec[j]] << " ";
		}
		cout << "\n";
		for(int j =0; j < g[i].size(); j++)
		{
			used[g[i][j]] = 0;
		}
	}
    return 0;
}