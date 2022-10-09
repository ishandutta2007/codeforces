#include <bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef unsigned int ui;
int goal[maxn];
vector <int> v[maxn];
bool odw[maxn];
vector <int> top;
int parent[maxn];
int flipped[maxn];
int value[maxn];
void dfs(int x)
{
	odw[x] = true;
	top.push_back(x);
	for (ui i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i]]) 
	  {
		  parent[v[x][i]] = x;
		  dfs(v[x][i]);
	  }
	
}
int n;
vector <int> wyn;
int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; ++i)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		v[b].push_back(a);
		v[a].push_back(b);
	}
	dfs(1);
	parent[1] = 0;
	for (int i=1; i<=n; ++i) scanf("%d", &value[i]);
	for (int i=1; i<=n; ++i) scanf("%d", &goal[i]);
	for (ui i=0; i<top.size(); ++i) 
	{
		int x = top[i];
		
		if (parent[parent[x]] != 0)
		  if (flipped[parent[parent[x]]]) flipped[x] = 1;
		if (flipped[x] == 1) value[x] = 1- value[x];
		if (value[x] != goal[x])
		{
			flipped[x] = 1 - flipped[x];
			wyn.push_back(x);
		}
	}
	int dl = wyn.size();
	printf("%d\n", dl);
	for (int i=0; i<dl; ++i) printf("%d\n", wyn[i]);
}