#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n,p;
LL a[N];
LL add (LL x){return (x%p+p)%p;}
int main()
{
	scanf("%I64d%I64d",&n,&p);
	for (LL u=1;u<=n;u++)
	{
		scanf("%I64d",&a[u]);
		a[u]=add(a[u-1]+a[u]);
	}
	LL ans=0;
	for (LL u=1;u<n;u++)
		ans=max(ans,a[u]+add(a[n]-a[u]));
	printf("%I64d\n",ans);
	return 0;
}