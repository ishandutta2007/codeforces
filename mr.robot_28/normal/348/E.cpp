#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, t;
vector <bool> color;
vector <vector <pair <int, int> > > g;
vector <int> dp, dpind;
vector <int> add;
vector <vector <int> > pred;
vector <int> tin, tout;
vector <int> upadd, updel;
vector <vector <int> > pref1, pref2;
int timer = 0;
vector <int> tree, dpcnt;

void dfs1(int v, int p = -1)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to != p)
		{
			pred[to][0] = v;
			dfs1(to, v);
			if(dpind[to] == -1)
			{
				continue;
			}
			if(dp[to] + g[v][i].second > dp[v])
			{
				dp[v] = dp[to] + g[v][i].second;
				dpind[v] = dpind[to];
			}
			else if(dp[to] + g[v][i].second == dp[v])
			{
				dpind[v] = v;
			}
		}
	}
	tout[v] = timer++;
}
int pr(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
	if(pr(a, b))
	{
		return a;
	}
	for(int i = t - 1; i >= 0; i--)
	{
		if(!pr(pred[a][i], b))
		{
			a = pred[a][i];
		}
	}
	return pred[a][0];
}
vector <vector <int> > updates;
void dfs(int v, int p = -1, int ind = -1, int maxans = 0)
{
	int m1 = 0, ind1 = -1;
	if(color[v])
	{
		if(dp[v] > maxans)
		{
			dpcnt[v]++;
			updates[v].push_back(dpind[v]);
		}
		else if(dp[v] < maxans)
		{
			int l1 = lca(ind, v);
			dpcnt[l1]++;
			updates[l1].push_back(ind);
			updates[l1].push_back(v);
		}
	}
	pref1[v].resize(g[v].size());
	pref2[v].resize(g[v].size());
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int weight = g[v][i].second;
		pref1[v][i] = maxans;
		pref2[v][i] = ind;
		if(to != p)
		{
			if(dp[to] + g[v][i].second >  maxans && dpind[to] != -1)
			{
				maxans = dp[to] + g[v][i].second;
				ind = dpind[to];
			}
			else if(dp[to] + g[v][i].second == maxans && dpind[to] != -1)
			{
				ind = v;
			}
		}
	}
	for(int i = g[v].size() - 1; i >= 0; i--)
	{
		int to = g[v][i].first;
		int weight = g[v][i].second;
		if(to != p)
		{
			if(m1 == pref1[v][i]){
				if(ind1 == -1 && !color[v])
				{
					dfs(to, v, -1, 0);
				}
				else
				{
					dfs(to, v, v, m1 + g[v][i].second);
				}
			}
			else if(m1 > pref1[v][i])
			{
				dfs(to, v, ind1, m1 + g[v][i].second);
			}
			else
			{
				dfs(to, v, pref2[v][i], pref1[v][i] + g[v][i].second);
			}
			if(dp[to] + g[v][i].second > m1 && dpind[to] != -1)
			{
				m1 = dp[to] + g[v][i].second;
				ind1 = dpind[to];
			}
			else if(dp[to] + g[v][i].second == m1 && dpind[to] != -1)
			{
				ind1 = v;
			}
		}
	}
}
int anssum = 0, anscnt = 0;
void update(int v, int l, int r, int ind)
{
	if(l == r)
	{
		tree[v]++;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind);
	}
	tree[v]++;
}
int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(al <= r && ar >= l)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	else
	{
		return 0;
	}
}
void dfs3(int v, int p = -1)
{
	if(!color[v])
	{
		int a = ans(1, 0, timer - 1, tin[v], tout[v]) + dpcnt[v];
		if(a > anssum)
		{
			anssum = a;
			anscnt = 1;
		}
		else if(a == anssum)
		{
			anscnt++;
		}
	}
	for(int i = 0; i < updates[v].size(); i++)
	{
		update(1, 0, timer - 1, tin[updates[v][i]]);
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to != p)
		{
			dfs3(to, v);
		}
	}
}
signed main()
{
    ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    add.resize(n);
    dp.resize(n);
    dpind.resize(n, -1);
    dpcnt.resize(n);
    color.resize(n);
    upadd.resize(n);
    updel.resize(n);
    pref1.resize(n);
    pref2.resize(n);
    dpcnt.resize(n);
    updates.resize(n);
    t = log2(n) + 1;
    pred.resize(n, vector <int> (t));
    tin.resize(n);
    tout.resize(n);
    g.resize(n);
    for(int i = 0; i < m; i++)
    {
    	int x;
    	cin >> x;
    	x--;
    	color[x] = true;
    	dpind[x] = x;
	}
	for(int i = 0; i < n - 1; i++)
	{
		int u, v, x;
		cin >> u >>  v>> x;
		u--;
		v--;
		g[u].push_back({v, x});
		g[v].push_back({u, x});
	}
	dfs1(0);
	tree.resize(timer * 4);
	for(int j = 1; j < t; j++)
	{
		for(int i = 0; i < n; i++)
		{
			pred[i][j] = pred[pred[i][j - 1]][j - 1];
		}
	}
	dfs(0);
	dfs3(0);
	cout << anssum << " " << anscnt << "\n";
    return 0;
}