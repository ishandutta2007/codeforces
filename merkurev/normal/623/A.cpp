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


const int N = (int) 505;
char ans[N];
bool g[N][N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a][b] = g[b][a] = true;
	}

	int notB = -1;
	for (int i = 0; i < n; i++)
	{
		bool isB = true;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (!g[i][j] ) isB = false;
		}
		if (isB)
			ans[i] = 'b';
		else
			notB = i;
	}

	if (notB != -1)
	{
		for (int i = 0; i < n; i++)
			if (i != notB && !g[notB][i] )
				ans[i] = 'c';
			else if (ans[i] == 0)
				ans[i] = 'a';
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			bool A = ( (ans[i] == 'c' && ans[j] == 'a') || (ans[i] == 'a' && ans[j] == 'c') );
			if ((!A) != g[i][j] )
			{
				printf("No\n");
				return 0;
			}
		}
	printf("Yes\n%s\n", ans);

	return 0;
}