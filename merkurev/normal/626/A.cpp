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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int getId(char c)
{
	if (c == 'D')
		return 0;
	if (c == 'U')
		return 1;
	if (c == 'L')
		return 2;
	if (c == 'R')
		return 3;
	throw;
}

const int N = 205;
char str[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	scanf("%s", str);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		for (int j = i; j < n; j++)
		{
			x += dx[getId(str[j] ) ];
			y += dy[getId(str[j] ) ];
			if (x == 0 && y == 0)
				ans++;
		}
	}
	printf("%d\n", ans);


	return 0;
}