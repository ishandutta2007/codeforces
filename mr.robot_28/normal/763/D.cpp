#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <vector <pair <int, int> > > g;
vector <int> hashes_down, hashes_up;
vector <int> hash1;
const int mod = 1e9 + 7;
const int p = 3;
vector <int> sz;
vector <int> power;
void dfs(int v, int pr = -1)
{
	sz[v] = 1;
	vector <pair <int, int> > mass1;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i].first != pr){
			dfs(g[v][i].first, v);
			sz[v] += sz[g[v][i].first];
			mass1.push_back({hashes_down[g[v][i].first], sz[g[v][i].first] * 2});
		}
	}
	if(mass1.size() != 0)
	{
	sort(mass1.begin(), mass1.end());
	}
	int c = 1;
	hashes_down[v] = 1;
	for(int i = 0; i < mass1.size(); i++)
	{
		hashes_down[v] += (mass1[i].first * power[c]) % mod;
		c += mass1[i].second;
		if(hashes_down[v] >= mod)
		{
			hashes_down[v] -= mod;
		}
	}
	hashes_down[v] += 2 * power[c] % mod;
	if(hashes_down[v] >= mod)
	{
		hashes_down[v] -= mod;
	}
}
int n;
void dfs1(int v, int pr = -1)
{
	vector <pair <pair <int, int>, int> > mass1;
	if(pr != -1)
	{
		mass1.push_back({{hashes_up[pr], (n - sz[v]) * 2}, pr});
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to != pr)
		{
			mass1.push_back({{hashes_down[to], sz[to] * 2}, to});
		}
	}
	sort(mass1.begin(), mass1.end());
	vector <int> prefh(g[v].size() + 2), preflen(g[v].size() + 2), sufh(g[v].size() + 2), suflen(g[v].size() + 2);
	prefh[0] = 1;
	preflen[0] = 1;
	for(int i = 0; i < mass1.size(); i++)
	{
		prefh[i + 1] = prefh[i] + (mass1[i].first.first * power[preflen[i]]) % mod;
		if(prefh[i + 1] >= mod)
		{
			prefh[i + 1] -= mod;
		}
		preflen[i + 1] = preflen[i] + mass1[i].first.second;
	}
	prefh[mass1.size() + 1] = prefh[mass1.size()] + (2 * power[preflen[mass1.size()]]) % mod;
	if(prefh[mass1.size() + 1] >= mod)
	{
		prefh[mass1.size() + 1] -= mod;
	}
	sufh[mass1.size() + 1] = 2;
	if(mass1.size() != 0)
	{
	for(int i = mass1.size() - 1; i >= 0; i--)
	{
		sufh[i + 1] = sufh[i + 2] * power[mass1[i].first.second] % mod + mass1[i].first.first;
		if(sufh[i + 1] >= mod)
		{
			sufh[i + 1] -= mod;
		}
	}
	}
	sufh[0] = 1 + power[1] * sufh[1] % mod;
	if(sufh[0] >= mod)
	{
		sufh[0] -= mod;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to == pr)
		{
			continue;
		}
		int l = 0, r = mass1.size();
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(mass1[midd].first.first < hashes_down[to])
			{
				l = midd;
			}
			else if(mass1[midd].first.first == hashes_down[to] && mass1[midd].first.second < sz[to] * 2)
			{
				l = midd;
			}
			else if(mass1[midd].first == make_pair(hashes_down[to], sz[to] * 2) && mass1[midd].second <= to)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		hashes_up[v] = prefh[l] + power[preflen[l]] * sufh[l + 2] % mod;
		if(hashes_up[v] >= mod)
		{
			hashes_up[v] -= mod;
		}  
		hash1[g[v][i].second] = hashes_up[v];
		dfs1(to, v);
 	}
}
unordered_map <int, int> mp;
void dfs2(int v, int pr = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to != pr)
		{
			mp[hashes_down[to]]++;
			dfs2(to, v);
		}
	}
}
vector <int> check;
void dfs3(int v, int pr = -1)
{
	check[v] = mp.size();
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(to == pr)
		{
			continue;
		}
		mp[hashes_down[to]]--;
		if(mp[hashes_down[to]] == 0)
		{
			mp.erase(hashes_down[to]);
		}
		mp[hash1[g[v][i].second]]++;
		dfs3(to, v);
		mp[hashes_down[to]]++;
		mp[hash1[g[v][i].second]]--;
		if(mp[hash1[g[v][i].second]] == 0)
		{
			mp.erase(hash1[g[v][i].second]);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	hash1.resize(n);
	sz.resize(n);
	check.resize(n);
	hashes_down.resize(n);
	hashes_up.resize(n);
	power.resize(n * 2 + 1);
	power[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		power[i] = power[i - 1] * p % mod;
	}
	g.resize(n);
	vector <pair <int, int> > edges;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
		edges.push_back({a, b});
		edges.push_back({b, a});
	}
	dfs(0);
	dfs1(0);
	dfs2(0);
	dfs3(0);
	int v = 0;
	for(int i = 1; i < n; i++)
	{
		if(check[i] > check[v])
		{
			v = i;
		}
	}
	cout << v + 1;
	return 0;
}