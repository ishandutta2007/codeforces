#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,a[111111];
long long sum,xr,fuck,z;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sum=0;xr=0;
		for (int i=1;i<=n;i++)
		{
			sum+=a[i];
			xr^=a[i];
		}
		printf("2\n%lld %lld\n",xr,sum+xr);
	}
	return Accepted;
}