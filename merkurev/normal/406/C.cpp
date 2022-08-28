#include <iostream>
#include <vector>
using namespace std;

#pragma comment(linker, "/STACK:100500500")

const int maxn = 1e5 + 100;

vector <int> tree[maxn];
vector <int> g[maxn];
int cure[maxn];

int e[maxn][2];
vector <int> ans[3];
bool usede[maxn];
bool used[maxn];


bool dfs(int v, int par = -1)
{
	used[v] = true;
	vector <int> ch;
	for (int i = 0; i < tree[v].size(); i++)
	{
		int nv = tree[v][i];
		if (nv == par)
			continue;
		if (!dfs(nv, v) )
			ch.push_back(nv);
	}
	while (ch.size() > 1)
	{
		int a = ch.back();
		ch.pop_back();
		int b = ch.back();
		ch.pop_back();
		ans[0].push_back(a);
		ans[1].push_back(v);
		ans[2].push_back(b);
	}
	while (cure[v] < g[v].size() && usede[g[v][cure[v] ] ] )
		cure[v]++;
	if (cure[v] == g[v].size() ) 
	{                           
		if (ch.size() == 0)
			return false;
		int a = par;
		int b = ch[0];
		ans[0].push_back(a);
		ans[1].push_back(v);
		ans[2].push_back(b);
		return true;
	}
	int ed = g[v][cure[v] ];
	usede[ed] = true;
	int a = e[ed][0] + e[ed][1] - v;

	if (ch.size() != 0)
	{                               
		int b = ch[0];
		ans[0].push_back(a);
		ans[1].push_back(v);
		ans[2].push_back(b);
		return false;
	}
	int b = par;
	ans[0].push_back(a);
	ans[1].push_back(v);
	ans[2].push_back(b);
	return true;
	
		
}



int par[maxn];

int getP(int x)
{                                      
	if (x != par[x] )
		par[x] = getP(par[x] );
	return par[x];
}

bool uni(int a, int b)
{
	a = getP(a);
	b = getP(b);
	if (a == b)
		return false;
	if (rand() & 1)
		swap(a, b);
	par[a] = b;
	return true;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif                             
		

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		par[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		e[i][0] = a;
		e[i][1] = b;
		if (uni(a, b) )
		{
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		else
		{
			g[a].push_back(i);
			g[b].push_back(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			while (cure[i] < g[i].size() && usede[g[i][cure[i] ] ] )
				cure[i] ++;
			if (cure[i] == g[i].size() )
				break;
			int a = g[i][cure[i] ];
			usede[a] = true;

			while (cure[i] < g[i].size() && usede[g[i][cure[i] ] ] )
				cure[i] ++;
			if (cure[i] == g[i].size() )
			{
				usede[a] = false;
				break;
			}

			int b = g[i][cure[i] ];                                                
			usede[b] = true;

			ans[0].push_back(e[a][0] + e[a][1] - i);
			ans[1].push_back(i);
			ans[2].push_back(e[b][0] + e[b][1] - i);	
		}
		cure[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] )
			continue;
		if (dfs(i) )
		{
			printf("No solution");
			return 0;
		}
	}
	
	for (int i = 0; i < ans[0].size(); i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", ans[j][i] + 1);
		printf("\n");
	}




	return 0;
}