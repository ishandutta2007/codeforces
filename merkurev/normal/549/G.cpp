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


const int maxn = 200500;
int a[maxn];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		a[i] += i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		a[i] -= i;
	bool bad = false;
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1] )
			bad = true;
	if (bad)
	{
		printf(":(");
		return 0;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i] );


	return 0;
}