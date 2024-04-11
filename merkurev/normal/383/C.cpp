#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int pow2 = (1 << 19);
const int N = (int)4e5;

int add(int a, int b)
{
	int res = a + b;
	return res;
}

int sub(int a, int b)
{
	int res = a - b;
	return res;
}


struct IntervalTree
{
	int val[pow2 * 2];
	int flag[pow2 * 2];

	IntervalTree()
	{
		fill(val, val + pow2 * 2, 0);
		fill(flag, flag + pow2 * 2, 0);
	}

	void add_flag(int v, int aflag)
	{
		flag[v] = add(flag[v], aflag);
		val[v] = add(val[v], aflag);
	}

	void push(int v)
	{
		if (v < pow2)
		{
			add_flag(v * 2, flag[v]);
			add_flag(v * 2 + 1, flag[v]);
			flag[v] = 0;
		}
	}

	void add_seg(int a, int b, int aval)
	{
		add_seg(1, 0, pow2 - 1, a, b, aval);
	}

	void add_seg(int v, int l, int r, int a, int b, int aval)
	{
		push(v);

		if (l > b || r < a)
			return;

		if (a <= l && r <= b)
		{
			add_flag(v, aval);
			return;
		}

		int m = (l + r) / 2;
		add_seg(v * 2, l, m, a, b, aval);
		add_seg(v * 2 + 1, m + 1, r, a, b, aval);
	}

	int get(int a)
	{
		return get(1, 0, pow2 - 1, a);
	}

	int get(int v, int l, int r, int a)
	{
		push(v);

		if (l == r)
			return val[v];
		
		int m = (l + r) / 2;
		if (a <= m)
			return get(v * 2, l, m, a);
		return get(v * 2 + 1, m + 1, r, a);
	}
};

int n;
vector<int> graph[N];

int ptr;
int pos[N], size[N], h[N];

IntervalTree A, B;

void dfs(int v, int cur_h, int par)
{
	pos[v] = ptr++;
	size[v] = 1;
	h[v] = cur_h;

	for (int to : graph[v])
	{
		if (to == par)
			continue;
		dfs(to, cur_h + 1, v);
		size[v] += size[to];
	}
}

int val[N];



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int q;
	scanf("%d", &n);
	scanf("%d", &q);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	
	for (int i = 2; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0, -1);

	//for (int i = 1; i <= n; i++)
	//	printf("i = %d pos = %d size = %d h = %d\n", i, pos[i], size[i], h[i]);

	for (int i = 0; i < q; i++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int v, x;
			scanf("%d%d", &v, &x);
			int a = pos[v];
			int b = a + size[v] - 1;
			if (h[v] & 1)
			{
				x = -x;
			}
			A.add_seg(a, b, x);

		}
		else
		{
			int v;
			scanf("%d", &v);
			int ans = A.get(pos[v]);
			if (h[v] & 1)
			{
				ans = -ans;
			}
			printf("%d\n", ans + val[v] );
		}
	}

	return 0;
}