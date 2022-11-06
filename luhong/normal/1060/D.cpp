#include <cstdio>
#include <cstring>
#include <algorithm>

int l[101000], r[101000];
using namespace std;
int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
	}
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += max(l[i], r[i]);
	}
	printf("%lld\n", ans + n);
	return 0;
}