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


const int maxn = (int) 1e5 + 100;
int h[maxn];
int l[maxn], r[maxn];


void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i] );

	int d = 0;
	for (int i = 0; i < n; i++)
	{
		d++;
		d = min(d, h[i] );
		l[i] = d;
	}
	d = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		d++;
		d = min(d, h[i] );
		r[i] = d;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, min(l[i], r[i] ) );

	printf("%d\n", ans);
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