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
const int maxn = 3005;
vector <int> g[maxn];
int d[maxn][maxn];
const int inf = (int) 1e6;
int qu[maxn];

void getD(int s, int *ds, int n)
{
	for (int i = 0; i < n; i++)
		ds[i] = inf;
	ds[s] = 0;
	int l = 0, r = 0;
	qu[r++] = s;
	while (l < r)
	{
		int v = qu[l++];
		for (int to : g[v] )
		{
			if (ds[to] == inf)
			{
				ds[to] = ds[v] + 1;
				qu[r++] = to;
			}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int s1, t1, l1, s2, t2, l2;
	scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
	s1--;
	t1--;
	s2--;
	t2--;
	for (int i = 0; i < n; i++)
		getD(i, d[i], n);

	if (d[s1][t1] > l1 || d[s2][t2] > l2)
	{
		printf("-1\n");
		return 0;
	}
	int ans = d[s1][t1] + d[s2][t2];

	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++)
		{
			int d1 = d[s1][a] + d[a][b] + d[b][t1];
			int d2 = d[s2][a] + d[a][b] + d[b][t2];
			if (d1 <= l1 && d2 <= l2)
			{
				ans = min(ans, d1 + d2 - d[a][b] );
			}
			d1 = d[s1][a] + d[a][b] + d[b][t1];
			d2 = d[s2][b] + d[a][b] + d[a][t2];
			
			if (d1 <= l1 && d2 <= l2)
			{
				ans = min(ans, d1 + d2 - d[a][b] );
			}
		}


	printf("%d\n", m - ans);
	return 0;
}