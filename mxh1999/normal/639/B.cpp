#include <bits/stdc++.h>
using namespace std;
int n, d, h;
int main()
{
	scanf("%d%d%d", &n, &d, &h);
	if ((d == 1 && n != 2) || d > h * 2) puts("-1");
	else if (d == h)
	{
		int r = 1;
		printf("%d %d\n", 1, ++r);
		for (int i = 1; i < h; i++) printf("%d %d\n", r, r + 1), r++;
		while (r < n) printf("%d %d\n", 2, ++r);
	}
	else
	{
		int r = 1;
		printf("%d %d\n", 1, ++r);
		for (int i = 1; i < h; i++) printf("%d %d\n", r, r + 1), r++;
		while (r < n)
		{
			printf("%d %d\n", 1, ++r);
			for (int i = 1; i < d - h && r < n; i++) printf("%d %d\n", r, r + 1), r++;
		}
	}
	return 0;
}