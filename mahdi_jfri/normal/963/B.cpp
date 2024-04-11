#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

vector<int> adj[maxn] , a[maxn] , b[maxn] , c[maxn] , ans;

bool dp[maxn] , pd[maxn];

void dfs(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
		{
			dfs(u , v);
			if(dp[u] && pd[u])
				a[v].pb(u);
			if(dp[u] && !pd[u])
				b[v].pb(u);
			if(!dp[u] && pd[u])
				c[v].pb(u);
			if(!dp[u] && !pd[u])
			{
				cout << "NO" << endl;
				exit(0);
			}
		}

	if(a[v].empty())
	{
		if((int)c[v].size() % 2 != 0)
			dp[v] = 1;

		if((int)c[v].size() % 2 == 0)
			pd[v] = 1;
	}
	else
		dp[v] = pd[v] = 1;
}

void print(int v , bool has , int p = -1)
{
	if(a[v].empty())
	{
		for(auto u : b[v])
			print(u , 1 , v);
		ans.pb(v);
		for(auto u : c[v])
			print(u , 0 , v);
	}
	else
	{
		int k = adj[v].size();
		if(!has && p != -1)
			k--;

		if((int)c[v].size() % 2 == 0)
		{
			for(auto u : a[v])
				print(u , 1 , v);
			for(auto u : b[v])
				print(u , 1 , v);
			ans.pb(v);
			for(auto u : c[v])
				print(u , 0 , v);
		}
		else
		{
			int node = a[v].back();
			a[v].pop_back();

			for(auto u : a[v])
				print(u , 1 , v);
			for(auto u : b[v])
				print(u , 1 , v);
			ans.pb(v);
			print(node , 0 , v);

			for(auto u : c[v])
				print(u , 0 , v);
		}
	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;

		p--;
		if(p != -1)
			adj[p].pb(i) , adj[i].pb(p);
	}
	dfs(0);

	if(!pd[0])
		return cout << "NO" << endl , 0;

	cout << "YES" << endl;

	print(0 , 0);

	for(auto v : ans)
		cout << v + 1 << endl;

}