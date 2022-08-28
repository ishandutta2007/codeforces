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


const int maxn = (int) 2e5 + 100;

vector <int> g[2 * maxn];
int e[maxn][2];
int ptr[maxn];
char ans[maxn];

int getOth(int eid, int v)
{
	return (e[eid][0] ^ e[eid][1] ^ v);
}

bool dfs(int v, int color)
{
	while (!g[v].empty() )
	{
		int eid = g[v].back();
		g[v].pop_back();
		if (ans[eid] != 0)
			continue;
		ans[eid] = color;
		int nv = getOth(eid, v);
		dfs(nv, color ^ 3);
		return true;
	}
	return false;
}


int main(int, char **)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		y += maxn;
		g[x].push_back(i);
		g[y].push_back(i);
		e[i][0] = x;
		e[i][1] = y;
	}
	for (int i = 0; i < 2 * maxn; i++)
	{
		int color = 1;
		while (dfs(i, color) )
			color ^= 3;
	}

	for (int i = 0; i < n; i++)
		if (ans[i] == 1)
			ans[i] = 'b';
		else
			ans[i] = 'r';

	printf("%s\n", ans);

	return 0;
}