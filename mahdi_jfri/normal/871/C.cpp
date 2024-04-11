#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
const ll mod = 1e9 + 7;

vector<int> adj[maxn];

int tah = 1 , is;

ll t[maxn] , cnt;

map<ll , int> mp;

bool visited[maxn];

int f(ll a)
{
	if(!mp[a])
		mp[a] = tah++;
	return mp[a];
}

void dfs(int v , int p = -1)
{
	visited[v] = 1;
	cnt++;
	for(auto u : adj[v])
	{
		if(!visited[u])
			dfs(u , v);
		else if(u != p)
			is = 1;
	}
}

int main()
{
	t[0] = 1;
	for(int i = 1; i < maxn; i++)
		t[i] = (t[i - 1] * 2) % mod;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		ll x , y;
		cin >> x >> y;
		y += 1e10;
		x = f(x);
		y = f(y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ll res = 1;
	for(int i = 1; i < tah; i++)
		if(!visited[i])
		{
			is = cnt = 0;
			dfs(i);
			if(!is)
				res *= (t[cnt] - 1 + mod) % mod;
			else
				res *= t[cnt];
			res %= mod;
		}
	cout << res << endl;
}