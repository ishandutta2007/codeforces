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

const int INF = (long long) 1e9;

const int N = 2005;
int d[N][N];
int ans[N];
int used[N][N];

vector <pair <int, int> > g[N];


int solve(int, int);

int solveId(int v, int id)
{
	if (id < 0) return INF;
	if (used[v][id] != -1) return used[v][id];
	int answ = solveId(v, id - 1);
	answ = min(answ, 
			solve(g[v][id].second, g[v][id].first) + g[v][id].first);
	return used[v][id] = answ;
}

int solve(int v, int cd)
{
	int answer = cd;
	int id = upper_bound(g[v].begin(), g[v].end(), make_pair(cd, -1) ) - g[v].begin();
	return min(answer, solveId(v, id - 1) );
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	memset(used, -1, sizeof used);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			d[i][j] = d[j][i] = x;
		}
	int mn = d[0][1];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			mn = min(mn, d[i][j] );
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			d[i][j] -= mn;
			d[j][i] -= mn;
			g[i].emplace_back(d[i][j], j);
			g[j].emplace_back(d[j][i], i);
		}
	for (int i = 0; i < n; i++)
		sort(g[i].begin(), g[i].end() );

	for (int i = 0; i < n; i++)
	{
		ans[i] = INF;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			ans[i] = min(ans[i], solve(j, d[i][j] ) + d[i][j] );
		}
	}

	for (int i = 0; i < n; i++)
		printf("%lld\n", ans[i] + mn * 1LL * (n - 1) );

	return 0;
}