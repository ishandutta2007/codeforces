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


const int N = 1005;
int f[N][N];
int s[N][N];
const int LOG = 10;
int sp[LOG][N][N];
int lg[N];

const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct Tree
{
	int mx[SZ];

	Tree() : mx() {}

	void build(int a[N] )
	{
		for (int i = 0; i < N; i++)
			mx[LEVEL + i] = a[i];
		for (int i = LEVEL - 1; i >= 1; i--)
			mx[i] = max(mx[2 * i], mx[2 * i + 1] );
	}

	int getMax(int v, int l, int r, int tl, int tr)
	{
		if (tr < l || tl > r)
			return 0;
		if (l <= tl && tr <= r)
			return mx[v];
		int tm = (tl + tr) / 2;
		return max(getMax(2 * v, l, r, tl, tm), getMax(2 * v + 1, l, r, tm + 1, tr));
	}

	int getMax(int l, int r) // segment
	{
		return getMax(1, l, r, 0, LEVEL - 1);
	}
} tree[LOG][N];


int getMax(int x1, int y1, int x2, int y2)
{
	int l = lg[x2 - x1 + 1];
	return max(tree[l][x1].getMax(y1, y2), tree[l][x2 - (1 << l) + 1].getMax(y1, y2) );
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &f[i][j] );

	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
		{
			if (f[i][j] == 0) continue;
			s[i][j] = min({s[i + 1][j], s[i][j + 1], s[i + 1][j + 1]}) + 1;
		}

	lg[1] = 0;
	for (int i = 2; i <= max(n, m); i++)
	{
		lg[i] = lg[i - 1];
		if ((1 << (lg[i] + 1) ) <= i)
			lg[i]++;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sp[0][i][j] = s[i][j];
	for (int l = 1; l < LOG; l++)
		for (int i = 0; i + (1 << l) <= n; i++)
			for (int j = 0; j < m; j++)
				sp[l][i][j] = max(sp[l - 1][i][j], sp[l - 1][i + (1 << (l - 1))][j]);
	
	for (int l = 0; l < LOG; l++)
		for (int i = 0; i < n; i++)
			tree[l][i].build(sp[l][i] );
	
	
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		x2--;
		y2--;
		int lb = 0, rb = min(y2 - y1 + 1, x2 - x1 + 1) + 1;
		while (rb - lb > 1)
		{
			int mb = (lb + rb) / 2;
			int x = getMax(x1, y1, x2 - mb + 1, y2 - mb + 1);
			if (x >= mb)
				lb = mb;
			else
				rb = mb;
		}
		printf("%d\n", lb);
	}

	return 0;
}