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


const int maxn = 105;
char f[maxn][maxn];
long long s[maxn][maxn];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", f[i] );

	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
		{
			long long need = (f[i][j] == 'W' ? 1 : -1);
			need -= s[i][j];
			if (need == 0)
				continue;

			ans++;
			for (int ii = 0; ii <= i; ii++)
				for (int jj = 0; jj <= j; jj++)
					s[ii][jj] += need;
		}

	printf("%d\n", ans);


	return 0;
}