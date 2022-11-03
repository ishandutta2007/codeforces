#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e3 + 20;
vector<int> adj[maxn];
int a[maxn][maxn] , n , m;
bool b[maxn][maxn];
bool check(ll x)
{
	for(int i = 0; i < n; i++)
	{
		adj[i].clear();
		for(int j = 0; j < m; j++)
			if(a[i][j] >= x)
				adj[i].pb(j);
	}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			b[i][j] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < (int)adj[i].size(); j++)
			for(int k = j + 1; k < (int)adj[i].size(); k++)
			{
				int v = adj[i][j] , u = adj[i][k];
				if(b[v][u])
				{
					return 1;
				}
				b[v][u] = 1;
			}
	}
	return 0;
}
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	ll lo = 0 , hi = 1e9;
	while(1)
	{
		if(hi - lo == 1)
		{
			if(check(hi))
				lo = hi;
			break;
		}
		ll m = (hi + lo) / 2;
		if(check(m))
			lo = m;
		else
			hi = m;
	}
//	cout << check(5) << " " << check(2) << " " << check(3) << " " << check(4) << endl;
	cout << lo << endl;
}