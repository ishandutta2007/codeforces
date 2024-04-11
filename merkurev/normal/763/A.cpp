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
int e[N][2];
int c[N];
int cnt[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		e[i][0] = a;
		e[i][1] = b;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i] );
	int cntAll = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int a = e[i][0];
		int b = e[i][1];
		if (c[a] != c[b] )
		{
			cntAll++;
			cnt[a]++;
			cnt[b]++;
		}
	}
	for (int i = 0; i < n; i++)
		if (cnt[i] == cntAll)
		{
			printf("YES\n%d\n", i + 1);
			return 0;
		}
	printf("NO\n");


	return 0;
}