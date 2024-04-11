#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> s, ans;
int sum = 0;
void dfs(int v, int p = -1)
{
	if(s[v] == -1)
	{
		int m = 1e9 + 1;
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			m = min(m, s[to] - s[p]);
		}
		if(m == 1e9 + 1)
		{
			ans[v] = 0;
		}
		else if(m < 0)
		{
			cout << -1;
			exit(0);
		}
		else
		{
			ans[v] = m;
			s[v] = s[p] + ans[v];
		}
	}
	else
	{
		if(v == 0)
		{
			ans[v] = s[v];
		}
		else
		{
			ans[v] = s[v] - s[p];
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to, v);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	ans.resize(n);
	g.resize(n);
	s.resize(n);
	for(int i = 1; i < n; i++){
		int p;
		cin >> p;
		p--;
		g[p].push_back(i);
	}
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	dfs(0);
	for(int i = 0; i < n; i++){
		sum += ans[i];
	}
	cout << sum;
    return 0;
}