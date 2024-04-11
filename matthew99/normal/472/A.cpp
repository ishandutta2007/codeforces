#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for ( ; ; )
	{
		int x = rand() % (n - 3) + 2, y = n - x;
		bool a = 0, b = 0;
		for (int i = 2; i * i <= x; ++i)
			if (!(x % i)) { a = 1; break; }
		if (!a) continue;
		for (int i = 2; i * i <= y; ++i)
			if (!(y % i)) { b = 1; break; }
		if (!b) continue;
		printf("%d %d\n", x, y);
		break;
	}
	return 0;
}