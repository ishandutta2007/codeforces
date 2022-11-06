#include<bits/stdc++.h>
#define re register
int a[200100],n;
long long b[200100],nnm;
long long check(re long long k)
{
	re long long num=0;
	for(re int i=1;i<=n;i++)
	if(k<=a[i]-1){
		b[i]=(long long)((-1.0+sqrt(1-(4.0*(1+k-a[i]))/3.0))/2.0-0.5);
		if(b[i]>a[i])b[i]=a[i];
		if(b[i]<0)b[i]=0;
		for(;b[i]<a[i]&&-3*b[i]*b[i]-3*b[i]-1+a[i]>=k;b[i]++);
		num+=b[i];
	}else b[i]=0;
	return num;
}
int main()
{
	re long long k;
	scanf("%d%lld",&n,&k);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	re long long l=-3.1e18,r=1e9,mid=(l+r)/2;
	for(mid=(l+r)/2;l<r-1;mid=(l+r)/2)
	{
		if(check(mid)<=k)r=mid;
		else l=mid+1;
	}
	if(check(l)>k)l=r;
	k-=check(l);
	for(re int i=1;i<=n;i++)
	{
		for(;k&&b[i]<a[i]&&-3*b[i]*b[i]-3*b[i]-1+a[i]==l-1;b[i]++)k--;
		printf("%lld ",b[i]);
	}
}