#include <cstdio>
#include <algorithm>

int n;
int a[150010];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	int w = 1, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != 1 && w < a[i] - 1) w = a[i] - 1;
		if(a[i] - 1 <= w && w <= a[i] + 1) ans++, w++;
	}
	printf("%d\n", ans);
}