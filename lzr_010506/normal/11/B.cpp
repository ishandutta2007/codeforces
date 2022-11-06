#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 0) n = -n;
	int ans = 0, now = 0;
	while (now < n || (now - n) % 2 != 0)
	{
		ans ++;
		now += ans;
	}
	printf("%d", ans);
	return 0;
}