#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> out[maxn] , in[maxn];

int n , k , t[maxn];

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;
	for(auto u : out[v])
	{
		if(!visited[u])
		{
			t[u] = t[v] + 1;
			dfs(u);
		}
		else if(t[u] != t[v] + 1)
			k = __gcd(k , abs(t[u] - t[v] - 1));
	}
	for(auto u : in[v])
	{
		if(!visited[u])
		{
			t[u] = t[v] - 1;
			dfs(u);
		}
		else if(t[u] != t[v] - 1)
			k = __gcd(k , abs(t[u] - t[v] + 1));
	}
}

bool dfs_check(int v , int x)
{
	bool f = 1;
	visited[v] = 1;
	for(auto u : out[v])
	{
		if(!visited[u])
		{
			t[u] = t[v] + 1;
			t[u] %= x;
			f &= dfs_check(u , x);
		}
		else if(t[u] != (t[v] + 1) % x)
			f = 0;
	}

	for(auto u : in[v])
	{
		if(!visited[u])
		{
			t[u] = t[v] - 1 + x;
			t[u] %= x;
			f &= dfs_check(u , x);
		}
		else if(t[u] != (t[v] - 1 + x) % x)
			f = 0;
	}
	return f;
}

bool check(int x)
{
	memset(t , 0 , sizeof t);
	memset(visited , 0 , sizeof visited);

	bool res = 1;

	for(int i = 0; i < n; i++)
		if(!visited[i])
			res &= dfs_check(i , x);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		out[a].pb(b);
		in[b].pb(a);
	}

	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);

	if(!k)
		return cout << n << endl , 0;

	for(int i = k; i >= k; i--)
		if(k % i == 0 && check(i))
			return cout << i << endl , 0;
}