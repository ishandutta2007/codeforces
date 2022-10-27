#include <bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
void add(int &a, int b)
{
	a += b;
	if(a >= const1)
	{
		a -= const1;
	}
}
int mult(int a, int b)
{
	return a * b % const1;
}
int n;
vector <vector <int> > g;
vector <vector <int> > cnk;
vector <int> ans, _size;
int dp[101][101][101];
int tmp[101][101];
void dfs(int v, int p = -1)
{
	dp[v][0][1] = 1;
	_size[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		dfs(to, v);
		_size[v] += _size[to];
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			for(int s1 = 0; s1 < 101; s1++)
			{
				for(int s2 = 0; s2 < 101; s2++)
				{
					tmp[s1][s2] = 0;
				}
			}
			for(int s1 = 0; s1 <= _size[v]; s1++)
			{
				for(int c1 = 0; c1 <= _size[v]; c1++)
				{
					if(dp[v][s1][c1] == 0)
					{
						continue;
					}
					for(int s2 = 0; s2 <= _size[to]; s2++)
					{
						for(int c2 = 0; c2 <= _size[to]; c2++)
						{
							add(tmp[s1 + s2][c1 + c2], mult(dp[v][s1][c1], dp[to][s2][c2]));
						}
					}
				}
			}
			for(int s1  = 0; s1 < 101; s1++)
			{
				for(int c1 = 0; c1 < 101; c1++)
				{
					dp[v][s1][c1] = tmp[s1][c1];
				}
			}
		}
	}
	for(int s1= 0; s1 + 1 < 101; s1++)
	{
		for(int c1 = 0; c1 < 101; c1++)
		{
			add(dp[v][s1 + 1][0], mult(dp[v][s1][c1], c1));
		}
	}
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n;
	g.resize(n);
	_size.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cnk.resize(n + 1, vector <int> (n + 1));
	ans.resize(n + 1);
	cnk[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		cnk[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{
			add(cnk[i][j], cnk[i - 1][j]);
			add(cnk[i][j], cnk[i - 1][j - 1]);
		}
	}
	dfs(0, -1);
	for(int i = 1; i < n + 1; i++)
	{
		ans[i] = dp[0][i][0];
	}
	ans[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < i - 2; j++)
		{
			ans[i] = mult(ans[i], n);
		}
		for(int s = 1; s < i; s++)
		{
			add(ans[i], const1 - mult(ans[s], cnk[n - s][n - i]));
		}
	}
	for(int i = n ; i >= 1; i--)
	{
		cout << ans[i] << " ";
	}
    return 0;
}