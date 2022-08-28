#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


const int maxn = 1e5 + 100;
vector <int> g[maxn];
int need[maxn];

vector <int> answer;

void dfs(int v, int par, int clickHere, int clickOther)
{
	bool isLeaf = true;
	need[v] ^= clickHere;
	if (need[v] )
	{
		clickHere ^= 1;
		answer.push_back(v + 1);
	}

	for (int i = 0; i < g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		isLeaf = false;
		dfs(nv, v, clickOther, clickHere);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &need[i] );
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		need[i] ^= x;
	}
	dfs(0, -1, 0, 0);
	printf("%d\n", answer.size() );
	for (int i = 0; i < answer.size(); i++)
		printf("%d\n", answer[i] );


	return 0;
}