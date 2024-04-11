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


struct Mn
{
	int sz;
	int arr[11];
	Mn() : sz(0), arr() {}

	void add(int x)
	{
		int pos = sz;
		for (int i = 0; i < sz; i++)
		{
			if (arr[i] > x)
			{
				pos = i;
				break;
			}
		}
		for (int i = sz; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[pos] = x;
		if (sz < 10)
			sz++;
	}

	Mn(const Mn &A, const Mn &B)
	{
		sz = min(10, A.sz + B.sz);
		int pa = 0;
		int pb = 0;
		for (int i = 0; i < sz; i++)
		{
			if (pa == A.sz)
				arr[i] = B.arr[pb++];
			else if (pb == B.sz)
				arr[i] = A.arr[pa++];
			else if (A.arr[pa] < B.arr[pb] )
				arr[i] = A.arr[pa++];
			else
				arr[i] = B.arr[pb++];
		}
	}

	void print(int b)
	{
		printf("%d ", min(b, sz) );
		for (int i = 0; i < min(b, sz); i++)
			printf("%d ", arr[i] + 1);
		printf("\n");
	}
};

const int LOG = 18;
const int maxn = (int) 1e5 + 100;
vector <int> g[maxn];
int par[maxn][LOG];
Mn parMn[maxn][LOG];
int h[maxn];


void dfs(int v, int p = -1, int ch = 0)
{
	h[v] = ch;
	par[v][0] = p;
	for (int i = 1; i < LOG; i++)
	{
		par[v][i] = par[par[v][i - 1] ][i - 1];
		parMn[v][i] = Mn(parMn[v][i - 1], parMn[par[v][i - 1] ][i - 1] );
	}
	for (int i = 0; i < (int) g[v].size(); i++)
	{
		int nv = g[v][i];
		if (nv == p)
			continue;
		dfs(nv, v, ch + 1);
	}
}


int goUp(int v, int d)
{
	for (int i = 0; i < LOG; i++)
		if (d & (1 << i) )
			v = par[v][i];
	return v;
}

int getLCA(int a, int b)
{
	if (h[a] < h[b] )
	{
		swap(a, b);
	}
	a = goUp(a, h[a] - h[b] );
	if (a == b)
		return a;
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (par[a][i] != par[b][i] )
		{
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

Mn getMn(int v, int d)
{
	Mn ans = Mn();
	for (int i = 0; i < LOG; i++)
		if (d & (1 << i) )
		{
			ans = Mn(ans, parMn[v][i] );
			v = par[v][i];
		}
	return ans;
}

Mn getAns(int a, int b)
{
	int l = getLCA(a, b);
	Mn X = getMn(a, h[a] - h[l] );
	Mn Y = getMn(b, h[b] - h[l] );
	Mn Z = parMn[l][0];
	return Mn(Z, Mn(X, Y) );
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		parMn[x][0].add(i);
	}

	dfs(0);

	for (int i = 0; i < q; i++)
	{
		int x, y, a;
		scanf("%d%d%d", &x, &y, &a);
		x--;
		y--;
		Mn ans = getAns(x, y);
		ans.print(a);
	}

	return 0;
}