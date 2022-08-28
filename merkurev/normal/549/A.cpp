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


const int maxn = 55;
char f[maxn][maxn];
int cnt[305];


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
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
		{
			memset(cnt, 0, sizeof cnt);
			cnt[(int)f[i][j] ]++;
			cnt[(int)f[i][j + 1] ]++;
			cnt[(int)f[i + 1][j] ]++;
			cnt[(int)f[i + 1][j + 1] ]++;
			if (cnt[(int)'f'] && cnt[(int)'a'] && cnt[(int)'c'] && cnt[(int)'e'] )
				ans++;
		}
	printf("%d\n", ans);




	return 0;
}