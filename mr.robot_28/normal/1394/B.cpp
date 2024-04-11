#include<bits/stdc++.h>
 
using namespace std;

vector <vector <pair <int, int> > > g;
bool cmp(pair <int, int> a, pair <int, int> b)
{
	return a.second < b.second;
}
int n, m ,k;
bool matrix[10][9][10][9];
vector <vector <bool> > used;
int ans = 0;
void dfs(int i)
{
	if(i == k + 1)
	{
		ans++;
		return;
	}
	vector <vector <bool> > turned(k + 1, vector <bool> (k));
	for(int j = 0; j < i; j++){
		if(!used[i][j])
		{
			bool flag = 1;
			for(int a = i; a <= k; a++)
			{
				for(int b = 0; b < k; b++)
				{
					if(matrix[i][j][a][b])
					{
						if(!used[a][b])
						{
						turned[a][b] = 1;
						used[a][b] = 1;
						}
						if(a == i && b == j)
						{
							flag = 0;
						}
					}
				}
			}
			if(flag)
			{
			dfs(i + 1);
			}
			for(int a = i; a <= k; a++)
			{
				for(int b = 0; b < k; b++)
				{
						if(turned[a][b])
						{
						turned[a][b] = 0 ;
						used[a][b] = 0;
						}
				}
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	g.resize(n);
	for(int i = 1;  i <= k; i++)
	{
		for(int j = 0; j < k; j++)
		{
			for(int a = 1; a <= k; a++)
			{
				for(int b = 0; b < k; b++)
				{
					matrix[i][j][a][b] = 0; 
				}
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >>  a>> b >> c;
		a--;
		b--;
		g[a].push_back({b, c});
	}
	vector <vector <pair <int, int> > > g1(n);
	vector <vector <vector <int> > > graf(n, vector <vector <int> > (k + 1, vector <int> (k)));
	for(int i = 0; i < n; i++)
	{
		sort(g[i].begin(), g[i].end(), cmp);
		for(int j = 0; j < g[i].size(); j++)
		{
			int to = g[i][j].first;
			graf[to][g[i].size()][j]++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			for(int b = 0; b < j; b++)
			{
				if(graf[i][j][b])
				{
					graf[i][j][b]--;
					for(int e = j; e <= k; e++)
					{
						for(int d = 0; d < e; d++)
						{
							if(graf[i][e][d])
							{
								matrix[j][b][e][d] = 1;
							}
						}
					}
					graf[i][j][b]++;
				}
			}
		}
	}
	used.resize(k + 1, vector <bool> (k, 0));
	vector <int> vec;
	dfs(1);
	cout << ans;
	return 0;
}