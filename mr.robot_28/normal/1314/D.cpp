#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector <bool> used;
vector <vector <int> > g;
vector <vector <vector <int> > > s;
int ans = 1e11;
inline void dfs(vector <int> &a, int cnt)
{
	if(cnt == 0)
	{
		if(a.size() == 0)
		{
			ans = min(ans, g[0][s[0][0][0]] + g[s[0][0][0]][0]);
			return;
		}
		bool flag = true;
		used[0] = true;
		for(int p = 0; p < a.size(); p++)
		{
			used[a[p]] = true;
		}
		int sum = 0;
		for(int i = 0; i < s[0][a[0]].size(); i++)
		{
			int v = s[0][a[0]][i];
			if(v != -1 && !used[v])
			{
				sum += g[0][v] + g[v][a[0]];
				break;
			}
			if(i == s[0][a[0]].size() - 1){
				flag = false;
			}
		}
		for(int i = 0; i < s[a[a.size() - 1]][0].size(); i++)
		{
			int v = s[a[a.size() - 1]][0][i];
			if(v != -1 && !used[v])
			{
				sum += g[a[a.size() - 1]][v] + g[v][0];
				break;
			}
			if(i == s[a[a.size() - 1]][0].size() - 1)
			{
				flag = false;
			}
		}
		for(int i = 0; i < a.size() - 1; i++)
		{
			for(int j = 0; j < s[a[i]][a[i + 1]].size(); j++)
			{
				int v = s[a[i]][a[i + 1]][j];
				if(v != -1 && !used[v])
				{
					sum += g[a[i]][v] + g[v][a[i + 1]];
					break;
				}
				if(j == s[a[i]][a[i + 1]].size() - 1)
				{
					flag = false;
				}
			}
		}
		for(int p = 0; p < a.size(); p++)
		{
			used[a[p]] = false;
		}
		if(flag)
		{
			ans = min(ans, sum);
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
				a.push_back(i);
				dfs(a, cnt - 1);
				a.pop_back();
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	used.resize(n);
	s.resize(n, vector <vector <int> > (n, vector <int> (6, -1)));
	g.resize(n, vector <int> (n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;j < n; j++)
		{
			vector <int> maxp(6, -1);
			for(int k = 0; k < n; k++)
			{
				if(k != i && k != j)
				{
					for(int t = 0; t < 6; t++)
					{
					if(maxp[t] == -1 || g[i][maxp[t]] + g[maxp[t]][j] > g[i][k] + g[k][j])
					{
						for(int t1 = 5; t1 > t; t1--)
						{
							maxp[t1] = maxp[t1 - 1];
						}
						maxp[t] = k;
						break;
					}
					}
				}
			}
			for(int p = 0; p < 6; p++)
			{
				s[i][j][p] = maxp[p];
			}
		}
	}
	vector <int> p;
	dfs(p, k / 2 - 1);
	cout << ans;
	return 0;
}