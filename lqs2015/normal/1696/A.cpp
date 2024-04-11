#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int a[2222], n, z, ans, test;
int main()
{
    scanf("%d", &test);
    while(test--)
    {
		scanf("%d%d", &n, &z);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, (a[i] | z));
		}
		printf("%d\n", ans);
    }
	return Accepted;
}