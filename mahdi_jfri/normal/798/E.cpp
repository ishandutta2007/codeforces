#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 5e5 + 20;
const int maxm = maxn * 30;

vector<int> adj[maxm];

bool visited[maxm] , mark[maxn];

int id , a[maxn] , b[maxn] , vertex[maxn * 4] , topol[maxm];

void build(int s , int e , int v)
{
	vertex[v] = id++;
	if(e - s < 2)
	{
		adj[vertex[v]].pb(s);
		return;
	}
	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	adj[vertex[v]].pb(vertex[2 * v]);
	adj[vertex[v]].pb(vertex[2 * v + 1]);
}

void add(int l , int r , int u , int s , int e , int v)
{
	if(l >= r)
		return;
	if(l <= s && e <= r)
	{
		adj[u].pb(vertex[v]);
		return;
	}
	if(r <= s || e <= l)
		return;
	int m = (s + e) / 2;
	
	add(l , r , u , s , m , 2 * v);
	add(l , r , u , m , e , 2 * v + 1);
}

void rem(int p , int s , int e , int v)
{
	if(e - s < 2)
	{
		vertex[v] = id++;
		return;
	}
	int m = (s + e) / 2;

	vertex[v] = id++;

	if(p < m)
		rem(p , s , m , 2 * v);
	else
		rem(p , m , e , 2 * v + 1);

	adj[vertex[v]].pb(vertex[2 * v]);
	adj[vertex[v]].pb(vertex[2 * v + 1]);
}

void dfs(int v)
{
	visited[v] = 1;
	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
	topol[id++] = v;
}

int main()
{
	int n;
	scanf("%d", &n);
	id = n;

	build(0 , n , 1);

	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if(x == -1)
		{
			add(0 , i , i , 0 , n , 1);
			add(i + 1 , n , i , 0 , n , 1);
		}
		else
		{
			x--;
			adj[x].pb(i);
			mark[x] = 1;
			if(x < i)
				add(0 , x , i , 0 , n , 1);
			else
			{
				add(0 , i , i , 0 , n , 1);
				add(i + 1 , x , i , 0 , n , 1);
			}
			rem(x , 0 , n , 1);
		}
		b[i] = x;
	}
	id = 0;
	for(int i = 0; i < maxm; i++)
		if(!visited[i])
			dfs(i);
	int cnt = 0;
	for(int i = 0; i < maxm; i++)
		if(topol[i] < n)
			a[topol[i]] = cnt , cnt++;

	for(int i = 0; i < n; i++)
		cout << a[i] + 1 << " ";
	cout << endl;
}