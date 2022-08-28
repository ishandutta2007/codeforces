#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;
const int maxn = 5005;
int sz[maxn];

int n;
vector <int> g[maxn];
bool cb[maxn][maxn];
bool ans[maxn];

void dfs(int v, int par)
{
	sz[v] = 1;
	cb[v][0] = true;
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == par)
			continue;
		dfs(nv, v);
		sz[v] += sz[nv];
		for (int j = n; j >= 0; j--)
			if (cb[v][j] )
				cb[v][j + sz[nv] ] = true;
	}
	int oth = n - sz[v];
	for (int i = n; i >= 0; i--)
		if (cb[v][i] )
		{
			cb[v][i + oth] = true;
		}
	for (int i = 1; i < n - 1; i++)
		if (cb[v][i] )
			ans[i] = true;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

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
	dfs(0, -1);
	int answer = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (ans[i] )
			answer++;
	}
	printf("%d\n", answer);
	for (int i = 1; i < n - 1; i++)
		if (ans[i] )
			printf("%d %d\n", i, n - 1 - i);

	return 0;
}