#include <bits/stdc++.h>
 
using namespace std;
const double pi = 3.1415926535;
vector <int> col;
int cnt1 = 0, cnt2 = 0;
vector <vector <int> > g;
vector <int> col1, col2;
void dfs(int v, int cl)
{
	col[v] = cl;
	if(cl == 1)
	{
		col1.push_back(v);
		cnt1++;
	}
	else
	{
		col2.push_back(v);
		cnt2++;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(col[to] == -1)
		{
			dfs(to, 1 - cl);
		}
		else if(col[to] == col[v])
		{
			cout << "NO";
			exit(0);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	g.resize(n);
	col.resize(n, -1);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector <pair <int, int> > mass;
	vector <vector <int> > vec1, vec2;
	for(int i = 0; i < n; i++)
	{
		if(col[i] == -1)
		{
			dfs(i, 0);
			mass.push_back({cnt1, cnt2});
			cnt1 = 0;
			cnt2 = 0;
			vec1.push_back(col1);
			vec2.push_back(col2);
			col1.clear();
			col2.clear();
		}
	}
	vector <vector <bool> > dp(mass.size() + 1, vector <bool> (n + 1));
	dp[0][0] = true;
	vector <vector <int> > pred(mass.size() + 1, vector <int> (n + 1, -1));
	for(int i = 0; i < mass.size(); i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(dp[i][j])
			{
				if(j + mass[i].first <= n)
				{
					dp[i + 1][j + mass[i].first] = true;
					pred[i + 1][j + mass[i].first] = 0;
				}
				if(j + mass[i].second <= n)
				{
					dp[i + 1][j + mass[i].second] = true;
					pred[i + 1][j + mass[i].second] = 1;
				}
			}
		}
	}
	if(!dp[mass.size()][n2])
	{
		cout << "NO";
		return 0;
	}
	vector <int> anscol(n, -1);
	int st = mass.size(), stkol =n2;
	while(st > 0)
	{
		if(pred[st][stkol] == 0)
		{
			for(int j = 0; j < vec1[st - 1].size(); j++)
			{
				anscol[vec1[st - 1][j]] = 2;
			}
			stkol -= vec1[st - 1].size();
		}
		else
		{
			for(int j = 0; j < vec2[st -1].size(); j++)
			{
				anscol[vec2[st - 1][j]] = 2;
			}
			stkol -= vec2[st - 1].size();
		}
		st--;
	}
	cout << "YES\n";
	for(int j = 0; j < n; j++)
	{
		if(anscol[j] == -1)
		{
			if(n1 > 0)
			{
				cout << 1;
				n1--;
			}
			else
			{
				cout << 3;
				n3--;
			}
		}
		else
		{
			cout << 2;
		}
	}
    return 0;
}