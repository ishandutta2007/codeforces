#include <cstdio>
#include <algorithm>

using namespace std;
int a[1010000];
bool used[1010000];
int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), used[a[i]] = 1;
	int ans = 0;
	for(int i = 1, j = 1000000; i < j; i++, j--)
	{
		if(used[i] || used[j]) ans = i - 1;
	}
	printf("%d\n", ans);
	return 0;
}