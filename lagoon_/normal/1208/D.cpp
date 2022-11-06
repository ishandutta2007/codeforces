#include<bits/stdc++.h>
using namespace std;
#define re register
long long s[200100],num[200100];
int n,p[200100];
void add(re int a,re int ad)
{
	for(;a<=n;a+=a&-a)num[a]+=ad;
}
long long sum(re int a)
{
	re long long x=0;
	for(;a;a-=a&-a)x+=num[a];
	return x;
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);add(i,i);
	}
	for(re int i=n;i;i--)
	{
		re int l=1,r=n,mid=(l+r)/2;
		for(;l<r;mid=(l+r+1)/2)
		{
			re long long x=sum(mid-1);
			if(x<=s[i])l=mid;
			else r=mid-1;
		}
		p[i]=l;
		add(l,-l);
	}
	for(re int i=1;i<=n;i++)printf("%d ",p[i]);
}