#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;

struct node
{
	ll lazy , mn , tmn;
	node()
	{
		lazy = 0;
		mn = 0;
		tmn = 0;
	}
};

node seg[maxn * 4] , void_node;

vector<int> adj[maxn] , work[maxn];

int st[maxn] , ft[maxn] , id = -1 , v1[maxn] , v2[maxn] , ans[maxn] , n;

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].tmn = 1;
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	
	seg[v].tmn = e - s;
}

node merge(node a , node b)
{
	node c;
	c.mn = min(a.mn , b.mn);
	c.tmn = ((a.mn == c.mn)? a.tmn : 0) + ((b.mn == c.mn)? b.tmn : 0);
	return c;
}

void ok(int v , int val)
{
	seg[v].lazy += val;
	seg[v].mn += val;
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

void add(int l , int r , int val , int s , int e , int v)
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
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);
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

void pre_dfs(int v , int p = -1)
{
	st[v] = ++id;
	for(auto u : adj[v])
		if(u != p)
			pre_dfs(u , v);
	ft[v] = id + 1;
}

void dfs(int v , int p = -1)
{
	for(auto x : work[v])
	{
		add(st[v1[x]] , ft[v1[x]] , 1 , 0 , n , 1);
		add(st[v2[x]] , ft[v2[x]] , 1 , 0 , n , 1);
	}
	int tmp = get(st[v] , st[v] + 1 , 0 , n , 1).mn;
	if(tmp == 0)
		ans[v] = 0;
	else
	{
		node x = get(0 , n , 0 , n , 1);
		if(x.mn == 0)
			ans[v] = n - x.tmn - 1;
		else
			ans[v] = n - 1;
	}
	for(auto u : adj[v])
		if(u != p)
			dfs(u , v);
	for(auto x : work[v])
	{
		add(st[v1[x]] , ft[v1[x]] , -1 , 0 , n , 1);
		add(st[v2[x]] , ft[v2[x]] , -1 , 0 , n , 1);
	}
}

int main()
{
	void_node.mn = 1e16;
	int q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	pre_dfs(0);
	build(0 , n , 1);

	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &v1[i], &v2[i]);
		v1[i]--;
		v2[i]--;
		work[v1[i]].pb(i);
		work[v2[i]].pb(i);
	}
	dfs(0);

	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	cout << endl;
}