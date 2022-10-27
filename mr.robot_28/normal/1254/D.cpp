#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t  % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
vector <int> sz;
vector <vector <int> > g;
vector <int> tin, tout;
int timer = 0;
vector <int> tree;
void update(int v, int l, int r, int al, int ar, int upd)
{
	while(ar >= 0){
		tree[ar] += upd;
		ar = (ar & (ar + 1)) - 1;
	}
	al--;
	while(al >= 0)
	{
		tree[al] -= upd;
		al = (al & (al + 1)) - 1;
	}
}
int ans(int v, int l, int r, int ind)
{
	int sum = 0;
	while(ind < sz.size())
	{
		sum = sum + tree[ind];
		if(sum >= const1)
		{
			sum -= const1;
		}
		ind = ind | (ind + 1);
	}
	return sum;
}
void dfs(int v, int p = -1)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
			sz[v] += sz[to];
		}
	}
	sz[v]++;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] == p)
		{
			g[v].erase(g[v].begin() + i);
			break;
		}
	}
	tout[v] = timer - 1;
}
bool pr(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	g.resize(n);
	tin.resize(n);
	tout.resize(n);
	sz.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	tree.resize(4 * n, 0);
	vector <int> allcnt(n, 0);
	int t = sqrt(n);
	vector <int> vec;
	for(int i = 0; i < n; i++)
	{
		if(g[i].size() >= t)
		{
			vec.push_back(i);
		}
	}
	int n1 = power(n, const1 - 2);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int v, d;
			cin >> v >> d;
			v--;
			allcnt[v] += d;
			allcnt[v] %= const1;
			if(g[v].size() < t)
			{
				for(int i = 0; i < g[v].size(); i++)
				{
					int to = g[v][i];
					update(1, 0, n - 1, tin[to], tout[to], (n - sz[to]) * d % const1);
				}
				if(tin[v] > 0)
				{
					update(1, 0, n - 1, 0, tin[v] - 1, sz[v] * d % const1);
				}
				if(tout[v] < n -1 )
				{
					update(1, 0, n - 1, tout[v] + 1, n -1, sz[v]* d % const1);
				}
			}
		}
		else
		{
			int v;
			cin >> v;
			v--;
			int sum = 0;
			sum += allcnt[v] * n % const1;
			sum += ans(1, 0, n - 1, tin[v]) % const1;
			for(int i = 0; i < vec.size(); i++)
			{
				int v1 = vec[i];
				if(v1 == v)
				{
					continue;
				}
				if(!pr(v1, v))
				{
					sum += sz[v1] * allcnt[v1] % const1;
				}
				else
				{
					int l = 0, r = g[v1].size();
					while(r - l > 1){
						int midd = (r + l) / 2;
						if(tin[g[v1][midd]] <= tin[v])
						{
							l = midd;
						}
						else
						{
							r = midd;
						}
					}
					sum += allcnt[v1] * (n - sz[g[v1][l]]) % const1;
				}
			}
			cout << sum % const1* n1 % const1 << "\n";
		}
	}
    return 0;
}