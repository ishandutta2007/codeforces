#include <bits/stdc++.h>
using namespace std;
int n, a[500010];
int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
		scanf("%d",&a[i]);
	sort(a, a + n);
	int l = n / 2;
	int r = n - 1;
	int ans;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(a[mid] >= 2 * a[0]) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	int k = 0;
	int count = 0;
	for(int i = ans; i < n; i ++)
	{
		if(k == ans) break;
		if(a[i] >= 2 * a[k])
		{
			count ++;
			k ++;
		}
	}
	printf("%d\n", n - count);
	return 0;
}