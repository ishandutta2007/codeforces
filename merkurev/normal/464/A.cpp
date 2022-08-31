#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;


const int maxn = 1005;
char str[maxn];
char ans[maxn];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, p;
	scanf("%d%d", &n, &p);
	scanf("%s", str);

	for (int rem = n - 1; rem >= 0; rem--)
	{
		for (int i = 0; i < n; i++)
			ans[i] = str[i];
		bool onBound = true;
		bool good = true;
		for (int i = rem; i < n; i++)
		{
			char was = ans[i];
			char r1 = 0, r2 = 0;
			if (i > 0)
				r1 = ans[i - 1];
			if (i > 1)
				r2 = ans[i - 2];
			if (onBound)
			{
				onBound = false;
				was++;
			}
			else
				was = 'a';
			while (was == r1 || was == r2)
			{
				was++;
			}
			if (was >= 'a' + p)
			{
		//		fprintf(stderr, "ans = '%s', rem = %d, i = %d\n", ans, rem, i);
				good = false;
				break;
			}
			ans[i] = was;
		}
		if (!good)
			continue;
		printf("%s\n", ans);
		return 0;
	}
	printf("NO\n");

	return 0;
};