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



const int maxn = 405;
int g[maxn][maxn];

const int INF = (int) 1e9;
int dist[maxn];
int qu[maxn];

int bfs(int n)
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	int l = 0, r = 0;
	qu[r++] = 0;
	dist[0] = 0;

	while (r > l)
	{
		int v = qu[l++];
		for (int i = 0; i < n; i++)
			if (g[v][i] == 1 && dist[i] == INF)
			{
				dist[i] = dist[v] + 1;
				qu[r++] = i;
			}
	}
	return dist[n - 1];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a][b] = g[b][a] = 1;
	}
	int dst1 = bfs(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				g[i][j] ^= 1;
	int dst2 = bfs(n);
	int dst = max(dst1, dst2);
	if (dst == INF)
		dst = -1;
	printf("%d\n", dst);


	return 0;
}