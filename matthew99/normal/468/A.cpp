#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	if (n < 4) printf("NO\n");
	else
	{
		printf("YES\n");
		int cur = n;
		int cnt = n - 1;
		while (cur - 2 >= 4)
		{
			printf("%d - %d = 1\n", cur, cur - 1);
			--cnt;
			cur -= 2;
		}
		if (n & 1)
		{
			printf("2 - 1 = 1\n");
			printf("3 + 1 = 4\n");
			printf("4 * 5 = 20\n");
			printf("4 + 20 = 24\n");
			cnt -= 4;
		}
		else
		{
			printf("1 * 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
			cnt -= 3;
		}
		while (cnt) --cnt, printf("24 * 1 = 24\n");
	}
	return 0;
}