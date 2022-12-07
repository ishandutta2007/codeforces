#include<bits/stdc++.h>

using namespace std;

#define LL long long int

LL a[100005];
bool b[100005];
LL tot,ans,n,m,i,j;

int main()
{
	scanf("%lld %lld",&n,&m);
	ans=tot=0;
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		tot+=a[i];
		if(i==1)continue;
		ans+=a[i-1]*a[i];
	}
	ans+=a[1]*a[n];
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&j);
		if(j==1)
		{
			if(!b[n])ans-=a[1]*a[n];
			if(!b[2])ans-=a[1]*a[2];
			tot-=a[1];
			ans+=tot*a[1];
			b[j]=true;
			continue;
		}
		if(j==n)
		{
			if(!b[1])ans-=a[1]*a[n];
			if(!b[n-1])ans-=a[n]*a[n-1];
			tot-=a[n];
			ans+=tot*a[n];
			b[j]=true;
			continue;
		}
		if(!b[j+1])ans-=a[j]*a[j+1];
		if(!b[j-1])ans-=a[j]*a[j-1];
		tot-=a[j];
		ans+=tot*a[j];
		b[j]=true;
	}
	printf("%lld",ans);
	return 0;
}