#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector <vector <pair <int, int> > > g;
vector <int> _size;
vector <int> used;
int cnt = 1;
map <int, int> w;
int eiler(int m)
{
	if(m == 1)
	{
		return 0;
	}
	int m1 = m;
	int pr1 = 1, pr2 = m;
	for(int j = 2; j <= sqrt(m); j++)
	{
		if(m1 % j == 0)
		{
			pr1 *= (j - 1);
			pr2 /= j;
		}
		while(m1 % j == 0)
		{
			m1 = m1 / j;
		}
	}
	if(m1 != 1)
	{
		pr1 *= (m1 - 1);
		pr2 /= m1;
	}
	return pr2 * pr1;
}
void find_size(int v, int p = -1)
{
	_size[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(!used[to] && to != p)
		{
			find_size(to, v);
			_size[v] += _size[to];
		}
	}
}
int find_centroid(int v, int sz, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(!used[to] && _size[to] * 2 > sz && to != p)
		{
			return find_centroid(to, sz, v);
		}
	}
	return v;
}
int M;
int power(int a, int n)
{
	if(n == 0)
	{
		return 1 % m;
	}
	else if(n % 2 == 0)
	{
		int t = power(a, n / 2);
		return t * t % m;
	}
	else
	{
		int t = power(a, n / 2);
		t = t * t % m;
		return a * t % m;
	}
}
int ans = 0;
vector <int> mass;
void go_to_add(int v, int p, int a, bool flag, int u)
{
	if(a == 0 && flag)
	{
		ans++;
	}
	w[a]++;
	mass.push_back(a);
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int weight = g[v][i].second;
		if(to != p && !used[to])
		{
			go_to_add(to, v, (weight * u + a) % m, flag, u * 10 % m);
		}
	}
}
vector <int> Pow;
void go_to_find(int v, int p, int a, bool flag, int k = 1)
{
	int y = 0;
	if(a != 0)
	{
		y = m - a;
	}
	if(a == 0 && flag)
	{
		ans++;
	}
	y = y * Pow[k] % m;
	ans += w[y];
	for(int i = 0; i < g[v].size(); i++)
	{
		int to= g[v][i].first;
		int weight = g[v][i].second;
		if(to != p && !used[to])
		{
			go_to_find(to, v, (a * 10 + weight) % m, flag, k + 1);
		}
	}
}
void build(int v)
{
	find_size(v);
	v = find_centroid(v, _size[v]);
	used[v] = cnt++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(!used[to])
		{
			go_to_find(to, v, g[v][i].second % m, true);
			go_to_add(g[v][i].first, v, g[v][i].second % m, true, 10 % m);
		}
	}
	while(mass.size() > 0)
	{
		w[mass.back()]--;
		mass.pop_back();
	}
	for(int i = g[v].size() - 1; i >= 0; i--)
	{
		int to = g[v][i].first;
		if(!used[to])
		{
			go_to_find(to, v, g[v][i].second % m, false);
			go_to_add(g[v][i].first, v, g[v][i].second % m, false, 10 % m);
		}
	}
	while(mass.size() > 0)
	{
		w[mass.back()]--;
		mass.pop_back();
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(!used[to])
		{
			build(to);
		}
	}
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    M = eiler(m) + 1;
    g.resize(n);
    used.resize(n);
    _size.resize(n);
    Pow.resize(n + 1);
    Pow[0] = 1;
    int a = power(10, M - 2);
    for(int i = 1; i <= n; i++)
    {
    	Pow[i] = Pow[i - 1] * a % m;
	}
    for(int i = 0; i < n - 1; i++)
    {
    	int u, v, x;
    	cin >> u >> v >> x;
    	g[u].push_back({v, x});
    	g[v].push_back({u, x});
	}
	build(0);
	cout << ans;
    return 0;
}