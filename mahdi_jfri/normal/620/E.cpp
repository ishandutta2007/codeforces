#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 4e5 + 20;

struct node
{
	ll lazy , val;
	node()
	{
		lazy = 0;
		val = 0;
	}
};

node seg[maxn * 4] , void_node;
vector<int> adj[maxn];
int c[maxn] , id = -1 , st[maxn] , ft[maxn] , rst[maxn];

void dfs(int v , int p = -1)
{
	st[v] = ++id;
	rst[id] = v;
	for(auto u : adj[v])
		if(u != p)
			dfs(u , v);
	ft[v] = id;
}

node merge(node a, node b)
{
	node c;
	c.val = a.val | b.val;
	return c;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].val = (1LL << c[rst[s]]);
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

void ok(int v , ll val)
{
	seg[v].lazy = val;
	seg[v].val = val;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && seg[v].lazy)
	{
		ok(2 * v , seg[v].lazy);
		ok(2 * v + 1 , seg[v].lazy);
	}
	seg[v].lazy = 0;
}

void update(int l , int r , ll val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		ok(v , val);
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

node get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return void_node;
	shift(s , e , v);
	int m = (s + e) / 2;
	return merge(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int f(ll val)
{
	int res = 0;
	while(val)
	{
		val -= val & -val;
		res++;
	}
	return res;
}

int main()
{
	int n , q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]) , c[i]--;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	dfs(0);

	build(0 , n , 1);

	while(q--)
	{
		int type;
		scanf("%d", &type);
		if(type == 1)
		{
			int v , c;
			scanf("%d%d", &v, &c);
			v--;
			c--;
			update(st[v] , ft[v] + 1 , (1LL << c) , 0 , n , 1);
		}
		else
		{
			int v;
			scanf("%d", &v);
			v--;
			printf("%d\n", f(get(st[v] , ft[v] + 1 , 0 , n , 1).val));
		}
	}
}