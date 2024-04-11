#include <bits/stdc++.h>
using namespace std;
vector<int> G[200010];
int last[200010], st[200010];

void dfs(int u, int rt)
{
	for(auto v : G[u])
	{
		if(st[v] == 0) 
		{
			if(rt == u) st[v] = u;
			else st[v] = st[u];
			last[v] = u;
			dfs(v, rt);
		}
		else if(st[v] != st[u])
		{
			cout << "Possible\n";
			vector<int> a, b;
			b.push_back(v);
			for(int i = v; i != 0; i = last[i]) a.push_back(i);
			for(int i = u; i != 0; i = last[i]) b.push_back(i);
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			cout << a.size() << "\n";
			for(auto x : a) cout << x << " "; cout << "\n";
			cout << b.size() << "\n";
			for(auto x : b) cout << x << " "; cout << "\n";
			exit(0);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, s;
	cin >> n >> m >> s;	
	for(int i = 1; i <= m; i ++)
	{
		int u, v;
		cin >> u >> v;
		if(v != s) G[u].push_back(v);
	}
	for(auto v : G[s])
	{
		last[v] = s;
		st[v] = v;
	}
	for(auto v : G[s]) dfs(v, v);
	cout << "Impossible\n";
}