#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		ll ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			ans += x;
		}
		printf("%lld\n",abs(ans));
	}
	return 0;
}