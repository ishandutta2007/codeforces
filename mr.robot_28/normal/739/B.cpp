#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > tree;
vector <vector <int> > itleft;
vector <vector <int> > itright;
vector <int> tin, tout;
vector <vector <pair <int, int> > > g;
vector <int> a, h;
int timer = 0;
void dfs(int v)
{
	tin[v] = timer;
	timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int weight = g[v][i].second;
		h[to] = h[v] + weight;
		dfs(to);
	}	
	tout[v] = timer - 1;
}
vector <pair <int, int> > mass;
void build(int v, int l, int r)
{
	if(l == r)
	{
		itleft[v].resize(1);
		itright[v].resize(1);
		tree[v].push_back(mass[l].second);
		return;
	}
	build(v * 2, l, (r + l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
	int j = 0;
	for(int i = 0; i < tree[v * 2].size(); i++)
	{
		while(j < tree[v * 2 + 1].size() && tree[v * 2 + 1][j] <= tree[v * 2][i])
		{
			tree[v].push_back(tree[v * 2 + 1][j]);
			j++;
		}
		tree[v].push_back(tree[v * 2][i]);
	}
	while(j < tree[v * 2 + 1].size())
	{
		tree[v].push_back(tree[v * 2 + 1][j]);
		j++;
	}
	itleft[v].resize(tree[v].size());
	itright[v].resize(tree[v].size());
	j = 0;
	for(int i = 0; i < tree[v].size(); i++)
	{
		while(j < tree[v * 2].size() && tree[v * 2][j] <= tree[v][i])
		{
			j++;
		}
		itleft[v][i] = j - 1;
	}
	j = 0;
	for(int i = 0; i < tree[v].size(); i++)
	{
		while(j < tree[v * 2 + 1].size() && tree[v * 2 + 1][j] <= tree[v][i])
		{
			j++;
		}
		itright[v][i] = j - 1;
	}
}
int ans(int v, int l, int r, int al, int ar, int i)
{
	if(i == -1)
	{
		return 0;
	}
	if(l >= al && r <= ar)
	{
		return i + 1;
	}
	else if(l <= ar && r >= al)
	{
		int ileft = itleft[v][i];
		int iright = itright[v][i];
		return ans(v * 2, l, (r + l) / 2, al, ar, ileft) + 
		ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, iright);
	}
	return 0;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    h.resize(n);
    a.resize(n);
    g.resize(n);
    tree.resize(4 * n);
    itleft.resize(4 * n);
    itright.resize(4 * n);
    tin.resize(n);
    tout.resize(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
    	int p, w;
    	cin >> p >> w;
    	p--;
    	g[p].push_back({i, w});
    }
    dfs(0);
	for(int i = 0; i < n; i++)
	{
		mass.push_back({tin[i], h[i] - a[i]});
	}   
	sort(mass.begin(), mass.end());
	build(1, 0, n - 1);
	for(int i = 0; i < n; i++)
	{
		if(tin[i] + 1 <= tout[i])
		{
			int l = -1, r = tree[1].size();
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(h[i] >= tree[1][midd])
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			cout << ans(1, 0, n - 1, tin[i] + 1, tout[i], l) << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}
	return 0;
}