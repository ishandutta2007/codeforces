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


int sz = 0;
const int maxn = (int) 1e5 + 100;
int all[maxn * 2];
int a[maxn];
int b[maxn];
bool has[2 * maxn];
int nxt[2 * maxn];
int prt[2 * maxn];

int len2min[2 * maxn];
int len2minF[2 * maxn];
int len2minR[2 * maxn];

const int inf = (int) 1e9;
void solveF(int l, int r, int bef)
{
	int len = r - l;
	for (int i = 0; i <= len; i++)
		len2min[i] = inf;
	len2min[0] = bef;
	
	for (int i = l; i < r; i++)
	{
//		eprintf("%d %d %d\n", l, i, r);
		int cur = a[i];
		if (a[i] != -1)
		{
			if (cur > bef)
			{
//			eprintf("a[i] = %d\n", a[i] );
			int pos = lower_bound(len2min, len2min + len, a[i] ) - len2min;
//			eprintf("pos = %d\n", pos);
			len2min[pos] = cur; 
			}
		}
		else
		{
			for (int j = len - 1; j >= 0; j--)
			{
				if (len2min[j] >= sz)
					continue;
				int nx = nxt[len2min[j] + 1];
				if (nx < len2min[j + 1] )
					len2min[j + 1] = nx;
			}
		}
	}
}

void solveR(int l, int r, int aft)
{
	int len = r - l;
	for (int i = 0; i <= len; i++)
		len2min[i] = -1;
	len2min[len] = aft;
	
	for (int i = r - 1; i >= l; i--)
	{
		int cur = a[i];
		if (a[i] != -1)
		{
			if (cur < aft)
			{
				int pos = upper_bound(len2min, len2min + len, a[i] ) - len2min - 1;
				len2min[pos] = cur; 
			}
		}
		else
		{
			for (int j = 1; j <= len; j++)
			{
				if (len2min[j] - 1 <= 0)
					continue;
				int pr = prt[len2min[j] - 1];
				if (pr > len2min[j - 1] )
					len2min[j - 1] = pr;
			}
		}
	}
	reverse(len2min, len2min + len + 1);
}

int tk = 0;
int taked[maxn];

void solve(int l, int r, int bef, int aft)
{
	eprintf("l = %d, r = %d, bef = %d, aft = %d\n", l, r, bef, aft);
	if (r - l == 1)
	{
		if (a[l] == -1)
		{
			int x = nxt[bef + 1];
			if (x < aft)
			{
				taked[tk++] = x;
				a[l] = x;
			}
		}
		return; 
	}
	int mid = (l + r) / 2;
	solveF(l, mid, bef);
	for (int i = 0; i <= mid - l; i++)
		len2minF[i] = len2min[i];

	solveR(mid, r, aft);
	for (int i = 0; i <= r - mid; i++)
		len2minR[i] = len2min[i];
	
	eprintf("mid = %d\n", mid);
	for (int i = 0; i <= mid - l; i++)
		eprintf("%d ", len2minF[i] );
	eprintf("\n");
	for (int i = 0; i <= r - mid; i++)
		eprintf("%d ", len2minR[i] );
	eprintf("\n");
	
	int bst = -1;
	int dv = -1;
	int j = r - mid;
	for (int i = 0; i <= mid - l; i++)
	{
		while (j >= 0 && len2minR[j] <= len2minF[i] )
			j--;
		if (j < 0)
			break;
		if (i + j > bst)
		{
			bst = i + j;
			dv = len2minF[i];
		}
	}
	solve(l, mid, bef, dv + 1);
	solve(mid, r, dv, aft);
}


void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		if (a[i] != -1)
			all[sz++] = a[i];
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i] );
		all[sz++] = b[i];
	}
	sort(b, b + m);
	all[sz++] = -2;
	sort(all, all + sz);
	sz = unique(all, all + sz) - all;
	for (int i = 0; i < n; i++)
		if (a[i] != -1)
			a[i] = lower_bound(all, all + sz, a[i] ) - all;
	for (int i = 0; i < m; i++)
	{
		b[i] = lower_bound(all, all + sz, b[i] ) - all;
		has[b[i] ] = true;
	}
	nxt[sz] = inf;
	for (int i = sz - 1; i >= 0; i--)
	{
		if (has[i] )
			nxt[i] = i;
		else
			nxt[i] = nxt[i + 1];
	}
	prt[0] = -1;
	for (int i = 1; i <= sz; i++)
	{
		if (has[i] )
			prt[i] = i;
		else
			prt[i] = prt[i - 1];
	}

	for (int i = 0; i < n; i++)
		eprintf("%d ", a[i] );
	eprintf("\n");
	for (int i = 0; i < m; i++)
		eprintf("%d ", b[i] );
	eprintf("\n");
	for (int i = 0; i <= sz; i++)
		eprintf("%d ", nxt[i] );
	eprintf("\n");
	for (int i = 0; i <= sz; i++)
		eprintf("%d ", prt[i] );
	eprintf("\n");

	solve(0, n, 0, sz);
	sort(taked, taked + tk);
	int post = 0, posb = 0;

	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		if (a[i] == -1)
		{
			eprintf("!!\n");
			while (post < tk && taked[post] == b[posb] )
			{
				post++;
				posb++;
			}
//			eprintf("post = %d, posb = %d\n", post, posb);
			a[i] = b[posb++];
//			eprintf("a[i] = %d\n", a[i] );
		}
		x = a[i];
		x = all[x];
		printf("%d ", x);
	}
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	solve();

	return 0;
}