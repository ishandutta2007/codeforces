#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 5e4 + 20;
const int sq = 256;
const int qs = maxn / sq + 5;
const int maxb = 10;

vector<int> adj[maxn] , tmp;

int x[maxn];

int a[maxn] , ans[maxn][qs];

int l[maxn * maxb] , r[maxn * maxb] , t[maxn * maxb] , mx[maxn * maxb];

int tah = 1 , par[maxn] , p[maxn] , h[maxn];

bool is[maxn * maxb];

void add(int val , int val2)
{
	int pos = 0;
	for(int i = 9; i >= -1; i--)
	{
		t[pos]++;
		mx[pos] = max(mx[pos] , val2);
		if(i < 0)
			return;
		if(!l[pos])
		{
			l[pos] = tah++;
			r[pos] = tah++;
			t[l[pos]] = t[r[pos]] = 0;
			mx[l[pos]] = mx[r[pos]] = -1;
			l[l[pos]] = l[r[pos]] = 0;
		}
		if(bit(val , i))
			pos = r[pos];
		else
			pos = l[pos];
	}
}

int get(int val , bool f)
{
	int pos = 0 , res = 0;
	for(int i = 9; i >= 0; i--)
	{
		res = res * 2;
		if(bit(val , i))
		{
			if(t[l[pos]])
				pos = l[pos];
			else
				pos = r[pos] , res++;
		}
		else
		{
			if(t[r[pos]])
				pos = r[pos] , res++;
			else
				pos = l[pos];
		}
	}
	return res * sq + mx[pos];
}

void dfs(int v)
{
	int u = v;
	l[0] = 0;
	tah = 1;
	t[0] = 0;
	mx[0] = -1;
	for(int i = 0; i < sq; i++)
	{
		add((a[u] ^ i) / sq , (a[u] ^ i) % sq);
		if(u == p[u])
			break;
		u = p[u];
	}
	par[v] = u;
	for(int i = 0; i < qs; i++)
		ans[v][i] = get(i , 0) ^ (sq * i);
	for(auto u : adj[v])
		if(u != p[v])
		{
			p[u] = v;
			h[u] = h[v] + 1;
			dfs(u);
		}
}

int main()
{
	int n , q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	dfs(0);
	while(q--)
	{
		int u , v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		int res = 0 , now = 0 , d = 0;
		while(h[par[v]] > h[u])
		{
			res = max(res , ans[v][now]);
			now++;
			v = par[v];
		}
		d = now * sq;
		while(h[v] > h[u])
		{
			res = max(res , a[v] ^ d);
			d++;
			v = p[v];
		}
		res = max(res , a[u] ^ d);
		printf("%d\n", res);
	}
}