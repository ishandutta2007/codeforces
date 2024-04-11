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
int st[N];
int sz = 0;
int o2[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		a[i]--;
	}
	memset(st, -1, sizeof st);
	for (int i = 0; i < n; i++)
		if (i == a[i] )
		{
			o2[sz] = i;
			st[i] = sz++;
		}
	for (int i = 0; i < n; i++)
		if (st[a[i] ] == -1)
		{
			printf("-1\n");
			return 0;
		}
	printf("%d\n", sz);
	for (int i = 0; i < n; i++)
		printf("%d ", st[a[i] ] + 1);
	printf("\n");
	for (int i = 0; i < sz; i++)
		printf("%d ", o2[i] + 1);
	printf("\n");




	return 0;
}