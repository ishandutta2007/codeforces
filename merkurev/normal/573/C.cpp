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

const int maxn = (int) 1e5 + 100;
vector <int> g[maxn], G[maxn];
int type[maxn];
int cntIn[maxn];

void no()
{
	printf("No");
	exit(0);
}


void yes()
{
	printf("Yes");
	exit(0);
}


void dfsG(int v, int par = -1)
{
	if ((int) G[v].size() > 2)
		no();
	type[v] = 3;
	for (int i = 0; i < (int) G[v].size(); i++)
	{
		int nv = G[v][i];
		if (nv == par)
			continue;
		dfsG(nv, v);
		break;
	}
}

void solve()
{
	int n;
	scanf("%d", &n);

	if (n <= 2)
		yes();

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	bool fnd = false;
	for (int i = 0; i < n; i++)
		if ((int) g[i].size() >= 3)
			fnd = true;
	if (!fnd)
		yes();

	for (int i = 0; i < n; i++)
		if ((int) g[i].size() == 1 && type[i] == 0)
		{
			type[i] = 1;
			int pv = i;
			int v = g[i][0];

			while ((int) g[v].size() == 2)
			{
				type[v] = 1;
				int nv = g[v][0] + g[v][1] - pv;
				pv = v;
				v = nv;
			}
			
			cntIn[v]++;
		}
	for (int i = 0; i < n; i++)
		if ((int) g[i].size() == 3 && cntIn[i] == 2)
		{
			type[i] = 2;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int) g[i].size(); j++)
		{
			int ni = g[i][j];
			if (type[i] == 0 && type[ni] == 0)
				G[i].push_back(ni);
		}
	int st = -1;
	for (int i = 0; i < n; i++)
		if (type[i] == 0 && (int) G[i].size() <= 1)
			st = i;
	if (st != -1)
		dfsG(st);
//	for (int i = 0; i < n; i++)
//		eprintf("%d ", type[i] );
//	eprintf("\n");
	for (int i = 0; i < n; i++)
		if (type[i] == 0)
			no();
	yes();
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}