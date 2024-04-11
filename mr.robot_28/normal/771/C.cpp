#include<bits/stdc++.h>
 
using namespace std;
#define int long long
int n, k;
vector <vector <int> > cntdown, cntup, g;
long long ans = 0;
vector <int> _sz;
vector <int> lendown, lenup;
void dfs(int v, int p = -1)
{
	_sz[v] = 1;
	auto it = find(g[v].begin(), g[v].end(), p);
	if(it != g[v].end())
	{
		g[v].erase(it);
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to, v);
		for(int j = 0; j < k; j++)
		{
			cntdown[v][(j + 1) % k] += cntdown[to][j];
		}
		cntdown[v][1 % k]++;
		lendown[v] += _sz[to] + lendown[to];
		_sz[v] += _sz[to];
	}
}
void dfs1(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		lenup[to] = lenup[v] + (lendown[v] - _sz[to] - lendown[to]) + (n - _sz[to]);
		for(int j = 0; j < k; j++)
		{
			cntup[to][(j + 1) % k] += cntup[v][j];
			cntup[to][(j + 1) % k] += (cntdown[v][j] - cntdown[to][(j - 1 + k) % k]);
		}
		cntup[to][(2) % k]--;
		cntup[to][1 % k]++;
		dfs1(to, v);
	}
	int sum = (lenup[v] + lendown[v]);
	for(int j = 1; j < k; j++)
	{
		sum -= cntup[v][j] * j;
		sum -= cntdown[v][j] * j;
		sum += (cntup[v][j] + cntdown[v][j]) * k;
	}
	sum /= k;
	ans += sum;
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n >> k;
	lendown.resize(n);
	lenup.resize(n);
	_sz.resize(n);
	g.resize(n);
	cntdown.resize(n, vector <int> (k));
	cntup.resize(n, vector <int> (k));
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	dfs1(0);
	cout << ans / 2;
	return 0;
}