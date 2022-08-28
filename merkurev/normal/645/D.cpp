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


const int N = (int) 1e5 + 100;
int e[N][2];
int n;
int degIn[N];
int qu[N];
int quSz;
vector <int> g[N];

bool canOrder(int m)
{
	quSz = 0;
	memset(degIn, 0, sizeof degIn);
	for (int i = 0; i < n; i++)
		g[i].clear();

	for (int i = 0; i < m; i++)
	{
		g[e[i][0] ].push_back(e[i][1] );
		degIn[e[i][1] ]++;
	}

	for (int i = 0; i < n; i++)
		if (degIn[i] == 0)
			qu[quSz++] = i;

	for (int i = 0; i < n; i++)
	{
		if (quSz > i + 1) return false;
		int v = qu[i];
		for (int to : g[v] )
		{
			degIn[to]--;
			if (degIn[to] == 0)
				qu[quSz++] = to;
		}
	}
	return true;
}



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		e[i][0] = a;
		e[i][1] = b;
	}

	int lb = 0, rb = m + 1;
	while (rb - lb > 1)
	{
		int mb = (lb + rb) / 2;
		if (canOrder(mb) )
			rb = mb;
		else
			lb = mb;
	}
	if (rb == m + 1)
		rb = -1;
	printf("%d\n", rb);

	return 0;
}