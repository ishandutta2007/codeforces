#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t = 1;
	while(t--)
	{
		long long n, s;
		scanf("%lld%lld",&n,&s);
		long long l = 1LL;
		long long r = n;
		long long ans = n + 1LL;
		while(l <= r)
		{
			long long mid = (l + r) / 2LL;
			long long sum = mid;
			long long sum1 = mid;
			while(sum > 0)
			{
				sum1 -= sum % 10LL;
				sum /= 10LL;
			}
			if(sum1 >= s)
			{
				r = mid - 1LL;
				ans = mid;
			}
			else l = mid + 1LL;
		}
		printf("%lld\n",n - ans + 1LL);
	}
	return 0;
}