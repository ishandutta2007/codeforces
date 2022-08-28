#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 100;
int a[maxn];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	sort(a, a + n);
	n = unique(a, a + n) - a;


	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		for (int j = 2; ; j++)
		{
			int p = lower_bound(a, a + n, x * j) - a;
			p--;

			ans = max(ans, a[p] % a[i] );
			if (p + 1 == n)
				break;
		}
	}

	
	printf("%d\n", ans);


	return 0;
}