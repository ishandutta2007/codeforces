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


const int LOG = 18;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct Tree
{
	int mx[SZ];
	int add[SZ];

	Tree() : mx(), add() {}

	void addV(int v, int val)
	{
		mx[v] += val;
		add[v] += val;
	}

	void push(int v)
	{
		if (add[v] == 0 || v >= LEVEL) return;
		addV(2 * v, add[v] );
		addV(2 * v + 1, add[v] );
		add[v] = 0;
	}

	void update(int v)
	{
		mx[v] = max(mx[2 * v], mx[2 * v + 1] );
	}

	void fadd(int v, int l, int r, int val, int tl, int tr)
	{
		if (tr < l || r < tl) return;
		if (l <= tl && tr <= r)
		{
			addV(v, val);
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		fadd(2 * v, l, r, val, tl, tm);
		fadd(2 * v + 1, l, r, val, tm + 1, tr);
		update(v);
	}

	void fadd(int l, int r, int val)
	{
		fadd(1, l, r, val, 0, LEVEL - 1);
	}

	int last()
	{
		int v = 1;
		if (mx[v] <= 0) return -1;
		while (v < LEVEL)
		{
			push(v);
			if (mx[2 * v + 1] > 0)
				v = 2 * v + 1;
			else
				v = 2 * v;
		}
		return v - LEVEL;
	}

} tree;


const int N = (int) 1e5 + 100;
int val[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int it = 0; it < n; it++)
	{
		int i, t;
		scanf("%d%d", &i, &t);
		i--;
		if (t == 0) // pop
		{
			tree.fadd(0, i, -1);
		}
		else if (t == 1)
		{
			int x;
			scanf("%d", &x);
			val[i] = x;
			tree.fadd(0, i, 1);
		}
		else throw;

		int id = tree.last();
		if (id == -1)
			printf("-1\n");
		else
			printf("%d\n", val[id] );
	}




	return 0;
}