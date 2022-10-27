#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> mt;
vector <int> was;
bool dfs(int v, int count){
	if(was[v] == count)
	{
		return false;
	}
	was[v] = count;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(mt[g[v][i]] == -1)
		{
			mt[g[v][i]] = v;
			return true;
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		if(dfs(mt[g[v][i]], count))
		{
			mt[g[v][i]] = v;
			return true;
		}
	}
	return false;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> s;
	vector <pair <int, int> > A;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		A.push_back({a, b});
		s.push_back(a);
		s.push_back(b);
	}
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());
	g.resize(s.size());
	was.resize(s.size());
	for(int i = 0; i < n; i++)
	{
		int i1 = int(lower_bound(s.begin(), s.end(), A[i].first) - s.begin());
		int i2 = lower_bound(s.begin(), s.end(), A[i].second) - s.begin();
		A[i].first = i1;
		A[i].second = i2;
	}
	for(int i = 0; i < n; i++)
	{
		g[A[i].first].push_back(i);
		g[A[i].second].push_back(i);
	}
	mt.resize(n, -1);
	int match = 0;
	set <int> :: iterator it;
	for(int i = 0; i < s.size(); i++)
	{
		if(dfs(i, i + 1))
		{
			++match;
			if(match == n)
			{
				cout << s[i];
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}