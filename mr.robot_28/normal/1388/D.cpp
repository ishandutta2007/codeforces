#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> dp;
int ans = 0;
vector <int> a;
vector <int> st1, end1;
void dfs(int v)
{
	dp[v] = a[v];
	for(int i = 0; i< g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
		if(dp[to] >= 0)
		{
			st1.push_back(to);
			dp[v] += dp[to];
		}
		else
		{
			end1.push_back(to);
		}
	}
	ans += dp[v];
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp.resize(n);
	g.resize(n);
	a.resize(n);
	vector <int> b(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
		b[i]--;
		if(b[i] != -2)
		{
			g[b[i]].push_back(i);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(b[i] == -2)
		{
			dfs(i);
			st1.push_back(i);
		}
	}
	cout << ans << "\n";
	for(int i = 0; i < st1.size(); i++)
	{
		cout << st1[i] + 1 << " ";
 	}
 	if(end1.size() != 0)
 	{
 	for(int i = end1.size() - 1; i >= 0; i--)
 	{
 		cout << end1[i] + 1 << " ";
 	}
 	}
	return 0;
}