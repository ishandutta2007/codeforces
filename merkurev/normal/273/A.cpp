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
int a[maxn];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	int m;
	scanf("%d", &m);

	int pos = 0;
	long long boxUp = 0;
	for (int i = 0; i < m; i++)
	{
		int w, h;
		scanf("%d%d", &w, &h);
		while (pos < w)
		{
			boxUp = max(boxUp, (long long) a[pos++] );
		}
		printf("%lld\n", boxUp);
		boxUp += h;
	}
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}