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

const int N = (int) 4e5 + 100;
vector <int> g[N];
int c[N];
char str[N];
vector <int> nxt[N];

const int ALP = 27;
int sz[N];
int ch[N][ALP];

int dfsSz(int a)
{
	int ans = 1;
	for (int i = 0; i < ALP; i++)
		if (ch[a][i] != -1)
			ans += dfsSz(ch[a][i] );
	return ans;
}

void dfsM(int a, int b, int A)
{
//	eprintf("a = %d, b = %d, A = %d\n", a, b, A);
	for (int i = 0; i < ALP; i++)
	{
		if (ch[b][i] == -1)
			continue;
		if (ch[a][i] == -1)
		{
			ch[a][i] = ch[b][i];
			sz[A] += dfsSz(ch[b][i]);
			continue;
		}
		dfsM(ch[a][i], ch[b][i], A);
	}
}

int merge(int a, int b)
{
	if (sz[a] < sz[b] )
		swap(a, b);

//	eprintf("merge %d and %d\n", a, b);
	dfsM(a, b, a);
	return a;
}

bool cmp(const int &a, const int &b)
{
	if (str[a] != str[b] )
		return str[a] < str[b];
	return a < b;
}


const long long INF = (long long) 1e18;
long long ans = -INF, ansCnt = 0;

void dfs(int v, int par)
{
//	eprintf("v = %d, par = %d\n", v, par);
	for (int nv : g[v] )
	{
		if (nv == par)
			continue;
		dfs(nv, v);
		nxt[v].push_back(nv);
	}
	sort(nxt[v].begin(), nxt[v].end(), cmp);
	int pos = 0;
	sz[v] = 1;
	for (int i = 0; i < ALP; i++)
	{
		ch[v][i] = -1;
		while (pos < (int) nxt[v].size() && str[nxt[v][pos] ] == i)
		{
			int nv = nxt[v][pos++];
			if (ch[v][i] == -1)
			{
				ch[v][i] = nv;
				continue;
			}
			ch[v][i] = merge(ch[v][i], nv);
		}
		if (ch[v][i] != -1)
			sz[v] += sz[ch[v][i] ];
	}
	long long curAns = c[v] + sz[v];
//	eprintf("v = %d, curAns = %d\n", v, curAns);
	if (curAns > ans)
	{
		ans = curAns;
		ansCnt = 0;
	}
	if (curAns == ans)
		ansCnt++;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i] );
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		str[i] -= 'a';
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

	printf("%lld\n%lld\n", ans, ansCnt);

	return 0;
}