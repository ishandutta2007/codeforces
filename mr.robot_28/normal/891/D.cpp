#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
int n;
int dp[500000][2];
vector <int> _size;
vector <vector <int> > g;
void dfs1(int v, int p = -1)
{
	_size[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs1(to, v);
			_size[v] += _size[to];
		}
	}
	int cnt1 = 0, cnt2 = 0;
	vector <int> post(g[v].size(), 1);
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			if(_size[to] % 2 == 0)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
	}
	for(int i = g[v].size() - 1; i >= 0; i--)
	{
		if(i != g[v].size() - 1)
		{
			post[i] = post[i + 1];
		}
		int to = g[v][i];
		if(to != p && dp[to][0] == 0)
		{
			post[i] = 0;
		}
	}
	if(cnt2 > 2)
	{
		dp[v][0] = dp[v][1] = 0;
		return;
	}
	if(cnt2 > 0)
	{
		if(cnt2 == 2)
		{
			dp[v][0] = 0;
		}
		else
		{
			dp[v][0] = post[0];
		}
		bool flag = true;
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if(to != p)
			{
				if(flag && (i == g[v].size() - 1 || post[i + 1]) && _size[to] % 2 == 1)
				{
					dp[v][1] += dp[to][1];
				}
				if(dp[to][0] == 0)
				{
					flag = false;
				}
			}
		}
	}
	else
	{
		dp[v][0] = post[0];
		bool flag = true;
		for(int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if(to != p)
			{
				if(flag && (i == g[v].size() - 1 || post[i + 1]))
				{
					dp[v][1] += dp[to][1];
				}
				if(dp[to][0] == 0)
				{
					flag = false;
				}
			}
		}
		dp[v][1] += post[0];
	}
}
int ans = 0;
int dp_pref[500001][2][2];
int dp_post[500001][2][2];
int dp3[500001][2][2];
void dfs2(int v, int p = -1)
{
	for(int i =0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			dp_pref[0][i][j] = dp3[v][i][j];
		}
	}
	if(p != -1)
	{
		if(_size[v] % 2 == 0)
		{
			ans += dp[v][0] * dp3[v][0][0] * ((n - _size[v]) * _size[v]);
		}
		else
		{
			ans += dp[v][1] * dp3[v][1][0];
		}
	}
	for(int a = 0; a < 2; a++)
	{
		for(int b = 0; b < 2; b++)
		{
			dp_post[g[v].size()][a][b] = 0;
		}
	}
	dp_post[g[v].size()][0][0] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			if(_size[to] % 2 == 0)
			{
				dp_pref[i + 1][0][0] = dp_pref[i][0][0] * dp[to][0];
				dp_pref[i + 1][0][1] = dp_pref[i][0][1] * dp[to][0];
				dp_pref[i + 1][1][0] = dp[to][0] * dp_pref[i][1][0];
				dp_pref[i + 1][1][1] = dp_pref[i][0][0] * dp[to][1] + dp[to][0] * dp_pref[i][1][1];
			}
			else
			{
				dp_pref[i + 1][0][0] = 0;
				dp_pref[i + 1][0][1] = dp_pref[i][0][0] * dp[to][0];
				dp_pref[i + 1][1][0] = dp_pref[i][0][0] * dp[to][1];
				dp_pref[i + 1][1][1] = dp_pref[i][0][1] * dp[to][1] + dp[to][0] * dp_pref[i][1][0];
			}
		}
		else
		{
			for(int a = 0; a < 2; a++)
			{
				for(int b = 0; b < 2; b++)
				{
					dp_pref[i + 1][a][b] = dp_pref[i][a][b];
				}
			}
		}
	}
	for(int i = g[v].size() - 1; i >= 0; i--)
	{
		int to = g[v][i];
		if(to != p)
		{
			if(_size[to] % 2 == 0)
			{
				dp_post[i][0][0] = dp_post[i + 1][0][0] * dp[to][0];
				dp_post[i][0][1] = dp_post[i + 1][0][1] * dp[to][0];
				dp_post[i][1][0] = dp_post[i + 1][1][0] * dp[to][0];
				dp_post[i][1][1] = dp_post[i + 1][0][0] * dp[to][1] + dp_post[i + 1][1][1] * dp[to][0];
			}
			else
			{
				dp_post[i][0][0] = 0;
				dp_post[i][0][1] = dp_post[i + 1][0][0] * dp[to][0];
				dp_post[i][1][0] = dp_post[i + 1][0][0] * dp[to][1];
				dp_post[i][1][1] = dp_post[i + 1][0][1] * dp[to][1] + dp_post[i + 1][1][0] * dp[to][0];
			}
		}
		else
		{
			for(int a = 0; a < 2; a++)
			{
				for(int b = 0; b < 2; b++)
				{
					dp_post[i][a][b] = dp_post[i + 1][a][b]; 
				}
			}
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dp3[to][0][0] = dp_pref[i][0][0] * dp_post[i + 1][0][0];
			dp3[to][0][1] = min(1LL, dp_pref[i][0][1] * dp_post[i + 1][0][0] + dp_pref[i][0][0] * dp_post[i + 1][0][1]);
			dp3[to][1][0] = dp_pref[i][1][0] * dp_post[i + 1][0][0] + dp_pref[i][0][0] * dp_post[i + 1][1][0];
			dp3[to][1][1] = dp_pref[i][1][1] * dp_post[i + 1][0][0] + dp_pref[i][1][0] * dp_post[i + 1][0][1] + 
			dp_pref[i][0][1] * dp_post[i + 1][1][0] + dp_pref[i][0][0] * dp_post[i + 1][1][1];
			for(int a = 0; a < 2; a++)
			{
				swap(dp3[to][a][0], dp3[to][a][1]);
			}
			dp3[to][1][0] += dp3[to][0][1];
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs2(to, v);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	_size.resize(n);
	g.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(n % 2  == 1)
	{
		cout << 0;
		return 0;
	}
	dfs1(0);
	for(int i = 0; i < n; i++)
	{
		for(int a  = 0;  a < 2; a++)
		{
			for(int b = 0; b < 2; b++)
			{
				dp3[i][a][b] = 0;
			}
		}
	}
	dp3[0][0][0] = 1;
	dfs2(0);
	cout << ans;
	return 0;
}