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


const int X = 10000;
char dir[105];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	int pos = X;

	for (int i = 0; i < n; i++)
	{
		int d;
		scanf("%d%s", &d, dir);
		if (string(dir) == "North")
			pos += d;
		else if (string(dir) == "South")
			pos -= d;
		else
		{
			if (pos == X || pos == -X)
			{
				printf("NO\n");
				return 0;
			}
		}
		if (pos < -X || pos > X)
		{
			printf("NO\n");
			return 0;
		}
	}
	if (pos != X)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");


	return 0;
}