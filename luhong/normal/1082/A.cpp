#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

int a[501000], n, x, y, d;
int Abs(int x) {return x > 0 ? x : -x;}
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &n, &x, &y, &d);
		if(Abs(x - y) % d == 0) printf("%d\n", Abs(x - y) / d);
		else
		{
			int ans = 2000000001;
			int len1 = x - 1, len2 = y - 1;
			if(len2 % d == 0) ans = std::min(ans, len1 / d + (len1 % d > 0) + len2 / d);
			len1 = n - x, len2 = n - y;
			if(len2 % d == 0) ans = std::min(ans, len1 / d + (len1 % d > 0) + len2 / d);
			if(ans == 2000000001) puts("-1");
			else printf("%d\n", ans);
		}
	}
	return 0;
}