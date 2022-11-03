#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

vector<int> adj[maxn] , rq[maxn];

int par[maxn] , a[maxn] , h[maxn];

ll sum[maxn];

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;
	for(auto u : adj[v])
		if(u != par[v])
		{
			if(!visited[u])
			{
				h[u] = h[v] + 1;
				par[u] = v;
				dfs(u);
			}
			else if(h[u] < h[v])
			{
				int tmp = v , mn = u , mx = u;
				while(tmp != u)
				{
					mn = min(mn , tmp);
					mx = max(mx , tmp);
					tmp = par[tmp];
				}
				rq[mx].pb(mn);
			}
		}
}

int main()
{
	int n , m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	for(int i = 0; i < n; i++)
		if(!visited[i])
		{
			par[i] = -1;
			dfs(i);
		}
	int lst = -1;
	for(int i = 0; i < n; i++)
	{
		for(auto x : rq[i])
			lst = max(lst , x);
		a[i] = lst;
	//	cout << a[i] << " ";
	}
/*	cout << endl;
	for(int i = 0; i < n; i++)
		cout << i - a[i] << " ";
	cout << endl;*/
	for(int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + (i - a[i]);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int l , r;
		scanf("%d%d", &l, &r);
		l--;
		ll res = 0;
		ll k = lower_bound(a , a + n , l) - a;
		if(k < r)
			res += sum[r] - sum[max(k , (ll)l)];
		k = min(k , (ll)r);
		if(l <= k)
			res += (ll)(k - l) * (k - l + 1) / 2;
		printf("%I64d\n" , res);
	}
}