
#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <bool> used;
vector <int> x;
void dfs(int v)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(!used[g[v][i]])
		{
			dfs(g[v][i]);
		}
	}
	x.push_back(v);
}
signed main() {
	int n, m;
	cin >> n >> m;
	vector <int> cnt(n);
	g.resize(n);
	used.resize(n, false);
	vector <pair <int, int> > A(m);
	for(int i = 0; i < m; i++)
	{
		cin >> A[i].first >> A[i].second;
		A[i].first--;
		A[i].second--;
		g[A[i].first].push_back(A[i].second);
		cnt[A[i].second]++;
	}
	int ind = -1;
	for(int i = 0; i < n; i++)
	{
		if(cnt[i] == 0)
		{
			if(ind != -1)
			{
				cout << -1;
				return 0;
			}
			ind = i;
		}
	}
	dfs(ind);
	reverse(x.begin(), x.end());
	vector <int> newind(n);
	for(int i = 0; i < n; i++)
	{
		newind[x[i]] = i;
		used[i] = false;
	}
	int allcnt = 0;
	for(int i = 0; i < m; i++)
	{
		int ind1 = newind[A[i].first];
		if(!used[ind1] && ind1 < n - 1 && x[ind1 + 1] == A[i].second)
		{
			used[ind1] = true;
			allcnt++; 
		}
		if(allcnt == n - 1)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}