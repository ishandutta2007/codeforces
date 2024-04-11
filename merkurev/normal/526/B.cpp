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


const int maxn = 10500;
long long a[maxn];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	int N = (1 << (n + 1) );
	for (int i = 2; i < N; i++)
		scanf("%lld", &a[i] );

	long long ans = 0;
	for (int i = N / 2; i >= 1; i--)
	{
		long long x = a[2 * i];
		long long y = a[2 * i + 1];
		ans += llabs(x - y);
		a[i] += max(x, y);
	}
	printf("%lld\n", ans);

	return 0;
}