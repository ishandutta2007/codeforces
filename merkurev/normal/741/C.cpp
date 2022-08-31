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
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 2e5 + 100;
int p[N];
int ans[N];
vector <int> g[N];

void dfs(int v, int col)
{
	ans[v] = col;
	for (int to : g[v] )
		if (ans[to] == 0)
			dfs(to, col ^ 3);
}

int par[N];
int sz[N];

int getP(int v)
{
	if (v == par[v] ) return v;
	return par[v] = getP(par[v] );
}

bool uni(int a, int b)
{
	a = getP(a);
	b = getP(b);
	if (a == b) return false;
	if (sz[a] < sz[b] )
		swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
	return true;
}

int a[N], b[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; i++)
	{
		sz[i] = 1;
		par[i] = i;
	}
	for (int i = 0; i < n / 2; i++)
	{
		scanf("%d%d", &a[i], &b[i] );
		a[i]--;
		b[i]--;
		g[a[i] ].push_back(b[i] );
		g[b[i] ].push_back(a[i] );
		uni(a[i], b[i] );
	}
	for (int i = 0; i < n; i += 2)
	{
		g[i].push_back(i + 1);
		g[i + 1].push_back(i);
		uni(i, i + 1);
	}
	for (int i = 1; i < n; i += 2)
	{
		int j = (i + 1) % n;
		if (uni(i, j) )
		{
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}

	dfs(0, 1);

	for (int i = 0; i < n / 2; i++)
		printf("%d %d\n", ans[a[i] ], ans[b[i] ] );

	return 0;
}