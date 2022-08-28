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

const int N = (int)2e5;

int n, m;
vector<int> graph[N];
vector<int> rev_graph[N];
int type[N];

bool can_finish[N];
bool used[N];

void dfs1(int v)
{
	can_finish[v] = true;
	
	if (type[v] == 1)
		return;

	for (int to : rev_graph[v])
		if (!can_finish[to])
			dfs1(to);
}

void dfs2(int v)
{
	used[v] = true;

	for (int to : graph[v])
		if (!used[to])
			dfs2(to);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &type[i]);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		rev_graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (type[i] == 2 && !can_finish[i])
			dfs1(i);

	for (int i = 1; i <= n; i++)
		if (type[i] == 1 && !used[i])
			dfs2(i);

	for (int i = 1; i <= n; i++)
	{
		if (used[i] && can_finish[i])
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}