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




int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int even = n / 2;
	int odd = n - even;
	int black = (a * b) / 2;
	int white = a * b - black;
	
	if (white < odd || black < even)
	{
		printf("-1\n");
		return 0;
	}
	int curEven = 2;
	int curOdd = 1;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ( (i + j) % 2 )
			{
				if (curEven <= n)
				{
					printf("%d ", curEven);
					curEven += 2;
				}
				else
					printf("%d ", 0);
			}
			else
			{
				if (curOdd <= n)
				{
					printf("%d ", curOdd);
					curOdd += 2;
				}
				else
					printf("%d ", 0);
			}
		}
		printf("\n");
	}

	return 0;
}