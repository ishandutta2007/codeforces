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


const int N = (int) 1e5 + 100;
int a[N];
int b[N];
int toL[N], toR[N];
int st[N];
int sz = 0;


long long solve(int l, int r)
{
	for (int i = l; i < r; i++)
	{
		b[i - l] = abs(a[i + 1] - a[i] );
	}
	int n = r - l;
	for (int i = 0; i < n; i++)
	{
		while (sz > 0 && b[i] >= b[st[sz - 1] ] )
			sz--;
		toL[i] = (sz == 0 ? -1 : st[sz - 1]);
		st[sz++] = i;
	}
	sz = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		while (sz > 0 && b[i] > b[st[sz - 1] ] )
			sz--;
		toR[i] = (sz == 0 ? n : st[sz - 1]);
		st[sz++] = i;
	}
	sz = 0;

	/*
	for (int i = 0; i < n; i++)
		eprintf("%d ", b[i] );
	eprintf("\n");
	for (int i = 0; i < n; i++)
		eprintf("%d ", toL[i] );
	eprintf("\n");
	for (int i = 0; i < n; i++)
		eprintf("%d ", toR[i] );
	eprintf("\n");
	eprintf("\n");
	*/
	
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += b[i] * 1LL * (toR[i] - i) * 1LL * (i - toL[i] );
	}
	return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );

	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		long long ans = solve(l, r);
		printf("%lld\n", ans);
	}




	return 0;
}