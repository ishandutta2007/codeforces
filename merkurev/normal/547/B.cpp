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



const int maxn = (int) 2e5 + 100;
int a[maxn];
int va[maxn];


int fn[maxn];

void setVal(int pos, int val)
{
	pos++;
	for (; pos < maxn; pos = (pos | (pos - 1) ) + 1)
		fn[pos] = max(fn[pos], val);
}

int getMaxLs(int pos)
{
	int ans = -1;
	for (; pos > 0; pos = (pos & (pos - 1) ) )
		ans = max(ans, fn[pos] );
	return ans;
}

int ans[maxn];
int lb[maxn], rb[maxn];


int main(int, char **)
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		va[i] = a[i];
	}
	sort(va, va + n);
	int nv = unique(va, va + n) - va;
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(va, va + nv, a[i] ) - va;

	memset(fn, -1, sizeof fn);
	for (int i = 0; i < n; i++)
	{
		lb[i] = getMaxLs(a[i] );
		setVal(a[i], i);
	}
	memset(fn, -1, sizeof fn);
	for (int i = n - 1; i >= 0; i--)
	{
		rb[i] = n - 1 - getMaxLs(a[i] );
		setVal(a[i], n - i - 1);
	}
	for (int i = 0; i < n; i++)
	{
		ans[rb[i] - lb[i] - 1] = max(ans[rb[i] - lb[i] - 1], a[i] );
	}
	for (int i = n - 1; i > 0; i--)
	{
		ans[i] = max(ans[i], ans[i + 1] );
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", va[ans[i] ] );

	return 0;
}