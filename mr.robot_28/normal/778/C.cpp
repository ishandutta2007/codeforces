#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 4;
const int MAXN = 1e6 + 5;
int h[MAXN], sub[MAXN];
int adj[MAXN][26];
int ans[MAXN];
int n, nn;
void dfs(int v)
{
	sub[v] = 1;
	for(int c =0; c < 26; c++)
	{
		int to = adj[v][c];
		if(to)
		{
			h[to] = h[v] + 1;
			dfs(to);
			sub[v] += sub[to];
		}
	}
}
int dfs3(int v, int v2, vector <pair <int, int> > &tmp)
{
	int ret = 1;
	for(int c = 0; c < 26; c++)
	{
		int to =adj[v][c];
		if(to)
		{
			int to2 = adj[v2][c];
			if(!to2)
			{
				adj[v2][c] = to2 = ++nn;
				tmp.push_back(make_pair(v2, c));
				--ret;
			}
			ret += dfs3(to, to2, tmp);
		}
	}
	return ret;
}
void dfs2(int v){
	int mx = -1;
	for(int c = 0; c < 26; c++)
	{
		int to = adj[v][c];
		if(to)
		{
			dfs2(to);
			if(mx == -1 || sub[to] > sub[mx])
			{
				mx = to;
			}
		}
	}
	if(mx == -1)
	{
		return;
	}
	ans[h[v]]++;
	vector <pair <int, int> > tmp;
	nn = n;
	for(int c = 0; c < 26; c++)
	{
		int to = adj[v][c];
		if(to && to != mx)
		{
			ans[h[v]] += dfs3(to, mx, tmp);
		}
	}
	for(int i = 0; i < tmp.size(); i++)
	{
		adj[tmp[i].first][tmp[i].second] = 0;
	}
}
signed main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		char c;
		cin >> u >> v >> c;
		adj[u][c - 'a'] = v;
	}
	dfs(1);
	dfs2(1);
	int me = 0;
	for(int i = 1; i <= n; i++)
	{
		if(ans[i] > ans[me])
		{
			me = i;
		}
	}
	cout << n - ans[me] << "\n";
	cout << me + 1;
	return 0;
}