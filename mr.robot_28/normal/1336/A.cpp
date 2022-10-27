#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector <vector <int> > g;
int ans = 0;
vector <int> h, lists;
vector <int> _size, _sizenew;
vector <int> pr;
vector <bool> used;
vector <int> cnt;
void dfs(int v, int p = -1)
{
	cnt[v] = 0;
	_size[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			cnt[v]++;
			pr[to] = v;
			h[to] = h[v] + 1;
			dfs(to, v);
			_size[v] += _size[to];
		}
	}
	_sizenew[v]=_size[v];
	if(cnt[v] == 0)
	{
		lists.push_back(v);
	}
}
void dfs1(int v, int p, int c)
{
	if(!used[v] || v == 0)
	{
		c++;
	}
	if(used[v])
	{
		ans += c;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs1(to, v, c);
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	g.resize(n);
	used.resize(n);
	pr.resize(n);
	h.resize(n);
	_size.resize(n);
	cnt.resize(n);
	_sizenew.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v ;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	set <pair <int, int> > s;
	for(int i = 0; i < lists.size(); i++)
	{
		s.insert({-h[lists[i]], lists[i]});
	}
	while(s.size() != 0)
	{
		pair <int, int> v = *s.begin();
		s.erase(s.begin());
		used[v.second] = true;
		_sizenew[pr[v.second]] -= _size[v.second];
		k--;
		if(_sizenew[pr[v.second]] == 1)
		{
			s.insert({-(h[pr[v.second]] - _size[pr[v.second]] + 1), pr[v.second]});
		}
		if(k == 0)
		{
			break;
		}
	}
	dfs1(0, -1, 0);
	cout << ans;
	return 0;
}