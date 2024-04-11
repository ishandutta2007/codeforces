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


const int N = 25;
int a[N][N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j] );
			a[i][j]--;
		}

	for (int i = 0; i < m; i++)
		for (int j = i; j < m; j++)
		{
			for (int r = 0; r < n; r++)
				swap(a[r][i], a[r][j] );
			bool good = true;
			for (int r = 0; r < n; r++)
			{
				int cnt = 0;
				for (int c = 0; c < m; c++)
					if (a[r][c] != c)
						cnt++;
				if (cnt > 2)
					good = false;
			}
			if (good)
			{
				printf("YES\n");
				return 0;
			}
			for (int r = 0; r < n; r++)
				swap(a[r][i], a[r][j] );
		}

	printf("NO\n");
	return 0;
}