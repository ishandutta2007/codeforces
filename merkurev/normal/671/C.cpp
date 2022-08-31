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

const int ST = 18;
const int LEVEL = (1 << ST);
const int SZ = (LEVEL << 1);

struct Tree
{
	long long toSet[SZ];
	long long sum[SZ], mn[SZ], mx[SZ];
	Tree () : toSet(), sum(), mn(), mx() 
	{
		memset(toSet, -1, sizeof toSet);
	}

	void update(int v)
	{
		mn[v] = min(mn[2 * v], mn[2 * v + 1] );
		mx[v] = max(mx[2 * v], mx[2 * v + 1] );
		sum[v] = sum[2 * v] + sum[2 * v + 1];
	}

	void updMax(int v, int tl, int tr, int l, int r, long long val)
	{
//		eprintf("%d : %d - %d\n", v, tl, tr);
//		eprintf("mn = %lld, mx = %lld, sum = %lld\n", mn[v], mx[v], sum[v] );
//		eprintf("l = %d, r = %d, val = %lld\n", l, r, val);
//		eprintf("\n");
		if (r < tl || l > tr) return;
		if (mn[v] >= val) return;
		if (mx[v] <= val && l <= tl && tr <= r)
		{
			push(v, tl, tr, val);
			return;
		}
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		updMax(2 * v, tl, tm, l, r, val);
		updMax(2 * v + 1, tm + 1, tr, l, r, val);
		update(v);
	}

	void updMax(int l, int r, int val)
	{
		updMax(1, 0, LEVEL - 1, l, r, val);
	}


	void push(int v, int tl, int tr, long long val)
	{
		toSet[v] = val;
		mn[v] = val;
		mx[v] = val;
		sum[v] = val * (tr - tl + 1);
	}

	void push(int v, int tl, int tr)
	{
		if (toSet[v] == -1) return;
		int tm = (tl + tr) / 2;
		push(2 * v, tl, tm, toSet[v] );
		push(2 * v + 1, tm + 1, tr, toSet[v] );
		toSet[v] = -1;
	}

	long long getSum(int v, int tl, int tr, int l, int r)
	{
		if (r < tl || l > tr) return 0;
		if (l <= tl && tr <= r) return sum[v];
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		return getSum(2 * v, tl, tm, l, r) + getSum(2 * v + 1, tm + 1, tr, l, r);
	}

	long long getSum(int l, int r)
	{
		if (l > r) return 0LL;
		return getSum(1, 0, LEVEL - 1, l, r);
	}


} tree;

const int N = (int) 2e5 + 100;
int a[N];
int r[N];

int n;

int pref[N], l[N];

void initPref()
{
	memset(l, -1, sizeof l);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int cur = a[i];
		for (int j = 1; j * j <= cur; j++)
		{
			if (cur % j != 0) continue;
			if (l[j] != -1)
				ans = max(ans, j);
			else
				l[j] = i;
			int x = cur / j;
			if (x != j)
			{
				if (l[x] != -1)
					ans = max(ans, x);
				else
					l[x] = i;
			}
		}
		pref[i + 1] = ans;
	}
	pref[0] = 1;
}

void initSuff()
{
	memset(r, -1, sizeof r);
	int ans = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		int cur = a[i];
		for (int j = 1; j * j <= cur; j++)
		{
			if (cur % j != 0) continue;
			if (r[j] != -1)
				ans = max(ans, j);
			else
				r[j] = i;
			int x = cur / j;
			if (x != j)
			{
				if (r[x] != -1)
					ans = max(ans, x);
				else
					r[x] = i;
			}
		}
//		eprintf("i = %d, ans = %d\n", i, ans);
		tree.updMax(i, i, ans);
	}
	tree.updMax(n, n, 1);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	initSuff();
	initPref();

	long long answer = 0;

	for (int i = 0; i < n; i++)
	{
		int rb = n;
		if (i == 0)
			rb -= 2;
		if (i == 1)
			rb--;
		tree.updMax(1, n, pref[i] );
		long long val = tree.getSum(i + 1, rb);
//		eprintf("i = %d, val = %lld\n", i, val);
		answer += val;
		int cur = a[i];
		for (int j = 1; j * j <= cur; j++)
		{
			if (cur % j != 0) continue;
			if (r[j] != -1)
				tree.updMax(1, r[j], j);
			int x = cur / j;
			if (r[x] != -1)
				tree.updMax(1, r[x], x);
		}
	}
	printf("%lld\n", answer);

	return 0;
}