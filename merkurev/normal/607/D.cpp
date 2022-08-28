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

const int ADD_V = 1;
const int Q = 2;

struct Task
{
	int type, vertex, value;
	Task() : type(), vertex(), value() {}

	void read()
	{
		scanf("%d%d", &type, &vertex);
		if (type == ADD_V)
			scanf("%d", &value);
	}
};

const int N = (int) 2e5 + 100;
int vvalue[N];
vector <int> g[N];
int leu[N], reu[N];
Task task[N];
int ch[N];
int par[N];


const int mod = (int) 1e9 + 7;
int mul(int x, int y)
{
	return (x * 1LL * y) % mod;
}
void add(int &x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}
int sum(int x, int y)
{
	add(x, y);
	return x;
}
int fpow(int x, int n)
{
	if (n == 0)
		return 1;
	int a = fpow(x, n >> 1);
	a = mul(a, a);
	if (n & 1)
		a = mul(a, x);
	return a;
}
int rev(int x)
{
	return fpow(x, mod - 2);
}

const int ST = 18;
const int LEVEL = (1 << ST);
const int SZ = (LEVEL << 1);

struct Tree
{
	int tree[SZ];
	int toAdd[SZ];
	int toMul[SZ];

	Tree() : tree(), toAdd(), toMul()
	{
		for (int i = 0; i < SZ; i++)
			toMul[i] = 1;
	}

	void push(int v)
	{
		if (toMul[v] == 1 && toAdd[v] == 0)
			return;
		eprintf("v = %d, tree[v] = %d, toMul[v] = %d, toAdd[v] = %d\n", v, tree[v], toMul[v], toAdd[v] );
		for (int i = 2 * v; i <= 2 * v + 1; i++)
		{
			eprintf("i = %d, tree[i] = %d\n", i, tree[i] );
			tree[i] = sum(toAdd[v], mul(tree[i], toMul[v] ) );
			toMul[i] = mul(toMul[i], toMul[v] );
			toAdd[i] = sum(toAdd[v], mul(toAdd[i], toAdd[v] ) );
			eprintf("i = %d, tree[i] = %d\n", i, tree[i] );
		}
		toMul[v] = 1;
		toAdd[v] = 0;
	}
	void update(int v)
	{
		tree[v] = sum(tree[2 * v], tree[2 * v + 1] );
	}

	int getSum(int v, int l, int r, int tl, int tr)
	{
		if (r <= tl || l >= tr)
			return 0;
		if (l <= tl && tr <= r)
			return tree[v];
		push(v);
		int tm = (tl + tr) / 2;
		int ans1 = getSum(2 * v, l, r, tl, tm);
		int ans2 = getSum(2 * v + 1, l, r, tm, tr);
		return sum(ans1, ans2);
	}
	void addVal(int v, int l, int r, int val, int tl, int tr)
	{
		if (r <= tl || l >= tr)
			return;
		if (l <= tl && tr <= r)
		{
			add(tree[v], val);
			add(toAdd[v], val);
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		addVal(2 * v, l, r, val, tl, tm);
		addVal(2 * v + 1, l, r, val, tm, tr);
		update(v);
	}
	void mulVal(int v, int l, int r, int val, int tl, int tr)
	{
		if (r <= tl || l >= tr)
			return;
		if (l <= tl && tr <= r)
		{
			tree[v] = mul(tree[v], val);
			toAdd[v] = mul(toAdd[v], val);
			toMul[v] = mul(toMul[v], val);
			eprintf("v = %d, val = %d, tree[v] = %d\n", v, val, tree[v] );
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		mulVal(2 * v, l, r, val, tl, tm);
		mulVal(2 * v + 1, l, r, val, tm, tr);
		update(v);
	}


	int getSum(int l, int r)
	{
		return getSum(1, l, r, 0, LEVEL);
	}
	void mulVal(int l, int r, int val)
	{
		mulVal(1, l, r, val, 0, LEVEL);
	}
	void addVal(int pos, int val)
	{
		addVal(1, pos, pos + 1, val, 0, LEVEL);
	}
} tree, koef;

int timer = 1;

void dfs(int x)
{
	leu[x] = timer++;
	
	for (int to : g[x] )
		dfs(to);

	reu[x] = timer;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int q;
	scanf("%d%d", &vvalue[1], &q);
	
	for (int i = 0; i < q; i++)
	{
		task[i].read();
	}
	int n = 1;
	for (int i = 0; i < q; i++)
	{
		if (task[i].type == Q)
			continue;
		int id = ++n;
//		eprintf("par = %d, to = %d\n", task[i].vertex, id);
		par[id] = task[i].vertex;
		g[task[i].vertex].push_back(id);
		vvalue[id] = task[i].value;
	}
	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		ch[i] = 1;
		koef.addVal(i, 1);
	}


	tree.addVal(leu[1], vvalue[1] );

	n = 1;
	for (int i = 0; i < q; i++)
	{
		if (task[i].type == Q)
		{
			int id = task[i].vertex;
			int sum = tree.getSum(leu[id], reu[id] );
			int k;
			if (id == 1)
				k = 1;
			else
				k = koef.getSum(leu[par[id] ], leu[par[id] ] + 1);
			eprintf("sum = %d, k = %d\n", sum, k);
			int ans = mul(sum, rev(k) ); 
			printf("%d\n", ans);
			eprintf("\n\n");
			continue;
		}
		int id = ++n;
		int a = task[i].vertex;
		int k = koef.getSum(leu[id], leu[id] + 1);
		int x = mul(k, vvalue[id] );
		int y = mul(ch[a] + 1, rev(ch[a] ) );
		eprintf("koef[%d] = %d\n", leu[id], k);
		eprintf("id = %d, a = %d, k = %d, x = %d, y = %d\n", id, a, k, x, y);
		tree.addVal(leu[id], x);
		tree.mulVal(leu[a], reu[a], y);
		koef.mulVal(leu[a], reu[a], y);
		eprintf("[%d, %d) x= %d\n", leu[a], reu[a], y);
		eprintf(">>> %d\n", koef.getSum(2, 3) );
		ch[a]++;
		eprintf("\n\n");
	}


	return 0;
}