#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
vector<int> adj[maxn];
int a[maxn] , res = 1e9 , last;
void dfs(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
			a[u] = min(u , a[v]) , dfs(u , v);
}
int main()
{
	int n , q;
	cin >> n >> q;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int x;
	cin >> x >> x;
	x = (x % n) + 1;
	a[x] = x;
	dfs(x);
	res = x;
	q--;
	while(q--)
	{
		int x , v;
		scanf("%d%d", &x , &v);
		v = (v + last) % n + 1;
		if(x == 1)
			res = min(res , a[v]);
		else
		{
			printf("%d\n" , min(res , a[v]));
		//	cout << min(res , a[v]) << endl;
			last = min(res , a[v]);
		}
	}
}