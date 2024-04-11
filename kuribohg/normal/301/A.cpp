#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1000],sum,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n+n;i++) scanf("%d",&a[i]),sum+=a[i];
	ans=sum;
	sort(a+1,a+n+n);
	if(n&1)
	{
		sum-=a[1],a[1]=-a[1],sum+=a[1],ans=max(ans,sum);
		for(int i=3;i<n+n;i+=2)
			sum-=a[i-1],a[i-1]=-a[i-1],sum+=a[i-1],ans=max(ans,sum),
			sum-=a[i],a[i]=-a[i],sum+=a[i],ans=max(ans,sum);
	}
	else
	{
		for(int i=2;i<n+n;i+=2)
			sum-=a[i-1],a[i-1]=-a[i-1],sum+=a[i-1],
			sum-=a[i],a[i]=-a[i],sum+=a[i],ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}