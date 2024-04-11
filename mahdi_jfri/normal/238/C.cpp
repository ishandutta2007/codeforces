#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e3 + 20;
vector<pair<int , bool> > adj[maxn];
ll root , dp[maxn] , res , t[maxn] , t2[maxn] , ans = 1e18;
void dfs(int v , int p)
{
	for(auto u : adj[v])
		if(u.first != p)
			dfs(u.first , v) , res += !u.second;
}
void dfs1(int v , int p)
{
	res = min(res , dp[v]);
	for(auto u : adj[v])
		if(u.first != p)
			dp[u.first] = dp[v] + (u.second? 1 : -1) , dfs1(u.first , v);
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		adj[--a].pb({--b , 1});
		adj[b].pb({a , 0});
	}
	dfs(0 , -1);
	dp[0] = res;
	res = 1e18;
	dfs1(0 , -1);
	ans = res;
	for(int i = 0; i < n; i++)
	{
		fill(dp , dp + n , 0);
		fill(t , t + n , 0);
		fill(t2 , t2 + n , 0);
		ll total = 0;
		for(auto u : adj[i])
		{
			total += !u.second;
			res = 0;
			dfs(u.first , i);
			dp[u.first] = res;
			total += res;
			t2[u.first] = res;
			res = 1e18;
			dfs1(u.first , i);
			t[u.first] = res;
		}
		ll min1 , min2;
		min1 = min2 = 1e18;
//		cout << i << endl;
		for(auto u : adj[i])
		{
	//		cout << i << " " << t2[u.first] << endl;
			ll dif = t[u.first] - t2[u.first];
			if(u.second)
				dif++;
			else
				dif--;
			if(dif < min1)
			{
				swap(min2 , min1);
				min1 = dif;
			}
			else if(dif < min2)
				min2 = dif;
		}
		if(min1 < 1e18 && min2 < 1e18)
		{
			ans = min(ans , total + min1 + min2);
//			cout << ans << " " << i + 1 << endl;
		}
	}
	if(n == 1)
		cout << 0;
	else
		cout << ans;
}