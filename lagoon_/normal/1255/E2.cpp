#include<bits/stdc++.h>
#define re register
int a[1001000],b[1001000],n;
long long ans=1ll<<60;
void rnw(re long long i)
{
	re long long l1=1,nm=0;
	re long long anq=0;
	for(re int j=1;j<=n;j++)
	{
		b[j]=a[j]%i;
		if(nm+b[j]>=i)
		{
			re long long xx=b[j]-(i-nm);b[j]=i-nm;nm=0;
			for(re int i1=l1;i1<=j;i1++)
			{
				nm+=b[i1];
				if(nm>=(i+1)/2)
				{
					for(re int j1=l1;j1<=j;j1++)
					anq+=(long long)b[j1]*abs(j1-i1);
					break;
				}
			}
			b[j]=xx;
			l1=j+(!b[j]);
			nm=b[j];
		}
		else nm+=b[j];
	}
	ans=std::min(anq,ans);
}
int main()
{
	scanf("%d",&n);
	re long long num=0;
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]),num+=a[i];
	for(re int i=2;(long long)i*i<=num;i++)
	if(!(num%i)){
		for(num/=i;!(num%i);num/=i);
		rnw(i);
	}if(num!=1)rnw(num);
	if(ans<(1ll<<60))printf("%lld\n",ans);
	else puts("-1");
}