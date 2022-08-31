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

const int maxn = (int) 5e5 + 100;
int a[maxn];
int st[maxn];
int sz;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		while (sz >= 2 && st[sz - 1] <= x && st[sz - 1] <= st[sz - 2] )
		{
			ans += min(st[sz - 2], x);
			sz--;
		}
		st[sz++] = x;
	}
	int pos = max_element(st, st + sz) - st;

	int pl, pr;
	if (pos == sz - 1 || (pos != 0 && st[pos - 1] > st[pos + 1] ) )
	{
		pl = pos - 1;
		pr = pos;
	}
	else
	{
		pl = pos;
		pr = pos + 1;
	}
	while (pl != 0 || pr != sz - 1)
	{
		if (pl == 0 || (pr != sz - 1 && min(st[pl - 1], st[pr] ) < min(st[pl], st[pr + 1] ) ) )
		{
			ans += min(st[pl], st[pr + 1] );
			pr++;
		}
		else
		{
			ans += min(st[pl - 1], st[pr] );
			pl--;
		}
	}
	printf("%lld\n", ans);

	return 0;
}