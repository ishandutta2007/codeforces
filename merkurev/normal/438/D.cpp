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

const int pow2 = (1 << 20);

struct IntervalTree
{
	int64 sum[pow2 * 2];
	pair<int, int> max_val[pow2 * 2];

	IntervalTree()
	{
		for (int i = pow2; i < pow2 * 2; i++)
		{
			sum[i] = 0;
			max_val[i] = make_pair(0, i);
		}

		for (int i = pow2 - 1; i >= 1; i--)
		{
			sum[i] = sum[i * 2] + sum[i * 2 + 1];
			max_val[i] = max(max_val[i * 2], max_val[i * 2 + 1]);
		}
	}

	void set(int pos, int val)
	{
		pos += pow2;
		sum[pos] = val;
		max_val[pos] = make_pair(val, pos - pow2);
		pos /= 2;
		while (pos >= 1)
		{
			sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
			max_val[pos] = max(max_val[pos * 2], max_val[pos * 2 + 1]);
			pos /= 2;
		}
	}

	int64 get_sum(int a, int b)
	{
		return get_sum(1, 0, pow2 - 1, a, b);
	}

	int64 get_sum(int v, int l, int r, int a, int b)
	{
		if (l > b || r < a)
			return 0;
		if (a <= l && r <= b)
			return sum[v];
		int m = (l + r) / 2;
		return get_sum(v * 2, l, m, a, b) + get_sum(v * 2 + 1, m + 1, r, a, b);
	}

	pair<int, int> get_max(int a, int b)
	{
		return get_max(1, 0, pow2 - 1, a, b);
	}

	pair<int, int> get_max(int v, int l, int r, int a, int b)
	{
		if (l > b || r < a)
			return make_pair(0, 0);
		if (a <= l && r <= b)
			return max_val[v];
		int m = (l + r) / 2;
		return max(get_max(v * 2, l, m, a, b),
				get_max(v * 2 + 1, m + 1, r, a, b));
	}
};

int n, m;
IntervalTree tree;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		tree.set(i, a);
	}

	for (int i = 0; i < m; i++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", tree.get_sum(l, r));
		}
		else if (type == 2)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			while (true)
			{
				auto p = tree.get_max(l, r);
				if (p.first < x)
					break;
				tree.set(p.second, p.first % x);
			}
		}
		else
		{
			int k, x;
			scanf("%d%d", &k, &x);
			tree.set(k, x);
		}
	}

	return 0;
}