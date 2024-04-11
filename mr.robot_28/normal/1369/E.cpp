#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <int> w(n);
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	vector <pair <int, int> > a(m);
	vector <bool> used(m), used1(n);
	vector <int> s(n);
	vector <vector <int> > g(n);
	for(int i = 0; i < m; i++)
	{
		cin >> a[i].first >> a[i].second;
		a[i].first--;
		a[i].second--;
		s[a[i].first]++;
		s[a[i].second]++;
		g[a[i].first].push_back(i);
		g[a[i].second].push_back(i);
	}
	vector <int> ans;
	queue <int> Q;
	for(int i = 0; i < n; i++)
	{
		if(s[i] <= w[i])
		{
			Q.push(i);
			used1[i] = true;
		}
	}
	while(Q.size() != 0)
	{
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < g[v].size(); i++)
		{
			int ind = g[v][i];
			if(!used[ind])
			{
				int ind1;
				if(a[ind].first == v)
				{
					ind1 = a[ind].second;
				}
				else
				{
					ind1 = a[ind].first;
				}
				s[ind1]--;
				if(!used1[ind1] && w[ind1] >= s[ind1])
				{
					used1[ind1] = true;
					Q.push(ind1);
				}
				ans.push_back(ind + 1);
				used[ind] = true;
			}
		}
	}
	if(ans.size() < m)
	{
		cout << "DEAD";
		return 0;
	}
	cout << "ALIVE\n";
	for(int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}
	return 0;
}