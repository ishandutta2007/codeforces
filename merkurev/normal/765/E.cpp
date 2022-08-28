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
vector <int> g[N];


void dfs(int v, int par, int cd, int d[] )
{
	d[v] = cd;
	for (int to : g[v] )
	{
		if (to == par) continue;
		dfs(to, v, cd + 1, d);
	}
}

int dfsCheck(int v, int par)
{
	vector <int> ds;
	for (int to : g[v] )
	{
		if (to == par) continue;
		ds.push_back(dfsCheck(to, v) );	
	}
	sort(ds.begin(), ds.end() );
	ds.resize(unique(ds.begin(), ds.end() ) - ds.begin() );
	if (v != par)
	{
//		eprintf("v = %d, par = %d, ds.size() = %d\n", v, par, (int) ds.size() );
		if ( (int) ds.size() > 1)
		{
			printf("-1\n");
			exit(0);
		}
		if (ds.empty() ) return 1;
		return ds[0] + 1;
	}
	if (ds.empty() ) return 0;
	if ( (int) ds.size() > 2) return -1;
	return ds[0] + ds.back();
}

int d0[N];
int da[N];
int db[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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
	dfs(0, 0, 0, d0);
	int a = 0;
	for (int i = 0; i < n; i++)
		if (d0[i] > d0[a] )
			a = i;
	dfs(a, a, 0, da);
	int b = a;
	for (int i = 0; i < n; i++)
		if (da[i] > da[b] )
			b = i;
	dfs(b, b, 0, db);
	int c = b;
	for (int i = 0; i < n; i++)
		if (db[i] + da[i] == db[a] && min(db[i], da[i] ) > min(db[c], da[c] ) )
			c = i;
//	eprintf("a = %d, b = %d, c = %d\n", a, b, c);
	
	int ans = dfsCheck(c, c);
	while (ans % 2 == 0 && ans > 0)
		ans /= 2;
	printf("%d\n", ans);

	return 0;
}