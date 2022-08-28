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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int maxn = (int) 1e6 + 100;
int a[maxn];
int aa[maxn];
int lb[maxn];
int rb[maxn];
int as;

int fn[maxn];
void fn_clear()
{
	memset(fn, -1, sizeof fn);
}
void fn_set(int pos, int val)
{
	pos++;
	for (; pos < maxn; pos = (pos | (pos - 1) ) + 1)
	{
		fn[pos] = max(fn[pos], val);
	}
}
int fn_max(int pos)
{
	pos++;
	int ans = -1;
	for (; pos > 0; pos = (pos & (pos - 1) ) )
	{
		ans = max(ans, fn[pos] );
	}
	return ans;
}

long long addE[maxn];
long long addI[maxn];

long long ans[maxn];

#ifdef LOCAL
long long alt[maxn];
#endif

void addInc(int l, int r, int k)
{
	if (l > r)
		return;
#ifdef LOCAL
	long long cur = k;
	for (int i = l; i <= r; i++)
	{
		alt[i] += cur;
		cur += k;
	}
#endif
	addI[l] += k;
	addI[r + 1] -= k;
	addE[r + 1] -= k * 1LL * (r - l + 1);

}
void addEq(int l, int r, long long k)
{
#ifdef LOCAL
	for (int i = l; i <= r; i++)
		alt[i] += k;
#endif
	addE[l] += k;
	addE[r + 1] -= k;
}
void addDec(int l, int r, int k)
{
	if (l > r)
		return;
#ifdef LOCAL
	long long cur = k;
	for (int i = r; i >= l; i--)
	{
		alt[i] += cur;
		cur += k;
	}
#endif
	addI[l] -= k;
	addI[r + 1] += k;
	addE[l] += k * 1LL * (r - l + 2);
	addE[r + 1] -= k;
}

void calc()
{
	for (int i = 0; i < maxn - 1; i++)
	{
		addE[i] += addI[i];
		ans[i] = addE[i];
		addE[i + 1] += addE[i];
		addI[i + 1] += addI[i];
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		aa[i] = a[i];
	}
	fn_clear();
	sort(aa, aa + n);
	as = unique(aa, aa + n) - aa;
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(aa, aa + as, a[i] ) - aa;
	for (int i = 0; i < n; i++)
	{
		lb[i] = fn_max(a[i] - 1);
		fn_set(a[i], i);
	}
	fn_clear();
	for (int i = n - 1; i >= 0; i--)
	{
		rb[i] = n - 1 - fn_max(a[i] );
		fn_set(a[i], n - i - 1);
	}
	for (int i = 0; i < n; i++)
	{
//		eprintf("%d %d\n", lb[i] , rb[i]);
		int l = i - lb[i] - 1;
		int r = rb[i] - i - 1;
//		eprintf("%d %d\n\n", l, r);
		if (l > r)
			swap(l, r);
		addInc(1, l, aa[a[i] ] );
		addEq(l + 1, r + 1, aa[a[i] ] * 1LL * (l + 1) );
		addDec(r + 2, l + r + 1, aa[a[i] ] );
	}
	calc();
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
#ifdef LOCAL
	//	printf("%lld ? ", alt[x] );
#endif
	//	printf("%lld\n", ans[x] );
		printf("%.10lf\n", (double) ans[x] / (double) (n - x + 1) );
	}

	return 0;
}