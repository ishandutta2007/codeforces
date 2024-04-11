#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,k;

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	if (n*m*2%k!=0)
	{
		printf("NO\n");
		return 0;
	}
	for (ll i=1;i*i<=2*n;i++)
	if (2*n%i==0)
	{
		if (i<=n && n*m*2/k%i==0)
		{
			ll tmp=n*m*2/k/i;
			if (tmp<=m)
			{
				printf("YES\n");
				printf("0 0\n");
				printf("0 %lld\n",tmp);
				printf("%lld 0\n",i);
				return 0;
			}
		}
		if (n/i<=n && n*m*2/k%(n/i)==0)
		{
			ll tmp=n*m*2/k/(n/i);
			if (tmp<=m)
			{
				printf("YES\n");
				printf("0 0\n");
				printf("0 %lld\n",tmp);
				printf("%lld 0\n",n/i);
				return 0;
			}
		}
	}
	swap(n,m);
	for (ll i=1;i*i<=2*n;i++)
	if (2*n%i==0)
	{
		if (i<=n && n*m*2/k%i==0)
		{
			ll tmp=n*m*2/k/i;
			if (tmp<=m)
			{
				printf("YES\n");
				printf("0 0\n");
				printf("%lld 0\n",tmp);
				printf("0 %lld\n",i);
				return 0;
			}
		}
		if (n/i<=n && n*m*2/k%(n/i)==0)
		{
			ll tmp=n*m*2/k/(n/i);
			if (tmp<=m)
			{
				printf("YES\n");
				printf("0 0\n");
				printf("%lld 0\n",tmp);
				printf("0 %lld\n",n/i);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}