#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

int my_round(double a)
{
	if (a >= 0)
		return (int)(a + 0.5);
	return (int)(a - 0.5);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int a, b;
	scanf("%d%d", &a, &b);

	for (int dx1 = -a; dx1 <= a; dx1++)
	{
		for (int dy1 = -a; dy1 <= a; dy1++)
		{
			if (dx1 * dx1 + dy1 * dy1 != a * a)
				continue;
			
			int dx2 = -dy1;
			int dy2 = dx1;
			
			double len = sqrt((double)dx2 * dx2 + dy2 * dy2);
			dx2 = my_round(dx2 / len * b);
			dy2 = my_round(dy2 / len * b);

			if (dx2 * dx2 + dy2 * dy2 != b * b)
				continue;

			int dx3 = dx2 - dx1;
			int dy3 = dy2 - dy1;

			if (dx1 == 0 || dx2 == 0 || dx3 == 0 ||
					dy1 == 0 || dy2 == 0 || dy3 == 0)
				continue;

			printf("YES\n");
			printf("0 0\n%d %d\n%d %d\n", dx1, dy1, dx2, dy2);
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}